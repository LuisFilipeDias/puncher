#include "../inc/puncher.h"
#include "../inc/database.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QtDebug>

extern database *db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Puncher w;
    w.show();

    return a.exec();
}

void quitting()
{
    qDebug( "Leaving app");
}
