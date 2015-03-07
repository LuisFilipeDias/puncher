#include "puncher.h"

Puncher::Puncher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Puncher)
{
    timer = new QTimer(this);

    ui->setupUi(this);

    /* initialization operations */
    init();

    /* connect timer to signal timeout (1s) */
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_callback()));

    /* manually tying the buttons/options to the callbacks */
    connect(ctrl, SIGNAL(clicked()), this, SLOT(ctrl_callback()));
    connect(reset, SIGNAL(clicked()), this, SLOT(reset_callback()));
    connect(edit, SIGNAL(clicked()), this, SLOT(edit_callback()));
    connect(check_logs, SIGNAL(triggered()), this, SLOT(check_logs_callback()));
    connect(check_raw, SIGNAL(triggered()), this, SLOT(check_raw_callback()));
    connect(close, SIGNAL(triggered()), this, SLOT(close_callback()));
}

Puncher::~Puncher()
{
    delete ui;
}

status Puncher::init()
{
    /* resetting the time for the day */
    seconds = minutes = hours = 0;

    /* getting the ui elements into variables */
    lcd = ui->lcdNumber;
    lcd_secs = ui->lcdNumber_secs;
    ctrl = ui->ctrlButton;
    reset = ui->resetButton;
    edit = ui->editButton;
    check_logs = ui->actionCheck_Logs;
    check_raw = ui->actionCheck_Raw;
    close = ui->actionClose;

    /* displaying 00:00:00 as startup value */
    lcd->display("00");
    lcd_secs->display("00:00");

    /* get current date and fill db info if any */
    QDate *date = new QDate();
    *date = date->currentDate();

    day = date->day();
    month = date->month();
    year = date->year();

    if (status_ok != db->query(day, month, year, &hours, &minutes, &seconds)) {
        qDebug() << "*** ERROR: db->query ***";
        return err_db;
    } else {
        if (status_ok != update_displays()) {
            qDebug() << "*** ERROR: update_displays ***";
            return err_db;
        }
    }

    return status_ok;
}

/* CALLBACKS ******************************************************************************************/

void Puncher::reset_callback()
{
    qDebug() << ":: reset_callback ::";
    QMessageBox msgBox;

    /* only reset if empty */
    if ((seconds + minutes + hours) != 0) {
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
    qDebug() << ":: ctrl_callback ::";

    /* start or stop accordingly to current state */
    if (timer->isActive()) {
        timer->stop();

        QDate *date = new QDate();
        *date = date->currentDate();

        day = date->day();
        month = date->month();
        year = date->year();

        if (status_ok != db->insert(day, month, year, hours, minutes, seconds))
            qDebug() << "*** ERROR: db->insert ***";

        ctrl->setText("Start");
    } else {
        timer->start(1000);
        ctrl->setText("Pause");
    }
}

void Puncher::timer_callback()
{
    qDebug() << ":: timer_callback ::";
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

void Puncher::check_logs_callback()
{
    qDebug() << ":: check_logs_callback ::";

    Data *cal = new Data();

    /* signal to get info from calendar */
    connect(cal, SIGNAL(set_hours(int,int,int)), this, SLOT(get_hours(int,int,int)));

    cal->setModal(true);
    cal->exec();
}

void Puncher::check_raw_callback()
{
    qDebug() << ":: check_raw_callback ::";

    Data_raw *raw = new Data_raw();
    raw->setModal(true);
    raw->exec();
}

void Puncher::edit_callback()
{
    qDebug() << ":: edit_callback ::";

    /* if updating, first stop counter */
    if (timer->isActive())
        ctrl_callback();

    edit_dialog *edit = new edit_dialog();

    /* signal to get info from edit_dialog */
    connect(edit, SIGNAL(set_hours(int,int,int)), this, SLOT(get_hours(int,int,int)));

    /* pass the timing data along to the new object */
    edit->receive_data(hours, minutes, seconds);
    edit->setModal(true);
    edit->exec();
}

void Puncher::close_callback()
{
    qDebug() << ":: close_callback ::";
    exit(0);
}

/* AUX FUNCTIONS ******************************************************************************************/

status Puncher::update_displays()
{
    qDebug() << ":: update_displays ::";
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

    return status_ok;
}

status Puncher::get_hours(int l_hours, int l_minutes, int l_seconds)
{
    qDebug() << ":: get_hours ::";

    hours = l_hours;
    minutes = l_minutes;
    seconds = l_seconds;

    if (status_ok != update_displays()) {
        qDebug() << "*** ERROR: update_displays ***";
        return err_db;
    }

    if (status_ok != db->insert(day, month, year, hours, minutes, seconds)) {
        qDebug() << "*** ERROR: db->insert ***";
        return err_disp;
    }

    return status_ok;
}

