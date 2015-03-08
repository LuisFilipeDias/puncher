#include "../inc/stats_monthly.h"

Stats_Monthly::Stats_Monthly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats_Monthly)
{
    setWindowTitle("Monthly Statistics");

    ui->setupUi(this);
}

Stats_Monthly::~Stats_Monthly()
{
    delete ui;
}
