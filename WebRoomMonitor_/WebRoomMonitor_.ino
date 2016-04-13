//Utilitzem la llibreria que instal·la per defecte SoftwareSerial.h//
#include <SoftwareSerial.h>
 
//configurem els ports digitals 4 i 5 com a TX i RX respectivament//
SoftwareSerial RFID = SoftwareSerial(4,5); 
 
//definim les variables//
char caracter;
String llegir_id;
 
void setup()
{
  Serial.begin(9600);
  RFID.begin(9600);
}
 
void loop(){
 
  while(RFID.available()>0)
  {
      caracter = RFID.read();
      llegir_id += caracter;
  }
 
  if (llegir_id.length() > 10) {
      llegir_id = llegir_id.substring(1,11);
      Serial.println(llegir_id);
      //our_id = "";
  }
  delay(1000);
}
