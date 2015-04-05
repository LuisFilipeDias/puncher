#include "filepath.h"
#include "ui_filepath.h"

FilePath::FilePath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilePath)
{
    ui->setupUi(this);
}

FilePath::~FilePath()
{
    delete ui;
}
