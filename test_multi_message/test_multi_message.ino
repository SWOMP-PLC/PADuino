#include <SoftwareSerial.h>


#define RxPin 5
#define TxPin 6

// Delay between transmissions (milliseconds)
#define TRANS_DELAY 1000 

// Inter-module serial port:
//  facilitates communication between transcievers
SoftwareSerial softSerial(RxPin, TxPin);

//const char* msg = "Fiona";

int sendMessage(const char* msg) {
  int bytesSent;
  int msgSize = strlen(msg);
  int packetSize = strlen(msg) + 1;

  Serial.print("\nSending message:"); 
  Serial.print(msg);
  Serial.print(" (");
  Serial.print(msgSize);
  Serial.print(" characters): ");

  softSerial.write(packetSize);
  delay(100);

  for(int i = 0; i < msgSize; i++) {
    // Transmit the next character in the string
    bytesSent = softSerial.write(msg[i]); 
    Serial.print(msg[i]); // Print transmitted character to the console
    delay(100); // Wait 100ms before sending the next character
    
    // When sending more than 10 characters at a time, a delay must be
    //  added to avoid overwhelming the receiver's buffer 
    // The following line simply delays for 200ms every 10 characters 
    if ( (i > 0) && ((i % 10) == 0) ) { delay(200); }
  }
  

  // Wait some amount of time before sending another message
  delay(TRANS_DELAY);  
}

void setup() {
  // Initialize the debug serial console
  Serial.begin(9600);
  
  // Initialize the inter-module serial port to 9600 baud 
  //   to begin communicating with the other transciever
  softSerial.begin(9600);

}

void loop() {

  sendMessage("Shrek");

  sendMessage("Fiona");

  sendMessage("Donkey");

  sendMessage("Gingy");

  sendMessage("Lord Farquad");

  sendMessage("Smash Mouth");

  sendMessage("Far, Far Away Land");
  //sendMessage("Far, Far"); 
  //sendMessage("Away Land");

  //delay(1000);  // wait 1 second before attempting to send another frame

}
