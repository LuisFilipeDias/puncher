#ifndef DATA_RAW_H
#define DATA_RAW_H

#include <QDialog>
#include <QSqlQueryModel>

#include "puncher.h"
#include "database.h"
#include "ui_data_raw.h"

namespace Ui {
class Data_raw;
}

class Data_raw : public QDialog
{
    Q_OBJECT

public:
    explicit Data_raw(QWidget *parent = 0);
    ~Data_raw();

private slots:
    void get_raw();
    void on_data_raw_cancel_clicked();

private:
    database *db;
    Ui::Data_raw *ui;
};

#endif // DATA_RAW_H
