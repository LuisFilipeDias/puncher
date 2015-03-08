#ifndef STATS_MONTHLY_H
#define STATS_MONTHLY_H

#include <QDialog>

#include "ui_stats_monthly.h"

namespace Ui {
class Stats_Monthly;
}

class Stats_Monthly : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Monthly(QWidget *parent = 0);
    ~Stats_Monthly();

private:
    Ui::Stats_Monthly *ui;
};

#endif // STATS_MONTHLY_H
