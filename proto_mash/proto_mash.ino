#include <SoftwareSerial.h>

#define RxPin 5
#define TxPin 6

// Inter-module serial port:
//  facilitates communication between transcievers
SoftwareSerial softSerial(RxPin, TxPin);

struct ProtoMash {
  unsigned char address : 8;
  unsigned char     CMD : 8;
  unsigned char payload : 8;
};

char byteRead;
unsigned char oldByteRead;

unsigned char sendByte;

char packets[3];

unsigned int pktIdx = 0;

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

  Serial.print("Beginning Program...");
}

void loop() {
  /*
  sendByte = 2;
  Serial.print("Recieved: ");
  Serial.println(sendByte);
  softSerial.write(sendByte);
  delay(20);

  sendByte = 1;
  Serial.print("Recieved: ");
  Serial.println(sendByte);
  softSerial.write(sendByte);
  delay(20);

  sendByte = 90;
  Serial.print("Recieved: ");
  Serial.println(sendByte);
  softSerial.write(sendByte);
  delay(20);
  */

  
  if (softSerial.available()) {
    byteRead = softSerial.read();

    Serial.print("Recieved: ");
    Serial.println(byteRead);
  
    //packets[pktIdx] = byteRead;

    //pktIdx++;
  } 
  

  delay(10);
}
