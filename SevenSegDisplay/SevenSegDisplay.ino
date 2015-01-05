// Send alphanumeric data to the Sparkfun Serial LED Display (COM-09230) using SPI
// Tested using Arduino Pro Mini w/ ATMega168 @ 5V
// July 21, 2009  - Quazar & Busaboi
// No guarantees expressed or implied just a good starting point
// Based upon the many SPI tutorials on Arduino.cc
//
// "num" specifies the number to display
// "base" specifies the base to use (2-16).
//    Use 2 for binary, 8 for octal, 10 for decimal, or 16 for hex
// "pad" indicates whether leading zeros should be replaced with spaces.
//    pad==0 means spaces ("   0"), pad==1 means zeros ("0000")
//
// Notes: The display's decimal/punctuation indicators are not changed.
// Numbers that don't fit into 4 digits show as " OF " for "Overflow".
// Assumptions: "unsigned short" is assumed to be at least 16b wide.

#define DATAOUT 11 //MOSI
#define DATAIN 12 //MISO - not used, but part of builtin SPI
#define SPICLOCK 13 //sck
#define SLAVESELECT 10 //ss
#define WHI 17 //canary LED
#define BLU 16 //canary LED
#define YEL 15 //canary LED
#define RED 14 //canary LED
#define LED 13 //canary LED
#define SNS 18 //analog temp sensor

void setup()
{
  pinMode(WHI, OUTPUT);  
  pinMode(BLU, OUTPUT); 
  pinMode(YEL, OUTPUT); 
  pinMode(RED, OUTPUT);  
  pinMode(LED, OUTPUT); 
  pinMode(SNS, INPUT); 
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);
  pinMode(SLAVESELECT, OUTPUT);
}

/*+25.0625 0000 0001 1001 0001 0191h 401d
  +10.125  0000 0000 1010 0010 00A2h 162d
  +0.5     0000 0000 0000 1000 0008h   8d
  0        0000 0000 0000 0000 0000h   0d
  -0.5     1111 1111 1111 1000 FFF8h
  -10.125  1111 1111 0101 1110 FF5Eh
  -25.0625 1111 1110 0110 1111 FE6Fh 
*/

void loop(){
  uint16_t temp = analogRead(SNS);
  Serial.print("analog 0 is: ");
  Serial.println(temp);
  if(temp > 0){
    digitalWrite(WHI, HIGH);
  } else {
    digitalWrite(WHI, LOW);
  }
  if(temp > 4){
    digitalWrite(BLU, HIGH);
  } else {
    digitalWrite(BLU, LOW);
  }
  if(temp > 81){
    digitalWrite(YEL, HIGH);
  } else {
    digitalWrite(YEL, LOW);
  }
  if(temp > 200){
    digitalWrite(RED, HIGH);
  } else {
    digitalWrite(RED, LOW);
  }
  digitalWrite(LED, HIGH);
  delay(700);
  digitalWrite(WHI, LOW);
  digitalWrite(BLU, LOW);
  digitalWrite(YEL, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(LED, LOW);
  delay(700);
}
