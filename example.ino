#include <MFRC522WITHUART.h>


#define RST_PIN D7
MFRC522WITHUART mfrc522( RST_PIN, &Serial);
void ShowReaderDetails();
void dump_byte_array(byte *buffer, byte bufferSize);
void setup() {
  Serial1.begin(9600, SERIAL_8N1, SERIAL_TX_ONLY, 1);
  Serial.begin(9600);

  delay(5000);
 
 // Serial.print("test serial 1");
  mfrc522.PCD_Init();   // Init MFRC522
  ShowReaderDetails();  // Show details of PCD - MFRC522 Card Reader details
  Serial1.println(F("Scan PICC to see UID, type, and data blocks..."));


  
//
}

void loop() { 
  delay(50);
//  // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
      
      return;
    }
  Serial1.println("NewCardPresent");
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      Serial1.println("could not read serial");
      return;
    }
  Serial1.println("ReadCardSerial");
    // Dump debug info about the card; PICC_HaltA() is automatically called
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
 Serial1.print(F("Card UID:"));
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  mfrc522.PCD_PerformSelfTest();
// // Serial1.println("Hello World");
// 
}

void ShowReaderDetails() {
  // Get the MFRC522 software version
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial1.print(F("MFRC522 Software Version: 0x"));
  Serial1.print(v, HEX);
  if (v == 0x91)
    Serial1.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial1.print(F(" = v2.0"));
  else
    Serial1.print(F(" (unknown)"));
  Serial1.println("");
  // When 0x00 or 0xFF is returned, communication probably failed
  if ((v == 0x00) || (v == 0xFF)) {
    Serial1.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}
void dump_byte_array(byte *buffer, byte bufferSize) {
  //Serial1.print(bufferSize);
  for (byte i = 0; i < bufferSize; i++) {
    Serial1.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial1.print(buffer[i], HEX);
  }
}

