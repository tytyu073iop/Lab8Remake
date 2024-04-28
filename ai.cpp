#include "ai.h"
#include "enviroment.h"

AI::AI(enviroment *e, QObject *parent)
    : QObject{parent}, e(e)
{}

void AI::gotTurn() {
    for (int i = 0; i < e->field.size(); ++i) {
        for (int j = 0; j < e->field.size(); ++j) {
            if (e->field[i][j] == 0){
                emit makeTurn(i, j);
                return;
            }
        }
    }
}
