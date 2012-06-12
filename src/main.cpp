#include <QtGui/QApplication>
#include "mainwindow.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int returnValue = a.exec();


    if (0!=returnValue)
    {
        QProcess::startDetached(argv[0], a.arguments());

    }
    return returnValue;
    
    //    return a.exec();
}
