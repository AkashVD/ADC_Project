#include<SoftwareSerial.h>
#include<string.h>
int tx=4,rx=3,i=0;            
String de_str,raw;
char str;
SoftwareSerial xbee=SoftwareSerial(rx,tx);             //For serial communication

void setup() 
{
 Serial.begin(9600);
 xbee.begin(9600);
 Serial.println("Decryption of transmitted data\n");
 Serial.println("Starting the receiver\n");
}

void loop() 
{
if(xbee.available()>0)
{
 while(xbee.available()>0)
 {
  str=xbee.read();
  Serial.println(str);
  char a = str - i;              //Decryption procedure 
  raw+=str;                     //Encrypted string                                      
  de_str+=a;                   //Decrypted string                                  
  i++;                                                           
 }
Serial.print("The raw data recived from the transmitter is :::");
Serial.println(raw);
Serial.print("The decrypted data recived from the transmitter is :::");
Serial.println(de_str);
i=0;
de_str="";
}
}
