#include "commands.h"

const byte messageLengthMax = 32;
char receivedMessage[messageLengthMax];
char transmissionStart = '@';
char transmissionEnd = '&';
bool newMessage = 0;


void getMessage() {
	static bool rxInProgress = 0;
	static byte ndx = 0;
	char received;

	while (Serial.available() && !newMessage) {
		received = Serial.read();

		if (rxInProgress) {
			// Check for end of transmission
			if (received != transmissionEnd) {
				receivedMessage[ndx] = received;
				ndx++;
				if (ndx >= messageLengthMax) {
					ndx = messageLengthMax - 1; // Will continue writing last byte if buffer overflow
				}
				else {
					receivedMessage[ndx] = '\0'; // Null terminator
					rxInProgress = 0;
					ndx = 0;
					newMessage = 1;
				}
			}
		}
		else if (received == transmissionStart) {
			rxInProgress = true;
		}
	}
}
