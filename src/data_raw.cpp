#include "../inc/data_raw.h"

Data_raw::Data_raw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data_raw)
{   
    setWindowTitle("Raw Data");

    ui->setupUi(this);
    get_raw();
}

Data_raw::~Data_raw()
{
    delete ui;
}

void Data_raw::get_raw()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    /* fill the table from all the info taken from the db object */
    model->setQuery(db->get_all());
    ui->tableView->setModel(model);
}

void Data_raw::on_data_raw_cancel_clicked()
{
    this->close();
}
