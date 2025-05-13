#include <SoftwareSerial.h>

#define RxPin 5
#define TxPin 6

// Inter-module serial port:
//  facilitates communication between transcievers
SoftwareSerial softSerial(RxPin, TxPin);

int bytesSent;

const char* msg = "Fiona";



void setup() {
  // Initialize the debug serial console
  Serial.begin(9600);
  
  // Initialize the inter-module serial port to 9600 baud 
  //   to begin communicating with the other transciever
  softSerial.begin(9600);

}

void loop() {
  int msgSize = strlen(msg);
  int packetSize = strlen(msg) + 1;

  //Serial.println("Printing...");  // Debug message
  Serial.print("\nSending message of (");
  Serial.print(msgSize);
  Serial.print(") characters:");

  // Payload size to send to the transmitter
  softSerial.write(packetSize);
  delay(100);

  for(int i = 0; i < msgSize; i++) {
    bytesSent = softSerial.write(msg[i]); // transmit a single character
    
    Serial.print(msg[i]);

    delay(100); // wait 100ms before sending the next character
  }

  /*
  delay(100); // wait 100ms before sending the next character
  bytesSent = softSerial.write("S"); // transmit a single character

  delay(100); // wait 100ms before sending the next character
  bytesSent = softSerial.write("W"); // transmit a single character

  delay(100); // wait 100ms before sending the next character
  bytesSent = softSerial.write("O"); // transmit a single character

  delay(100); // wait 100ms before sending the next character
  bytesSent = softSerial.write("M"); // transmit a single character

  delay(100); // wait 100ms before sending the next character
  bytesSent = softSerial.write("P"); // transmit a single character
  */

  delay(1000);  // wait 1 second before attempting to send another frame

}
