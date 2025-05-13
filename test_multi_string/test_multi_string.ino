#include <SoftwareSerial.h>
#include <string.h>

#define RxPin 5
#define TxPin 6

// Delay between transmissions (milliseconds)
#define TRANS_DELAY 1000 

#define BYTE_DELAY 100

// Inter-module serial port:
//  facilitates communication between transcievers
SoftwareSerial softSerial(RxPin, TxPin);

int sendMessage(String msg); 


void setup() {
  // Initialize the debug serial console
  Serial.begin(9600);
  
  // Initialize the inter-module serial port to 9600 baud 
  //   to begin communicating with the other transciever
  softSerial.begin(9600);
}


void loop() {
  String stringList[] = {"Shrek", "Fiona", "Donkey", "Gingy", 
                         "Lord Farquad", "Far, Far Away Land"};

  for (int i = 0; i < sizeof(stringList); i++) {
    sendMessage(stringList[i]);
  }
}

int sendMessage(String msg) {
  int msgSize = msg.length();

  Serial.print("\nSending message: " + msg + 
               " (" + msgSize + " characters): ");

  // Message <Total Size> = <Message Size> + 1 (for overhead)
  softSerial.write(msgSize + 1);  // Send <Total Size> as 1st byte
  
  delay(100); // Wait to allow the transciever to prepare the buffer
  
  // Begin transmitting characters in the message
  for(int i = 0; i < msgSize; i++) {
    softSerial.write(msg[i]); // Transmit next character in the string
    Serial.print(msg[i]); // Print transmitted character to the console
    delay(100); // Wait some time before sending the next character
    
    // When sending more than 10 characters at a time, a delay must be
    //  added to avoid overwhelming the receiver's buffer 
    // The following line simply delays for 200ms every 10 characters 
    if ( (i > 0) && ((i % 10) == 0) ) { delay(200); }
  }

  delay(TRANS_DELAY); // Allow some time before sending another message

  return 0;
}
