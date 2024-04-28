#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QIntValidator>

int main(int argc, char *argv[])
{
    size_t size;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
