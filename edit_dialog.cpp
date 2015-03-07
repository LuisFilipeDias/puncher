#include "edit_dialog.h"
#include "puncher.h"
#include "ui_edit_dialog.h"

edit_dialog::edit_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_dialog)
{
    ui->setupUi(this);
}

edit_dialog::~edit_dialog()
{
    delete ui;
}

void edit_dialog::receive_data(int hours, int minutes, int seconds)
{
    edit_dialog_input_hours = ui->edit_dialog_input_hours;
    edit_dialog_input_minutes = ui->edit_dialog_input_minutes;
    edit_dialog_input_seconds = ui->edit_dialog_input_seconds;

    edit_dialog_input_hours->setValue(hours);
    edit_dialog_input_minutes->setValue(minutes);
    edit_dialog_input_seconds->setValue(seconds);
}

void edit_dialog::on_edit_dialog_cancel_clicked()
{
    qDebug() << ":: on_edit_dialog_cancel_clicked ::";
    this->close();
}

void edit_dialog::on_edit_dialog_ok_clicked()
{
    /* sending signal to puncher object */
    emit(set_hours(edit_dialog_input_hours->value(),
                   edit_dialog_input_minutes->value(),
                   edit_dialog_input_seconds->value()));

    this->close();
}
