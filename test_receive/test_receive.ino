#include <SoftwareSerial.h>

#define RxPin 5
#define TxPin 6

// Inter-module serial port:
//  facilitates communication between transcievers
SoftwareSerial softSerial(RxPin, TxPin);

unsigned char byteRead;
unsigned char oldByteRead;

unsigned int pktNum;

void setup() {
  // Initialize the debug serial console
  Serial.begin(9600);

  // Initialize the inter-module serial port to 9600 baud
  //   to begin communicating with the other transciever
  softSerial.begin(9600);

  // Instruct the serial port begin listening for incoming data
  softSerial.listen();

  // Initialize our data variables to 0
  byteRead = 0;
  oldByteRead = 0;

  Serial.println("Beginning Process");
  pktNum = 0;
}

void loop() {

  if (softSerial.available()) {
    byteRead = softSerial.read();

    //if(byteRead != oldByteRead) {
    //oldByteRead = byteRead;
    Serial.print("Frame (");
    Serial.print(pktNum);
    Serial.print("): ");
    Serial.println(byteRead, HEX);
    pktNum++;
  }

  delay(10);


  //softSerial.print("Hello World!");
  //Serial.println("Print Complete.");

  //delay(1000);
}
