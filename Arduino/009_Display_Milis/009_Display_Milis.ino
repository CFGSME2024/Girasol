/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   14/12/23                                    **
**                      Prova de funció milis amb display                        **
**                                                                               **
**********************************************************************************/
//********** Includes *************************************************************

#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

//********** Variables ************************************************************

Servo myservo; 

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempoSegundos = 0;

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

void setup() {
  Serial.begin(9600);
  tiempo1 = millis();
  myservo.attach(ServoMotor);
  myservo.write(pos);
  pinMode (LedDret,OUTPUT);
  pinMode (LedCentral,OUTPUT);
  pinMode (LedEsquerra,OUTPUT);
  pinMode (Placa,INPUT);
  pinMode (LDREsquerra,INPUT);
  pinMode (LDRDret,INPUT);
  lcd.begin();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on 
}

//********** Loop *****************************************************************

void loop() {
   Valor_Placa=analogRead(Placa);
  Tensio=(Valor_Placa*5.0)/1023;
  //llegeix el valor dels LDR
  esquerra=analogRead(LDREsquerra)+220;
  dreta=analogRead(LDRDret);
  Serial.print(esquerra);
  Serial.print("    ");
  Serial.println(dreta);
  tiempo2 = millis();
  if(tiempo2 > (tiempo1+1000)){  //Si ha pasado 1 segundo ejecuta el IF
    tiempo1 = millis(); //Actualiza el tiempo actual
    tiempoSegundos = tiempo1/1000;
      lcd.setCursor(0,0);
      lcd.print("Valor LDR E:");
      lcd.print(esquerra);
      lcd.setCursor(0,1);
      lcd.print("Valor LDR D:");
      lcd.print(dreta);
      
  }
    if(tiempo1 > (tiempo2+1000)){
    tiempo1=millis();
    tiempoSegundos=tiempo1/1000;
      lcd.clear();
      lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
      lcd.print("Posicio servo:");
      lcd.print(pos);
      lcd.setCursor(0,1);
      lcd.print("Tensio:");
      lcd.print(Tensio);   //Move cursor to character 2 on line 1
      lcd.print("V");
      
    }
    
  }

//********** Funcions *************************************************************