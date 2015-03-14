#ifndef STATS_WEEKLY_H
#define STATS_WEEKLY_H

#include <QDialog>
#include <QLineEdit>

#include "../libs/qcustomplot/qcustomplot.h"
#include "ui_stats_weekly.h"
#include "../inc/common.h"
#include "database.h"

namespace Ui {
class Stats_Weekly;
}

class Stats_Weekly : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Weekly(QWidget *parent = 0);
    ~Stats_Weekly();

private slots:
    void update_graph();
    QVector<double> get_hours(int, sw_pos[]);
    sw_pos fill_next_pos(sw_pos);
    sw_pos fill_prev_pos(sw_pos);
    void week_changed_callback(int);

private:
    int d_o_w;
    Ui::Stats_Weekly *ui;
    int work_hours[7];
    QSpinBox *stats_weekly_week;
    QLabel *stats_weekly_label_from, *stats_weekly_label_to, *stats_weekly_weekly_statistics;
    QPushButton *stats_weekly_update;
    QLineEdit *stats_weekly_average_hours, *stats_weekly_working_days, *stats_weekly_total_hours;

    sw_pos pos[7];
    database *db;
    int the_week;
    bool no_graph;
};
#endif // STATS_WEEKLY_H
