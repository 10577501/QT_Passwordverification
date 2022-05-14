#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include "softkey.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection())
         return -1;
    MainWindow w;
    w.show();

    return a.exec();
}
