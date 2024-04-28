#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <QVector>

class enviroment
{
public:
    enviroment(const QVector<QVector<size_t>>& field);
    QVector<QVector<size_t>> field;
    bool turn = false;
    bool AiTurn = false;
    bool isAiEnabled = false;
};

#endif // ENVIROMENT_H
