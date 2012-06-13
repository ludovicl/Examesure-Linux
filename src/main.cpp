#include <QtGui/QApplication>
#include "mainwindow.h"
#include "config.h"
#include <X11/Xlib.h>
#include<X11/Xlib.h>

int main(int argc, char *argv[])
{
    XInitThreads();
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
