#include "mainwindow.h"
#include "enviroment.h"
#include "playelement.h"
#include <QVector>
#include <QWidget>
#include <QGridLayout>
#include <QDebug>
#include <QPushButton>


void MainWindow::Game(size_t fieldSize, bool IsAiPlay) {
    QVector<QVector<size_t>> field(fieldSize, QVector<size_t>(fieldSize));
    this->e = new enviroment(field);
    this->judge = new Judge(this->e);
    this->ai = new class AI(e);
    QObject::connect(this->judge, SIGNAL(giveTurnToAi()), this->ai, SLOT(gotTurn()));
    QObject::connect(this->ai, SIGNAL(makeTurn(size_t,size_t)), this->judge, SLOT(turnMade(size_t,size_t)));
    QObject::connect(this->judge, SIGNAL(blockAll()), this, SLOT(blockAll()));
    QObject::connect(this->judge, SIGNAL(paint(size_t,size_t,bool)), this, SLOT(paint(size_t,size_t,bool)));
    QObject::connect(this->judge, SIGNAL(unBlockAll()), this, SLOT(unBlockAll()));
    QObject::connect(this->judge, &Judge::win, this, &MainWindow::winSlot);
    QObject::connect(this->judge, SIGNAL(turnChanged()), this, SLOT(turnChanged()));
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
    QGridLayout* grid = new QGridLayout();
    for (size_t var = 0; var < fieldSize; ++var) {
        for (size_t i = 0; i < fieldSize; ++i) {
            auto l = new PlayElement(ih, var, i);
            QObject::connect(l, SIGNAL(clicked(size_t,size_t)), this->ih, SLOT(elementClicked(size_t,size_t)));
            grid->addWidget(l, var, i);
        }
    }
    QGridLayout* miGrid = new QGridLayout(cw);
    miGrid->addLayout(grid, 0, 0);
    QPushButton* clear = new QPushButton("clear");
    QObject::connect(clear, &QPushButton::clicked, this, &MainWindow::Clear);
    miGrid->addWidget(clear);
    QObject::connect(this->ih, SIGNAL(elementClick(size_t,size_t)), this->judge, SLOT(turnMade(size_t,size_t)));
    //this->setCentralWidget(w);
}
