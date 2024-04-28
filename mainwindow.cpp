#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QErrorMessage>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QIntValidator>
#include <QPixmap>
#include "playelement.h"
#include "keyblocker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), err(this)
{
    ui->setupUi(this);
    QWidget* m = new QWidget();
    QGridLayout* grid = new QGridLayout(m);
    QPushButton* p2 = new QPushButton("2 players", this);
    QObject::connect(p2, SIGNAL(clicked(bool)), this, SLOT(P2()));
    QPushButton* ai = new QPushButton("AI", this);
    QObject::connect(ai, SIGNAL(clicked(bool)), this, SLOT(AI()));
    QLineEdit* textField = new QLineEdit("3");
    QIntValidator* validator = new QIntValidator();
    validator->setBottom(3);
    textField->setValidator(validator);
    grid->addWidget(p2);
    grid->addWidget(ai);
    grid->addWidget(textField);
    this->setCentralWidget(m);
    this->resize(200, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AI()
{
    const QLineEdit* textField = GetTextField();
    qDebug() << textField->text() << " " << textField->hasAcceptableInput();
    if (!textField->hasAcceptableInput()) {
        err.showMessage("invalid number");
        return;
    }

}

void MainWindow::P2()
{
    const QLineEdit* textField = GetTextField();
    qDebug() << textField->text() << " " << textField->hasAcceptableInput();
    if (!textField->hasAcceptableInput()) {
        err.showMessage("invalid number");
        return;
    }
    Game(textField->text().toULong(), false);
}

void MainWindow::win(QVector<QPair<size_t, size_t> > wi)
{
    blockAll();
    for (auto i : wi) {
        auto widget = this->centralWidget();
        auto grid = static_cast<const QGridLayout*>(widget->children()[0]);
        auto label = static_cast<QLabel*>(grid->itemAtPosition(i.first, i.second)->widget());
        label->setStyleSheet("QLabel { background-color : green; }");
    }
    this->setMenuWidget(new QLabel("Game over!"));
}

void MainWindow::paint(size_t x, size_t y, bool turn)
{
    auto widget = this->centralWidget();
    auto grid = static_cast<const QGridLayout*>(widget->children()[0]);
    auto label = static_cast<QLabel*>(grid->itemAtPosition(x, y)->widget());
    label->setPixmap(this->images[turn]);
    label->installEventFilter(kb);
}

void MainWindow::blockAll()
{
    auto widget = this->centralWidget();
    auto grid = static_cast<const QGridLayout*>(widget->children()[0]);
    for (int i = 0; i < e->field.size(); ++i) {
        for (int j = 0; j < e->field.size(); ++j) {
            auto label = static_cast<QLabel*>(grid->itemAtPosition(i, j)->widget());
            label->installEventFilter(kb);
        }
    }
}

void MainWindow::unBlockAll()
{
    auto widget = this->centralWidget();
    auto grid = static_cast<const QGridLayout*>(widget->children()[0]);
    for (int i = 0; i < e->field.size(); ++i) {
        for (int j = 0; j < e->field.size(); ++j) {
            if (e->field[i][j] == 0) {
                auto label = static_cast<QLabel*>(grid->itemAtPosition(i, j)->widget());
                label->removeEventFilter(kb);
            }
        }
    }
}

void MainWindow::turnChanged()
{
    this->setMenuWidget(new QLabel(e->turn ? "crosses" : "circles"));
}



const QLineEdit* MainWindow::GetTextField()
{
    auto widget = this->centralWidget();
    auto list = widget->children();
    qDebug() << list;
    return static_cast<const QLineEdit*>(list[3]);
}


