#ifndef DATA_H
#define DATA_H

#include <QDialog>
#include <QCalendarWidget>
#include <QLabel>
#include <QSpinBox>

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
    void on_data_load_clicked();

    void on_data_raw_clicked();

    void on_data_cancel_clicked();

    void on_calendarWidget_selectionChanged();

    void fill_date(int*, int*);

    void on_data_update_clicked();

private:
    Ui::Data *ui;
    QCalendarWidget *calendar;
    int sel_day, sel_month, sel_year, sel_hours, sel_minutes, sel_seconds;
    QLabel *data_title, *data_hours, *data_minutes, *data_seconds;
    QSpinBox *data_input_hours, *data_input_minutes, *data_input_seconds;
};

#endif // DATA_H
