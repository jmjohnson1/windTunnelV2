#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include <QDebug>

#define AIRSPEED_MSG_LENGTH 3
#define PRESSURETAP_MSG_LENGTH 21

enum msgID_enum {
    airspeed_msgID = 2,
    pressureTap_msgID = 1
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
