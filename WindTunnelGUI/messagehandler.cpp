#include "messagehandler.h"

MessageHandler::MessageHandler(QObject *parent)
    : QObject{parent}
{

}

void MessageHandler::handleMessage(QByteArray msg) {
    // Split the message and get the message id
    QList<QByteArray> messageList;
    msg.removeFirst();
    msg.removeLast();
    msg = msg.simplified();
    messageList = msg.split(',');
    // Call the relevant function to parse
    msgID_enum msgID = static_cast<msgID_enum>(messageList[0].toInt());
    switch (msgID) {
    case airspeed_msgID:
        parseAirspeedMessage(&messageList);
        break;
    case pressureTap_msgID:
        parsePressureTapMessage(&messageList);
        break;
    default:
        qDebug() << "Message could not be parsed";
        break;
    }
}

void MessageHandler::parseAirspeedMessage(QList<QByteArray> *msgList) {
    /* Airspeed Message Format:
     * <msgID,airspeed,dynamicPressure_ts>
     * Airspeed is in (m/s)
     * Pressure measurements in Pascals
     * Static pressure comes from the port in the test section
    */
    QList<float> airspeedData;
    airspeedData.append(msgList->at(1).toFloat());
    airspeedData.append(msgList->at(2).toFloat());

    emit airspeedReady(airspeedData);
}

void MessageHandler::parsePressureTapMessage(QList<QByteArray> *msgList) {
    /* Pressure Tap Message Format:
     * <msgID, tap1, tap2, ..., tap20>
     * Pressure measurements in pascals
    */
    QList<double> pressureTapData;
    for (int i = 0; i < 20; ++i) {
        pressureTapData.append(msgList->at(i+1).toFloat());
    }

    emit pressureTapReady(pressureTapData);
}
