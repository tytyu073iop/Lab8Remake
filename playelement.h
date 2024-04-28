#ifndef PLAYELEMENT_H
#define PLAYELEMENT_H

#include "interfacehandler.h"
#include <QLabel>

class PlayElement : public QLabel
{
    Q_OBJECT
    size_t x, y;
public:
    PlayElement(InterfaceHandler* ih, size_t x, size_t y);
    void mousePressEvent(QMouseEvent *event);
signals:
    void clicked(size_t x, size_t y);
};

#endif // PLAYELEMENT_H
