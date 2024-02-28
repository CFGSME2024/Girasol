/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   23/11/23                                    **
**                         Programa complet del girasol                          **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <Servo.h>

//********** Variables ************************************************************
Servo myservo; 

int pos=90; //variable per emmagatzemar la variable del servo log 6
int esquerra=0; //Valor llegit del LDR esquerra
int dreta=0;  //Valor llegit del LDR dreta
const int LDREsquerra=15; //Fotoresistencia pin analogico 1 de arduino
const int LDRDret=14;
const int ServoMotor=9;
const int Buzzer=8;


//********** Setup ****************************************************************
void setup() 
{
  Serial.begin(9600);
  myservo.attach(ServoMotor);
  myservo.write(pos);
  pinMode(LDREsquerra,INPUT);
  pinMode(LDRDret,INPUT);    // Make sure backlight is on 
  pinMode(Buzzer,OUTPUT);
}

//********** Loop *****************************************************************
void loop() 
{
  //llegeix el valor dels LDR
  esquerra=analogRead(LDREsquerra)+220; //Sumamos 220 para igualar el valor de los LDR
  dreta=analogRead(LDRDret);
  Serial.print(esquerra);
  Serial.print("    ");
  Serial.println(dreta);


if (esquerra >(dreta +30))
{
  if (pos < 179)
 {
  pos=pos+1;
  digitalWrite(Buzzer,HIGH);
 }
 myservo.write(pos);
}
//comproba que la esquerra sigui mayor que la dreta, si es aixi moure a la esquerra
else if(dreta > (esquerra +30))
{
  if (pos > 1)
  { 
    pos=pos-1;
    digitalWrite(Buzzer,HIGH);
  }
  myservo.write(pos);
}
else
{
  digitalWrite(Buzzer,LOW);
  delay(20);
} }

//********** Funcions *************************************************************
