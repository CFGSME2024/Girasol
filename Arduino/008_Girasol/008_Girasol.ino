/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   23/11/23                                    **
**                         Programa complet del girasol                          **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

//********** Variables ************************************************************
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
Servo myservo; 

int pos=90; //variable per emmagatzemar la variable del servo log 6
int esquerra=0; //Valor llegit del LDR esquerra
int dreta=0;  //Valor llegit del LDR dreta
float Tensio=0;
const int LDREsquerra=15; //Fotoresistencia pin analogico 1 de arduino
const int LDRDret=14;
const int LedDret=2; //definim led 1 al pin 2
const int LedCentral=3; 
const int LedEsquerra=4; 
const int ServoMotor=9;
const int Placa=A2;
int Valor_Placa;

//********** Setup ****************************************************************
void setup() 
{
  Serial.begin(9600);
  myservo.attach(ServoMotor);
  myservo.write(pos);
  pinMode (LedDret,OUTPUT);
  pinMode (LedCentral,OUTPUT);
  pinMode (LedEsquerra,OUTPUT);
  pinMode (Placa,INPUT);
  pinMode(LDREsquerra,INPUT);
  pinMode(LDRDret,INPUT);
  lcd.begin();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on 
}

//********** Loop *****************************************************************
void loop() 
{
  Valor_Placa=analogRead(Placa);
  Tensio=(Valor_Placa*5.0)/1023;
  //llegeix el valor dels LDR
  esquerra=analogRead(LDREsquerra)+220;
  dreta=analogRead(LDRDret);
  Serial.print(esquerra);
  Serial.print("    ");
  Serial.println(dreta);
  //Comproba que la dreta sigui mayor que la esquerra,si es aixi moure a la dreta
  // Print a message on both lines of the LCD.
  lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print(esquerra);
  lcd.setCursor(7,0);
  lcd.print(pos);
  lcd.setCursor(12,0);   //Move cursor to character 2 on line 1
  lcd.print(dreta);
  lcd.setCursor(0,1);
  lcd.print(Tensio);

if (esquerra >(dreta +30))
{
  digitalWrite(LedDret,HIGH);
  digitalWrite(LedCentral,LOW);
  digitalWrite(LedEsquerra,LOW);
  delay(20);
  if (pos < 179)
 {
  pos=pos+1;
 }
 myservo.write(pos);
}
//comproba que la esquerra sigui mayor que la dreta, si es aixi moure a la esquerra
else if(dreta > (esquerra +30))
{
  digitalWrite(LedEsquerra,HIGH);
  digitalWrite(LedCentral,LOW);
  digitalWrite(LedDret,LOW);
  delay(20);
  if (pos > 1)
  { 
    pos=pos-1;
  }
  myservo.write(pos);
}
else
{
  digitalWrite(LedCentral,HIGH);
  digitalWrite(LedEsquerra,LOW);
  digitalWrite(LedDret,LOW);
  delay(20);
} }

//********** Funcions *************************************************************