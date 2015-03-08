#include "../inc/stats_weekly.h"

Stats_Weekly::Stats_Weekly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats_Weekly)
{
    setWindowTitle("Weekly Statistics");
    ui->setupUi(this);
}

Stats_Weekly::~Stats_Weekly()
{
    delete ui;
}
