#include "data_raw.h"
#include "ui_data_raw.h"

Data_raw::Data_raw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data_raw)
{
    ui->setupUi(this);
}

Data_raw::~Data_raw()
{
    delete ui;
}
