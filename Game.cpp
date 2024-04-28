#include "mainwindow.h"
#include "enviroment.h"
#include "playelement.h"
#include <QVector>
#include <QWidget>
#include <QGridLayout>
#include <QDebug>


void MainWindow::Game(size_t fieldSize, bool IsAiPlay) {
    QVector<QVector<size_t>> field(fieldSize, QVector<size_t>(fieldSize));
    this->e = new enviroment(field);
    this->e->isAiEnabled = IsAiPlay;
    this->setMenuWidget(new QLabel(e->turn ? "crosses" : "circles"));
    auto cw = this->centralWidget();
    qDebug() << cw->children();
    for (auto i : cw->children()) {
        delete i;
    }
    //QWidget* w = new QWidget();
    //this->setCentralWidget(new QLabel("test"));
    InterfaceHandler* ih = new InterfaceHandler();
    QGridLayout* grid = new QGridLayout(cw);
    for (size_t var = 0; var < fieldSize; ++var) {
        for (size_t i = 0; i < fieldSize; ++i) {
            grid->addWidget(new PlayElement(ih, var, i), var, i);
        }
    }
    //this->setCentralWidget(w);
}
