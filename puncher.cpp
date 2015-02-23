#include "puncher.h"
#include "ui_puncher.h"
#include <QTimer>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QDate>

QSqlQuery qry_p;

Puncher::Puncher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Puncher)
{
    timer = new QTimer(this);

    ui->setupUi(this);

    init();

    connect(timer, SIGNAL(timeout()), this, SLOT(timer_callback()));
    connect(ctrl, SIGNAL(clicked()), this, SLOT(ctrl_callback()));
    connect(reset, SIGNAL(clicked()), this, SLOT(reset_callback()));

}

void Puncher::init()
{
    seconds = minutes = hours = 0;

    lcd = ui->lcdNumber;
    lcd_secs = ui->lcdNumber_secs;
    ctrl = ui->ctrlButton;
    reset = ui->resetButton;

    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display("00");

    lcd_secs->setSegmentStyle(QLCDNumber::Flat);
    lcd_secs->display("00:00");

    ctrl->setText("Start");
}

Puncher::~Puncher()
{
    delete ui;
}

void Puncher::reset_callback()
{
    QMessageBox msgBox;

    if (timer->isActive()) {
        msgBox.setText("Do you want to Reset?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();

        if (ret == QMessageBox::Yes) {
            seconds = 0;
            minutes = 0;
            hours = 0;
            update_displays();
        }
    }
}

void Puncher::ctrl_callback()
{
   if (timer->isActive()) {
        timer->stop();

        QDate *date = new QDate();
        *date = date->currentDate();

        day = date->day();
        month = date->month();
        year = date->year();

        insert_into_db(day, month, year, hours, minutes, seconds);
        ctrl->setText("Start");
    } else {
        timer->start(1000);
        ctrl->setText("Stop");
    }
}

void Puncher::timer_callback()
{
    seconds++;
    if (seconds == 60) {
        minutes++;
        seconds = 0;
    }
    if (minutes == 60) {
        hours++;
        minutes = 0;
    }

    update_displays();
}

void Puncher::update_displays()
{
    char display_str[6];
    char aux[2];

    if (hours < 10) {
        strcpy(display_str, "0");
        snprintf(aux, 2, "%d", hours);
        strcat(display_str, aux);
    } else {
        snprintf(aux, 3, "%d", hours);
        strcat(display_str, aux);
    }

    lcd->display(display_str);

    if (minutes < 10) {
        strcpy(display_str, "0");
        snprintf(aux, 2, "%d", minutes);
        strcat(display_str, aux);
    } else {
        snprintf(aux, 3, "%d", minutes);
        strcat(display_str, aux);
    }

    strcat(display_str, ":");

    if (seconds < 10) {
        strcat(display_str, "0");
        snprintf(aux, 2, "%d", seconds);
        strcat(display_str, aux);
    } else {
        snprintf(aux, 3, "%d", seconds);
        strcat(display_str, aux);
    }

    lcd_secs->display(display_str);
}

void Puncher::insert_into_db(int l_day, int l_month, int l_year, int l_hours, int l_minutes, int l_seconds)
{
    QSqlQuery qry;

    qry.prepare( "CREATE TABLE IF NOT EXISTS puncher_db (id INTEGER UNIQUE PRIMARY KEY, day VARCHAR(30), month VARCHAR(30), year VARCHAR(30), hours VARCHAR(30), minutes VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table created!";

    QString query = "UPDATE puncher_db SET hours='" +
                  QString::number( l_hours )   + "', minutes='" +
                  QString::number( l_minutes ) + "', seconds='" +
                  QString::number( l_seconds ) + "' WHERE day='" +
                  QString::number( l_day )     + "' AND month='" +
                  QString::number( l_month )   + "' AND year='" +
                  QString::number( l_year )    + "'";

    qry.prepare( query );
    if( !qry.exec() )
    {
        query = "INSERT INTO puncher_db (day, month, year, hours, minutes, seconds) VALUES (" +
                      QString::number( l_day )     + ", " +
                      QString::number( l_month )   + ", " +
                      QString::number( l_year )    + ", " +
                      QString::number( l_hours )   + ", " +
                      QString::number( l_minutes ) + ", " +
                      QString::number( l_seconds ) + ")";

        qry.prepare( query );
        if( !qry.exec() )
          qDebug() << qry_p.lastError();
        else
          qDebug( "Inserted!" );
    }
    else
        qDebug() << "Updated!";
}

