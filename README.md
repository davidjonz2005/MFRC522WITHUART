# MFRC522WITHUART
a library to use mfrc522 with uart in esp8266 .

#how to use it
first add the .cpp and.h file to your library in arduino IDE. then creat a MFRC522WITHUARTinstance in main.c

then you can use thelibrary.
this is a library based on 
https://github.com/miguelbalboa/rfid
I justchanged writeregister and read register plus a little init functionremained untouched
I tested itmyself and I can read serial from Tag
