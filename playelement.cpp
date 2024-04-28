#include "playelement.h"
#include "interfacehandler.h"
#include <QMouseEvent>

PlayElement::PlayElement(InterfaceHandler* ih, size_t x, size_t y) : x(x), y(y) {
    this->setFrameShape(QFrame::Box);
    this->setScaledContents(true);
    QObject::connect(this, &PlayElement::clicked, ih, &InterfaceHandler::elementClicked);
    this->show();
}

void PlayElement::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked(x, y);
    } else {
        // pass on other buttons to base class
        QLabel::mousePressEvent(event);
    }
}
