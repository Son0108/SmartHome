#include <16F877A.h>
#include <lcd.h>
#include <dht11.c>
#include <servo.c>

#use RS232(BAUD = 9600,BITS=8,PARITY=N,XMIT=PIN_C6,RCV=PIN_C7)

#FUSES HS
#FUSES NOWDT                   
#FUSES NOBROWNOUT             
#FUSES NOLVP

#use delay(crystal=20000000)
