#ifndef STATS_MONTHLY_H
#define STATS_MONTHLY_H

#include <QDialog>

#include "ui_stats_monthly.h"
#include "database.h"
#include "../inc/common.h"

namespace Ui {
class Stats_Monthly;
}

class Stats_Monthly : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Monthly(QWidget *parent = 0);
    ~Stats_Monthly();


private slots:
    void update_graph();
    QVector<double> get_hours(int, sw_pos[]);
    void month_changed_callback(int);


private:
    Ui::Stats_Monthly *ui;
    int work_hours[31];
    QSpinBox *stats_monthly_month;
    QLabel *stats_monthly_label_from, *stats_monthly_label_to, *stats_monthly_monthly_statistics;
    QPushButton *stats_monthly_update;
    QLineEdit *stats_monthly_average_hours, *stats_monthly_working_days, *stats_monthly_total_hours;

    sw_pos pos[31];
    database *db;
    int the_month;
    int the_year;
    bool no_graph;
};

#endif // STATS_MONTHLY_H
