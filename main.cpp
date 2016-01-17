#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    MainWindow w;//w is object for main window
    w.show();//displays the main window

    return a.exec();
}
