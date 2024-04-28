#ifndef KEYBLOCKER_H
#define KEYBLOCKER_H

#include <QObject>

class KeyBlocker : public QObject
{
    Q_OBJECT
public:
    explicit KeyBlocker(QObject *parent = nullptr);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
signals:
};

#endif // KEYBLOCKER_H
