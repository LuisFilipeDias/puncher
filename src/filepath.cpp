#include "../inc/filepath.h"
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

void FilePath::on_filepath_cancel_clicked()
{
    this->close();
}

void FilePath::on_filepath_ok_clicked()
{
    QTextEdit *input = ui->filepath_textedit;
    emit(set_db_name(input->toPlainText()));
    this->close();
}
