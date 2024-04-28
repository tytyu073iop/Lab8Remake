#ifndef JUDGE_H
#define JUDGE_H
#include "enviroment.h"
#include <QObject>

class Judge : public QObject
{
    Q_OBJECT
    void giveTurn();
    enviroment* e;
public:
    explicit Judge(enviroment*, QObject *parent = nullptr);
    
public slots:
    void turnMade(size_t x, size_t y);

signals:
    void win(QVector<QPair<size_t, size_t>> winItem);
    void unBlockAll();
    void blockAll();
    void paint(size_t x, size_t y, bool turn);
    void turnChanged();
    void giveTurnToAi();
};

#endif // JUDGE_H
