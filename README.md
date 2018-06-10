# MFRC522WITHUART
a library to use mfrc522 with uart in esp8266 or arduino .

# how to use it

first add the .cpp and .h file to your library in arduino IDE. then create a MFRC522WITHUART instance in main.c
then you can use the library.

I used https://github.com/miguelbalboa/rfid ,however, I just changed writeregister and read register plus a little init function but other parts remained untouched
I tested it myself and I can read serial from Tag

# baudrate

I tested the reader module and found out that this module could not read Tag serial with baud rate less than 14400 
currently i setup baud rate to 115200 but if you want to change it you have to modify the .cpp file in line 234,235 and 267,268
based on Mfrc522 datasheet section 8.1.3.2

PCD_WriteRegister(SerialSpeedReg, 0x7A);

_serialClass->begin(115200);

