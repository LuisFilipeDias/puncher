#ifndef DATA_H
#define DATA_H

#include <QLabel>
#include <QDialog>
#include <QSpinBox>
#include <QSqlQuery>
#include <QMessageBox>
#include <QCalendarWidget>

#include "puncher.h"
#include "ui_data.h"
#include "data_raw.h"
#include "database.h"

namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = 0);
    ~Data();

private slots:
    void fill_date();
    void on_data_raw_clicked();
    void on_data_cancel_clicked();
    void on_data_update_clicked();
    void on_calendarWidget_selectionChanged();

private:
    database *db;
    Ui::Data *ui;
    QCalendarWidget *calendar;
    QLabel *data_title, *data_hours, *data_minutes, *data_seconds;
    QSpinBox *data_input_hours, *data_input_minutes, *data_input_seconds;
    int sel_day, sel_month, sel_year, sel_hours, sel_minutes, sel_seconds;

signals:
    void set_hours(int, int, int);

};

#endif // DATA_H
