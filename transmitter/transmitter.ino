#include<SoftwareSerial.h>
#include<string.h>
int tx=4,rx=3;
String str,en_str,q;
int d;
SoftwareSerial xbee=SoftwareSerial(rx,tx);             //for serial communication

void setup() 
{
 Serial.begin(9600);
 xbee.begin(9600);
 Serial.println("Hi\nWelcome to the introduction of data transmittion...\n");
 Serial.println("Enter the data to encrypted and transmitted\n");
}

void loop() 
{
 while(Serial.available()>0)
 {
  str=Serial.readString();
  d=str.length();                                 //length of string   
             
  for(int i=0;i<d;i++)
  {
    char a=str[i]+i;                                   //encryption
    
    Serial.print(str[i]);
    Serial.print(" encoded ");
    Serial.println(a);
    en_str+=a;                                    //encrypted string
  }
  Serial.print("The original message is ::: ");
  Serial.println(str);
  Serial.print("The encoded data is ::: ");
  Serial.println(en_str);
  xbee.print(en_str);                                  //data transmitted
  en_str="";
 }
  
 
}
