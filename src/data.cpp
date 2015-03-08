#include "data.h"

Data::Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);

    /* getting the ui elements into variables */
    calendar = ui->calendarWidget;
    data_title = ui->data_title;
    data_hours = ui->data_hours;
    data_minutes = ui->data_minutes;
    data_seconds = ui->data_seconds;
    data_input_hours = ui->data_input_hours;
    data_input_minutes = ui->data_input_minutes;
    data_input_seconds = ui->data_input_seconds;

    /* aligning labels */
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

/* CALLBACKS ******************************************************************************************/

void Data::on_data_raw_clicked()
{
    Data_raw *raw = new Data_raw();
    raw->setModal(true);
    raw->exec();
}

void Data::on_data_cancel_clicked()
{
    this->close();
}

void Data::on_calendarWidget_selectionChanged()
{
    qDebug() << ":: on_calendarWidget_selectionChanged ::";

    /* getting selected date */
    QDate *selected_date = new QDate();
    *selected_date = calendar->selectedDate();

    sel_day = selected_date->day();
    sel_month = selected_date->month();
    sel_year = selected_date->year();

    /* filling the date into the db and UI */
    if (status_ok != fill_date())
        qDebug() << "*** ERROR: fill_date ***";

    /* updating title accordingly to selected date */
    data_title->setText(selected_date->toString());
}

void Data::on_data_update_clicked()
{
    QMessageBox msgBox;

    sel_hours = data_input_hours->value();
    sel_minutes = data_input_minutes->value();
    sel_seconds = data_input_seconds->value();

    msgBox.setText("Are you sure you want to Update?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        if (status_ok != db->insert(sel_day, sel_month, sel_year, sel_hours, sel_minutes, sel_seconds))
            qDebug() << "*** ERROR: db->insert ***";
        else /* sending signal to update puncher object */
            emit(set_hours(sel_hours, sel_minutes, sel_seconds));
    }
}

/* AUX FUNCTIONS ******************************************************************************************/

status Data::fill_date()
{
    qDebug() << ":: fill_date ::";

    if (status_ok != db->query(sel_day, sel_month, sel_year,
                               &sel_hours, &sel_minutes, &sel_seconds)) {
        qDebug() << "*** ERROR: db->query ***";
        return err_db;
    } else {
        data_input_hours->setValue(sel_hours);
        data_input_minutes->setValue(sel_minutes);
        data_input_seconds->setValue(sel_seconds);
    }
    return status_ok;
}
