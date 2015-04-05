#ifndef FILEPATH_H
#define FILEPATH_H

#include <QDialog>

namespace Ui {
class FilePath;
}

class FilePath : public QDialog
{
    Q_OBJECT

public:
    explicit FilePath(QWidget *parent = 0);
    ~FilePath();

private:
    Ui::FilePath *ui;
};

#endif // FILEPATH_H
