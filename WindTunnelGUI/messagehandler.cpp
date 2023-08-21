#include "messagehandler.h"

MessageHandler::MessageHandler(QObject *parent)
    : QObject{parent}
{

}

void MessageHandler::handleMessage(QByteArray msg) {
    // Get the message ID
    bool notComma = true;
    int i = 0;
    while(notComma) {
        char
            i++;
    }

    // Call the relevant function to parse
}

void MessageHandler::parseAirspeedMessage(QByteArray *msg) {

}

void MessageHandler::parsePressureTapMessage(QByteArray *msg) {

}
