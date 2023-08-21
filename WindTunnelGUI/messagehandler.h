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
    // TO IMPLEMENT

private:
    void handleMessage(QByteArray msg);
    void parseAirspeedMessage(QByteArray *msg);
    void parsePressureTapMessage(QByteArray *msg);

};

#endif // MESSAGEHANDLER_H
