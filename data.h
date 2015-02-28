#ifndef DATA_H
#define DATA_H

#include <QDialog>

namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = 0);
    ~Data();

private slots:
    void on_data_load_clicked();

    void on_data_raw_clicked();

    void on_data_cancel_clicked();

private:
    Ui::Data *ui;
};

#endif // DATA_H
