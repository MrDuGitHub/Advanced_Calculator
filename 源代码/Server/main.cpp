#include "mainwindow.h"
#include <QApplication>
#include "network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Network n(&w);
    w.setWindowTitle("计算器服务端");
    w.show();
    return a.exec();
}
