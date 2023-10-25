#include <Servo.h>
Servo myservo; 
int pos=90; //variable per emmagatzemar la variable del servo log 6
int LDRizquierdo=1; //Fotoresistencia pin analogico 1 de arduino
int LDRderecho=0;
int izquierda=0; //Valor llegit del LDR esquerra
int derecha=0;  //Valor llegit del LDR dreta

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
//llegeix el valor dels LDR
izquierda=analogRead(LDRizquierdo);
derecha=analogRead(LDRderecho);
Serial.println(izquierda);
Serial.println(derecha);
//Comproba que la dreta sigui mayor que la esquerra,si es aixi moure a la dreta
if (izquierda >(derecha +110))
{if (pos < 179)
delay(200);
 {
  pos=pos+1;
 }
 myservo.write(pos);
}
//comproba que la esquerra sigui mayor que la dreta, si es aixi moure a la esquerra
if(derecha > (izquierda +110))
{
  if (pos>1)
  delay(200);
  {
    pos=pos-1;
  }
  myservo.write(pos);
}} 
