#include "interfacehandler.h"

InterfaceHandler::InterfaceHandler(QObject *parent)
    : QObject{parent}
{

}

void InterfaceHandler::elementClicked(size_t x, size_t y)
{
    emit elementClick(x, y);
}

void InterfaceHandler::clearClicked()
{

}
