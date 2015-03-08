#include "../inc/database.h"

database::database()
{
}

status database::init()
{
    QSqlDatabase sql_db = QSqlDatabase::addDatabase( "QSQLITE" );

    sql_db.setDatabaseName( "./puncher_new.db" );

    if( !sql_db.open() )
    {
      qDebug() << sql_db.lastError();
      qFatal( "Failed to connect." );
    }

    qDebug( "Connected!" );

    return status_ok;
}

status database::insert(int l_day, int l_month, int l_year, int l_hours, int l_minutes, int l_seconds)
{
    qDebug() << ":: insert_into_db ::";
    QSqlQuery qry;
    int rows = 0;

    qry.prepare( "CREATE TABLE IF NOT EXISTS puncher_db (id INTEGER UNIQUE PRIMARY KEY, day VARCHAR(30), month VARCHAR(30), year VARCHAR(30), hours VARCHAR(30), minutes VARCHAR(30), seconds VARCHAR(30))" );
    if (!qry.exec())
        qDebug() << qry.lastError();
    else
        qDebug() << "Table created!";

    QString qry_str = "SELECT * FROM puncher_db WHERE day='" +
            QString::number( l_day )     + "' AND month='" +
            QString::number( l_month )   + "' AND year='" +
            QString::number( l_year )    + "'";

    qry.prepare(qry_str);

    if (!qry.exec()) {
        qDebug() << qry.lastError();
    } else {
        for( rows=0; qry.next(); rows++ );
    }

    if (rows) {
        QString qry_str = "UPDATE puncher_db SET hours='" +
                QString::number( l_hours )   + "', minutes='" +
                QString::number( l_minutes ) + "', seconds='" +
                QString::number( l_seconds ) + "' WHERE day='" +
                QString::number( l_day )     + "' AND month='" +
                QString::number( l_month )   + "' AND year='" +
                QString::number( l_year )    + "'";

        qry.prepare(qry_str);
        if (!qry.exec())
            qDebug() << qry.lastError();
        else
            qDebug() << "Updated row!";
    } else {
        qry_str = "INSERT INTO puncher_db (day, month, year, hours, minutes, seconds) VALUES (" +
                QString::number( l_day )     + ", " +
                QString::number( l_month )   + ", " +
                QString::number( l_year )    + ", " +
                QString::number( l_hours )   + ", " +
                QString::number( l_minutes ) + ", " +
                QString::number( l_seconds ) + ")";

        qry.prepare(qry_str);
        if (!qry.exec())
            qDebug() << qry.lastError();
        else
            qDebug() << "Inserted new row!";
    }

    return status_ok;
}

QSqlQuery database::get_all()
{
    QSqlQuery qry;

    qry.prepare( "SELECT * FROM puncher_db" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
#ifdef DB_debug
    else
    {
      qDebug( "Selected!" );

      QSqlRecord rec = qry.record();

      int cols = rec.count();

      for( int c=0; c<cols; c++ )
        qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

      for( int r=0; qry.next(); r++ )
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
    }
#endif
    return qry;
}

status database::query(int l_day, int l_month, int l_year, int *l_hours, int *l_minutes, int *l_seconds)
{
    QSqlQuery qry;
    QString qry_str = "SELECT hours, minutes, seconds FROM puncher_db WHERE day='" +
            QString::number( l_day )     + "' AND month='" +
            QString::number( l_month )   + "' AND year='" +
            QString::number( l_year )    + "'";

    qry.prepare( qry_str );
    if (!qry.exec()) {
        qDebug() << qry.lastError();
    } else {
        QSqlRecord rec = qry.record();
        qry.next();

        *l_hours = qry.value(0).toInt();
        *l_minutes = qry.value(1).toInt();
        *l_seconds = qry.value(2).toInt();
    }

    return status_ok;
}
