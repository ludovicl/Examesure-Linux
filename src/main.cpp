#include <QtGui/QApplication>
#include "mainwindow.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
Config conf;
conf.show();
    
    return a.exec();
}
