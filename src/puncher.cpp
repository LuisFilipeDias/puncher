#include "../inc/puncher.h"

Puncher::Puncher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Puncher)
{
    over_hours = false;
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
    connect(stats_weekly, SIGNAL(triggered()), this, SLOT(stats_weekly_callback()));
    connect(stats_monthly, SIGNAL(triggered()), this, SLOT(stats_monthly_callback()));

    /* connecting return key to start stop */
    QKeySequence key_return(Qt::Key_Return);
    shortcut = new QShortcut(key_return, ui->ctrlButton);
    QObject::connect(shortcut, SIGNAL(activated()),ui->ctrlButton, SLOT(click()));

    /* connecting R key to reset */
    QKeySequence key_reset(Qt::Key_R);
    shortcut = new QShortcut(key_reset, ui->ctrlButton);
    QObject::connect(shortcut, SIGNAL(activated()),ui->resetButton, SLOT(click()));

    /* connecting E key to edit */
    QKeySequence key_edit(Qt::Key_E);
    shortcut = new QShortcut(key_edit, ui->editButton);
    QObject::connect(shortcut, SIGNAL(activated()),ui->editButton, SLOT(click()));

    /* connecting 1 key to log */
    QKeySequence key_log(Qt::Key_1);
    shortcut = new QShortcut(key_log, this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->actionCheck_Logs, SLOT(trigger()));

    /* connecting 2 key to raw */
    QKeySequence key_raw(Qt::Key_2);
    shortcut = new QShortcut(key_raw, this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->actionCheck_Raw, SLOT(trigger()));

    /* connecting Escape key to close */
    QKeySequence key_escape(Qt::Key_Escape);
    shortcut = new QShortcut(key_escape, this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->actionClose, SLOT(trigger()));

    /* connecting 3 key to weekly stats  */
    QKeySequence key_weekly_stats(Qt::Key_3);
    shortcut = new QShortcut(key_weekly_stats, this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->actionWeekly, SLOT(trigger()));

    /* connecting 4 key to monthly stats  */
    QKeySequence key_monthly_stats(Qt::Key_4);
    shortcut = new QShortcut(key_monthly_stats, this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->actionMonthly, SLOT(trigger()));
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
    stats_weekly = ui->actionWeekly;
    stats_monthly = ui->actionMonthly;
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
    if (hours >= 8 && !over_hours) {
        QMessageBox msgBox;
        msgBox.setText("You are working over-hours. Go Home!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        over_hours = true;
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

void Puncher::stats_weekly_callback()
{
    qDebug() << ":: stats_weekly_callback ::";

    Stats_Weekly *stats_weekly = new Stats_Weekly();
    stats_weekly->setModal(true);
    stats_weekly->exec();
}

void Puncher::stats_monthly_callback()
{
    qDebug() << ":: stats_monthly_callback ::";

    Stats_Monthly *stats_monthly = new Stats_Monthly();
    stats_monthly->setModal(true);
    stats_monthly->exec();
}

/* AUX FUNCTIONS ******************************************************************************************/

status Puncher::update_displays()
{
    qDebug() << ":: update_displays ::";
    char display_str[6];
    char aux[2];

    snprintf(aux, 2, "%d", hours/10);
    strcpy(display_str, aux);
    snprintf(aux, 2, "%d", hours%10);
    strcat(display_str, aux);

    lcd->display(display_str);

    snprintf(aux, 2, "%d", minutes/10);
    strcpy(display_str, aux);
    snprintf(aux, 2, "%d", minutes%10);
    strcat(display_str, aux);

    strcat(display_str, ":");

    snprintf(aux, 2, "%d", seconds/10);
    strcat(display_str, aux);
    snprintf(aux, 2, "%d", seconds%10);
    strcat(display_str, aux);

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

