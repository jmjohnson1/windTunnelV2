#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include <QDebug>

#define AIRSPEED_MSG_LENGTH 4
#define PRESSURETAP_MSG_LENGTH 21

enum msgID_enum {
    airspeed_msgID,
    pressureTap_msgID
};

class MessageHandler : public QObject
{
    Q_OBJECT
public:
    explicit MessageHandler(QObject *parent = nullptr);
    void handleMessage(QByteArray msg);

signals:
    void airspeedReady(QList<float> data);
    void pressureTapReady(QList<double> data);


private:
    void parseAirspeedMessage(QList<QByteArray> *msgList);
    void parsePressureTapMessage(QList<QByteArray> *msgList);

};

#endif // MESSAGEHANDLER_H