# MFRC522WITHUART
a library to use mfrc522 with uart in esp8266 .

#how to use it
first add the .cpp and.h file to your library in arduino IDE. then creat a MFRC522WITHUARTinstance in main.c

then you can use thelibrary.
this is a library based on 
https://github.com/miguelbalboa/rfid
I justchanged writeregister and read register plus a little init functionremained untouched
I tested itmyself and I can read serial from Tag
#baudrate
i tested the reader module and i found out that this module cant read serial with baud rate less than 14400 
currently i setup baud rate to 115200 but if you want to change it you have to change it in line 234,235 and 267,268
based on Mfrc522 datasheet section 8.1.3.2

PCD_WriteRegister(SerialSpeedReg, 0x7A);

_serialClass->begin(115200);

