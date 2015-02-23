#ifndef PUNCHER_H
#define PUNCHER_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QPushButton>
#include <QSqlDatabase>
#include <QtSql>

namespace Ui {
class Puncher;
}

class Puncher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Puncher(QWidget *parent = 0);
    ~Puncher();

private:
    Ui::Puncher *ui;
    QTimer * timer;
    QLCDNumber *lcd;
    QLCDNumber *lcd_secs;
    QPushButton *ctrl, *reset;
    int seconds, minutes, hours, day, month, year;

private slots:
    void init();
    void timer_callback();
    void ctrl_callback();
    void reset_callback();
    void update_displays();
    void insert_into_db(int, int, int, int, int);
};

#endif // PUNCHER_H
