#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDebug>
#include <QString>
#include <QSqlDatabase>

#include "errcodes.h"

class database
{
public:
    database();
    status init(QString);
    status get_db_path(QString*);
    status update_db_path(QString);
    QSqlQuery get_all();
    status insert(int, int, int, int, int, int);
    status query(int, int, int, int*, int*, int*);
};

#endif // DATABASE_H
