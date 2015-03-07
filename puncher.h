#ifndef PUNCHER_H
#define PUNCHER_H

#include <QDate>
#include <QTimer>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QLCDNumber>
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>

#include "data.h"
#include "data_raw.h"
#include "database.h"
#include "errcodes.h"
#include "ui_puncher.h"
#include "edit_dialog.h"

namespace Ui {
class Puncher;
}

class Puncher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Puncher(QWidget *parent = 0);
    ~Puncher();

private:
    database *db;
    QTimer * timer;
    QLCDNumber *lcd;
    QSqlQuery qry_p;
    Ui::Puncher *ui;
    QLCDNumber *lcd_secs;
    QPushButton *ctrl, *reset, *extra, *edit;
    int seconds, minutes, hours, day, month, year;
    QAction *check_logs, *check_raw, *close;

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

public slots:
    status get_hours(int, int, int);
};


#endif // PUNCHER_H
