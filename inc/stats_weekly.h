#ifndef STATS_WEEKLY_H
#define STATS_WEEKLY_H

#include <QDialog>

#include "ui_stats_weekly.h"

namespace Ui {
class Stats_Weekly;
}

class Stats_Weekly : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Weekly(QWidget *parent = 0);
    ~Stats_Weekly();

private:
    Ui::Stats_Weekly *ui;
};

#endif // STATS_WEEKLY_H
