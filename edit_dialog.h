#ifndef EDIT_DIALOG_H
#define EDIT_DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>

namespace Ui {
class edit_dialog;
}

class edit_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit edit_dialog(QWidget *parent = 0);
    ~edit_dialog();

private slots:
    void on_edit_dialog_cancel_clicked();

    void on_edit_dialog_ok_clicked();

public slots:
    void receive_data(int, int, int);

private:
    Ui::edit_dialog *ui;
    int sel_day, sel_month, sel_year, sel_hours, sel_minutes, sel_seconds;
    QSpinBox *edit_dialog_input_hours, *edit_dialog_input_minutes, *edit_dialog_input_seconds;

signals:
    void set_hours(int, int, int);
};

#endif // EDIT_DIALOG_H
