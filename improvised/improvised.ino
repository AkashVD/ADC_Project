#include<SoftwareSerial.h>
#include<string.h>
int tx=4,rx=3,i=0;
String st,en_str,raw,de_str;
int d;
char str;
SoftwareSerial xbee=SoftwareSerial(rx,tx);             //for serial communication

void setup() 
{
 Serial.begin(9600);
 xbee.begin(9600);
 Serial.println("Hi\nWelcome to the introduction of data transmitting and reciving...\n");
 Serial.println("Enter the data to encrypted and transmitted\n");
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


 while(Serial.available()>0)
 {
  st=Serial.readString();
  d=st.length();                                 //length of string   
             
  for(int j=0;j<d;j++)
  {
    char a=st[j]+j;                                   //encryption
    
    Serial.print(st[j]);
    Serial.print(" encoded ");
    Serial.println(a);
    en_str+=a;                                    //encrypted string
  }
  Serial.print("The original message is ::: ");
  Serial.println(st);
  Serial.print("The encoded data is ::: ");
  Serial.println(en_str);
  xbee.print(en_str);                                  //data transmitted
  en_str="";
 }
 
}
