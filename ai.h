#ifndef AI_H
#define AI_H

#include <QObject>
#include "enviroment.h"

class AI : public QObject
{
    Q_OBJECT
    enviroment* e;
public:
    explicit AI(enviroment* e, QObject *parent = nullptr);

public slots:
    void gotTurn();

signals:
    void makeTurn(size_t x, size_t y);
};

#endif // AI_H
