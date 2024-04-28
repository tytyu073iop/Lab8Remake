#include "keyblocker.h"
#include <QMouseEvent>

KeyBlocker::KeyBlocker(QObject *parent)
    : QObject{parent}
{}

bool KeyBlocker::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick || event->type() == QEvent::MouseButtonRelease) {
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
