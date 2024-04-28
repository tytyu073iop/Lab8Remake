#ifndef INTERFACEHANDLER_H
#define INTERFACEHANDLER_H

#include <QObject>

class InterfaceHandler : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceHandler(QObject *parent = nullptr);

public slots:
    void elementClicked(size_t x, size_t y);
    void clearClicked();
signals:
};

#endif // INTERFACEHANDLER_H
