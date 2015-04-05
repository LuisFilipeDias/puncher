#ifndef PUNCHER_H
#define PUNCHER_H

#include <QDate>
#include <QTimer>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QShortcut>
#include <QLCDNumber>
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QKeySequence>

#include "data.h"
#include "data_raw.h"
#include "database.h"
#include "errcodes.h"
#include "ui_puncher.h"
#include "edit_dialog.h"
#include "stats_weekly.h"
#include "stats_monthly.h"
#include "filepath.h"


namespace Ui {
class Puncher;
}

class Puncher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Puncher(QWidget *parent = 0);
    ~Puncher();
    QString database_name;

private:
    database *db;
    bool over_hours;
    QTimer * timer;
    QLCDNumber *lcd;
    QSqlQuery qry_p;
    Ui::Puncher *ui;
    QLCDNumber *lcd_secs;
    QAction *check_logs, *check_raw, *close, *stats_weekly, *stats_monthly;
    QPushButton *ctrl, *reset, *extra, *edit;
    int seconds, minutes, hours, day, month, year;
    QShortcut* shortcut;

private slots:
    status init();
    status update_displays();

    void edit_callback();
    void ctrl_callback();
    void close_callback();
    void reset_callback();
    void timer_callback();
    void check_raw_callback();
    void check_logs_callback();
    void stats_weekly_callback();
    void stats_monthly_callback();

public slots:
    status get_hours(int, int, int);
    void get_db_name(QString *);
    void set_db_name(QString);
};


#endif // PUNCHER_H
