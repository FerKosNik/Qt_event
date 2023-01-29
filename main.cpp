#include "mainwindow.h"

#include <QApplication>
#include "MouseObserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    MouseObserver mouseObserver;
    mouseObserver.resize(600, 400);
    mouseObserver.show();

    return a.exec();
}
