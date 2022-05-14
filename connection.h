#ifndef CONNECTION
#define CONNECTION

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db = 				QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("password.db");//设置数据库的名称为“password.db”
    db.open();
    if (!db.open()) {
       QMessageBox::critical(0, qApp->tr("Cannot open database"), qApp->tr("Unable to establisha database connection."), QMessageBox::Cancel);
       return false;
    }
    QSqlQuery query;
    query.exec("create table user(name text primary key not null,pwd);");
    return true;
 }

#endif // CONNECTION

