#ifndef FILEPATH_H
#define FILEPATH_H

#include <QDialog>
#include <QTextEdit>

#include "puncher.h"

namespace Ui {
class FilePath;
}

class FilePath : public QDialog
{
    Q_OBJECT

public:
    explicit FilePath(QWidget *parent = 0);
    ~FilePath();

private slots:
    void on_filepath_cancel_clicked();

    void on_filepath_ok_clicked();

private:
    Ui::FilePath *ui;

signals:
    void set_db_name(QString);

};

#endif // FILEPATH_H
