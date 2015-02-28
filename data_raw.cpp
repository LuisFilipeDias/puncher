#include "data_raw.h"
#include "ui_data_raw.h"
#include "puncher.h"
#include <QSqlQueryModel>

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

void Data_raw::on_data_raw_get_raw_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    //QSqlQuery *qry;

    //Puncher puncher;
    //puncher.dump_all_info(qry);

    QSqlQuery qry;

    qry.prepare( "SELECT * FROM puncher_db" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
      qDebug( "Selected!" );

      QSqlRecord rec = qry.record();

      int cols = rec.count();

      for( int c=0; c<cols; c++ )
        qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

      for( int r=0; qry.next(); r++ )
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
    }

    model->setQuery(qry);
    ui->tableView->setModel(model);
}

void Data_raw::on_data_raw_cancel_clicked()
{
    this->close();
}
