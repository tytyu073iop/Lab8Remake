#include "judge.h"
#include <QDebug>
#include <QPair>
#include <QGridLayout>

void Judge::giveTurn()
{
    e->turn = e->turn ? false : true;
    emit turnChanged();
    if (e->turn == e->AiTurn && e->isAiEnabled) {
        emit giveTurnToAi();
    } else {
        emit unBlockAll();
    }
}

Judge::Judge(enviroment *e, QObject *parent)
    : QObject{parent}, e(e)
{}

void Judge::turnMade(size_t x, size_t y)
{
    emit blockAll();
    emit paint(x, y, e->turn);
    qDebug() << "GetCurPlay: " << x << " " << y;
    e->field[x][y] = e->turn + 1;
    auto xb = x;
    auto yb = y;
    bool winb = false;
    QVector<QPair<size_t, size_t>> winItem;
    {
        x -= 2;
        size_t streak = 0;
        for (int i = x; i < x + 5 && !winb; ++i) {
            if (e->field.value(i, QVector<size_t>(e->field.size()))[y] == e->turn + 1) {
                streak++;
                winItem.push_back({y, i});
                if (streak >= 3) {
                    winb = true;
                    emit win(winItem);
                    break;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
        y -= 2;
        x = xb;
        winItem.clear();
        for (int i = y; i < y + 5 && !winb; ++i) {
            if (e->field[x].value(i, 0) == e->turn + 1) {
                streak++;
                winItem.push_back({i, x});
                if (streak >= 3) {
                    winb = true;
                    emit win(winItem);
                    break;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
        y = yb;
        winItem.clear();
        for (int i = -2; i < 3 && !winb; ++i) {
            if (e->field.value(x + i, QVector<size_t>(e->field.size())).value(y + i, 0) == e->turn + 1) {
                streak++;
                winItem.push_back({y + i, x + i});
                if (streak >= 3) {
                    winb = true;
                    emit win(winItem);
                    break;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
        winItem.clear();
        for (int i = -2; i < 3 && !winb; ++i) {
            if (e->field.value(x + i, QVector<size_t>(e->field.size())).value(y - i, 0) == e->turn + 1) {
                streak++;
                winItem.push_back({y - i, x + i});
                if (streak >= 3) {
                    winb = true;
                    emit win(winItem);
                    break;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
    }
    if (!winb) {
        this->giveTurn();
    }
}
