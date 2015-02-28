#ifndef DATA_RAW_H
#define DATA_RAW_H

#include <QDialog>

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
    void on_data_raw_get_raw_clicked();

    void on_data_raw_cancel_clicked();

private:
    Ui::Data_raw *ui;
};

#endif // DATA_RAW_H
