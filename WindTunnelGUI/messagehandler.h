#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>

enum msgIDs {
    airspeed_msgID,
    pressureTap_msgID
};

class MessageHandler : public QObject
{
    Q_OBJECT
public:
    explicit MessageHandler(QObject *parent = nullptr);

signals:
    void airspeedMessageReady() // FIXME: Needs an argument

};

#endif // MESSAGEHANDLER_H
