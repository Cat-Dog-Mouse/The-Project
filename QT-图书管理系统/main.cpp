#include "mainwindow.h"
#include"login.h"
#include <QApplication>
#include "stusql.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    stuSql sql;

    return a.exec();
}
