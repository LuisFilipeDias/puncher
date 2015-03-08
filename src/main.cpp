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

    database *db = new database();

    if (status_ok != db->init())
        qDebug() << "*** ERROR: db->init ***";

    Puncher w;
    w.show();

    return a.exec();
}

void quitting()
{
    qDebug( "Leaving app");
}

      /*qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (1, 'John', 'Doe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (2, 'Jane', 'Doe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (3, 'James', 'Doe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (4, 'Judy', 'Doe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (5, 'Richard', 'Roe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (6, 'Jane', 'Roe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (7, 'John', 'Noakes')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (8, 'Donna', 'Doe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "INSERT INTO puncher_db (id, firstname, lastname) VALUES (9, 'Ralph', 'Roe')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

      qry.prepare( "SELECT * FROM puncher_db" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
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


      qry.prepare( "SELECT firstname, lastname FROM puncher_db WHERE lastname = 'Roe'" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
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


      qry.prepare( "SELECT firstname, lastname FROM puncher_db WHERE lastname = 'Roe' ORDER BY firstname" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
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


      qry.prepare( "SELECT lastname, COUNT(*) as 'members' FROM puncher_db GROUP BY lastname ORDER BY lastname" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
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

      qry.prepare( "UPDATE puncher_db SET firstname = 'Nisse', lastname = 'Svensson' WHERE id = 7" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Updated!" );

      qry.prepare( "UPDATE puncher_db SET lastname = 'Johnson' WHERE firstname = 'Jane'" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Updated!" );

      qry.prepare( "DELETE FROM puncher_db WHERE id = 7" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Deleted!" );

      qry.prepare( "DELETE FROM puncher_db WHERE lastname = 'Johnson'" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Deleted!" );

      db.close();
*/
