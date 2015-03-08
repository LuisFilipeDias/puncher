#ifndef STATS_WEEKLY_H
#define STATS_WEEKLY_H

#include <QDialog>
#include "../libs/qcustomplot/qcustomplot.h"

#include "ui_stats_weekly.h"
#include "database.h"

struct sw_pos{
    int day;
    int month;
    int year;
};

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
    QVector<double> get_hours(sw_pos[]);
    int days_in_month(int);
    sw_pos fill_next_pos(sw_pos);
    sw_pos fill_prev_pos(sw_pos);
    void week_changed_callback(int);

    void on_stats_weekly_update_clicked();

private:
    int d_o_w;
    Ui::Stats_Weekly *ui;
    int work_hours[7];
    QSpinBox *stats_weekly_week;
    QLabel *stats_weekly_label;
    QPushButton *stats_weekly_update;
    sw_pos pos[7];
    database *db;
    int the_week;
    bool no_graph;
};
#endif // STATS_WEEKLY_H
