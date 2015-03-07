#include "data.h"
#include "data_raw.h"
#include "puncher.h"
#include "ui_data.h"
#include <QSqlQuery>
#include <QMessageBox>

Data::Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);

    calendar = ui->calendarWidget;

    data_title = ui->data_title;
    data_hours = ui->data_hours;
    data_minutes = ui->data_minutes;
    data_seconds = ui->data_seconds;

    data_input_hours = ui->data_input_hours;
    data_input_minutes = ui->data_input_minutes;
    data_input_seconds = ui->data_input_seconds;

    data_title->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    data_hours->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    data_minutes->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    data_seconds->setAlignment(Qt::AlignRight | Qt::AlignCenter);

    /* when window opens, update according to current day selection */
    QDate *date = new QDate();
    *date = date->currentDate();

    sel_day = date->day();
    sel_month = date->month();
    sel_year = date->year();

    on_calendarWidget_selectionChanged();
}

Data::~Data()
{
    delete ui;
}

void Data::on_data_load_clicked()
{

}

void Data::on_data_raw_clicked()
{
    Data_raw raw;
    raw.setModal(true);
    raw.exec();
}

void Data::on_data_cancel_clicked()
{
    this->close();
}

void Data::on_calendarWidget_selectionChanged()
{
    qDebug() << ":: on_calendarWidget_selectionChanged ::";

    int work_hours, work_minutes;

    QDate *selected_date = new QDate();
    *selected_date = calendar->selectedDate();

    sel_day = selected_date->day();
    sel_month = selected_date->month();
    sel_year = selected_date->year();

    fill_date(&work_hours, &work_minutes);

    data_title->setText(selected_date->toString());
}

void Data::fill_date(int *work_hours, int *work_minutes)
{
    qDebug() << ":: fill_date ::";
    QSqlQuery qry;

    QString qry_str = "SELECT hours, minutes, seconds FROM puncher_db WHERE day='" +
            QString::number( sel_day )     + "' AND month='" +
            QString::number( sel_month )   + "' AND year='" +
            QString::number( sel_year )    + "'";

    qry.prepare( qry_str );
    if (!qry.exec()) {
        qDebug() << qry.lastError();
    } else {
        QSqlRecord rec = qry.record();
        qry.next();

        sel_hours = qry.value(0).toInt();
        sel_minutes = qry.value(1).toInt();
        sel_seconds = qry.value(2).toInt();

        data_input_hours->setValue(sel_hours);
        data_input_minutes->setValue(sel_minutes);
        data_input_seconds->setValue(sel_seconds);
    }
}

void Data::on_data_update_clicked()
{
    QMessageBox msgBox;
    QSqlQuery qry;
    int rows = 0;

    sel_hours = data_input_hours->value();
    sel_minutes = data_input_minutes->value();
    sel_seconds = data_input_seconds->value();

    msgBox.setText("Are you sure you want to Update?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        QString qry_str = "SELECT * FROM puncher_db WHERE day='" +
                QString::number( sel_day )     + "' AND month='" +
                QString::number( sel_month )   + "' AND year='" +
                QString::number( sel_year )    + "'";

        qry.prepare(qry_str);

        if (!qry.exec()) {
            qDebug() << qry.lastError();
        } else {
            QSqlRecord rec = qry.record();

            int cols = rec.count();
            for( rows=0; qry.next(); rows++ );
        }

        if (rows) {
            QString qry_str = "UPDATE puncher_db SET hours='" +
                    QString::number( sel_hours )   + "', minutes='" +
                    QString::number( sel_minutes ) + "', seconds='" +
                    QString::number( sel_seconds ) + "' WHERE day='" +
                    QString::number( sel_day )     + "' AND month='" +
                    QString::number( sel_month )   + "' AND year='" +
                    QString::number( sel_year )    + "'";

            qry.prepare(qry_str);
            if (!qry.exec())
                qDebug() << qry.lastError();
            else
                qDebug() << "Updated row!";
        } else {
            qry_str = "INSERT INTO puncher_db (day, month, year, hours, minutes, seconds) VALUES (" +
                    QString::number( sel_day )     + ", " +
                    QString::number( sel_month )   + ", " +
                    QString::number( sel_year )    + ", " +
                    QString::number( sel_hours )   + ", " +
                    QString::number( sel_minutes ) + ", " +
                    QString::number( sel_seconds ) + ")";

            qry.prepare(qry_str);
            if (!qry.exec())
                qDebug() << qry.lastError();
            else
                qDebug() << "Inserted new row!";
        }

        /* sending signal to puncher object */
        emit(set_hours(sel_hours,
                       sel_minutes,
                       sel_seconds));
    }
}
