#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QErrorMessage>
#include <QMainWindow>
#include <QLineEdit>
#include <QPixmap>
//#include <QLabel>
#include "enviroment.h"
#include "keyblocker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPixmap images[2]{QPixmap("circle.png"), QPixmap("square.png")};

public:
    MainWindow(QWidget *parent = nullptr);
    enviroment* e;

    ~MainWindow();

public slots:
    void AI();
    void P2();
    void win(QVector<QPair<size_t, size_t> >);
    void paint(size_t x, size_t y, bool turn);
    void blockAll();
    void unBlockAll();
    void turnChanged();

private:
    KeyBlocker* kb = new KeyBlocker();
    Ui::MainWindow *ui;
    QErrorMessage err;
    const QLineEdit* GetTextField();
    void Game(size_t fieldSize, bool IsAiPlay);
};
#endif // MAINWINDOW_H
