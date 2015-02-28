#include "data.h"
#include "data_raw.h"
#include "puncher.h"
#include "ui_data.h"

Data::Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);

}

Data::~Data()
{
    delete ui;
}

void Data::on_data_load_clicked()
{
}

void Data::on_data_raw_clicked()
{
    Data_raw raw;
    raw.setModal(true);
    raw.exec();
}

void Data::on_data_cancel_clicked()
{
    this->close();
}
