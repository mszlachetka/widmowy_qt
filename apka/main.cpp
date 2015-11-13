#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.addLibraryPath(":/plugins/imageformats");
    MainWindow w;
    w.show();

    return a.exec();
}
