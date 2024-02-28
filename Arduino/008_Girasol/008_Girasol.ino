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
LiquidCrystal_I2C lcd(0x27,16,2);  //Definimos la direccion del display, en este caso se encuentra en 0x27,este LCD son 16 segmentos i 2 filas.

Servo myservo; //Variable para controlar el servo 
int pos=90; //Variable para almacenar la posicion del servomotor, lo iniciamos en 90º 
int esquerra=0; //Variable para almacenar el valor del LDR izq
int dreta=0;  //Variable para almacenar el valor del LDR derecha
int Valor_Placa; //Variable para almacenar el valor de la placa solar
float Tensio=0; //El float para admitir los decimales
const int LDREsquerra=A1; //LDR I pin analogico 1 de arduino, añadimos el const para que su valor no se pueda cambiar
const int LDRDret=A0; //LDR D pin analogico 0 de arduino
const int LedDret=2; //Definimos led al pin 2
const int LedCentral=3; //Definimos led al pin 3
const int LedEsquerra=5; //Definimos led al pin 5
const int Buzzer=8; //Definimos el Buzzer al pin 8
const int ServoMotor=9; //Definimos el servo al pin 9
const int Placa=A2; //Definimos placa solar al pin 2

//********** Setup ****************************************************************
void setup() 
{
  Serial.begin(9600); //Iniziamos el monitor serie 
  myservo.attach(ServoMotor); // Iniziamos el servo para que empiece a trabajar
  myservo.write(pos); //Escribimos el valor de la variable en el servo
  pinMode (LedDret,OUTPUT); //Añadimos el led derecho como salida
  pinMode (LedCentral,OUTPUT); //Añadimos el led central como salida
  pinMode (LedEsquerra,OUTPUT); //Añadimos el led izquierda como salida
  pinMode (Buzzer,OUTPUT); //Añadimos el Buzzer como salida
  pinMode (Placa,INPUT); //Añadimos la Placa como entrada
  pinMode(LDREsquerra,INPUT); //Añadimos el LDR como entrada
  pinMode(LDRDret,INPUT); //Añadimos el LDR como entrada
  lcd.begin(); //Establece las dimensiones de la pantalla LCD
  lcd.clear(); //Limpiamos pantalla   
  lcd.backlight(); //Enciende la luz del fondo del LCD
}

//********** Loop *****************************************************************
void loop() 
{
  Valor_Placa=analogRead(Placa); //Lee el valor de la placa i asignalo a la variable
  Tensio=(Valor_Placa*5.0)/1023; //Hacemos una operación para convertir el valor analogico, en tension
  esquerra=analogRead(LDREsquerra); //Lee el valor del LDR i asignalo a la variable
  dreta=analogRead(LDRDret); //Lee el valor del LDR i asignalo a la variable
  Serial.print(esquerra); //Escribe el valor de LDR izquierda
  Serial.print("    "); //Espacio
  Serial.println(dreta); //Escribe el valor de LDR derecha
  lcd.clear(); //Limpia la pantalla
  lcd.setCursor(0,0); //Establezca el cursor en el carácter 0 de la línea 0
  lcd.print(esquerra); //Muestra el valor del LDR Izquierdo
  lcd.setCursor(7,0); //Establezca el cursor en el carácter 7 de la línea 0
  lcd.print(pos); //Muestra la posición del servo
  lcd.setCursor(12,0); //Establezca el cursor en el carácter 12 de la línea 0
  lcd.print(dreta); //Muestra el valor del LDR Derecho
  lcd.setCursor(0,1); //Establezca el cursor en el carácter 0 de la línea 1
  lcd.print(Tensio); //Muestra el valor de la tensión absorbida de la célula solar

if (esquerra >(dreta +30)) //Si izquierda es mas grande que derecha +30 (Un poco de margen por si varían el valor de los LDR).   
{
  digitalWrite(LedDret,HIGH); //Enciende el led derecho
  digitalWrite(LedCentral,LOW); //Apaga el led central
  digitalWrite(LedEsquerra,LOW); //Apaga el led izquierda
  delay(20); //Espera 20ms
  if (pos < 179) //Si la posición del servo es mas pequeña a 179 grados
 {
  pos=pos+1; //Suma uno a la posición del servo
  digitalWrite(Buzzer,HIGH); //Enciende el buzzer
 }
  myservo.write(pos); //Dale el valor de la variable, al servo
}

else if(dreta > (esquerra +30)) //Sino i sí la izquierda és mayor que la derecha
{
  digitalWrite(LedEsquerra,HIGH); //Enciende el led izquierdo
  digitalWrite(LedCentral,LOW); //Apaga el led central
  digitalWrite(LedDret,LOW); //Apaga el led derecho
  delay(20); //Espera 20ms
  if (pos > 1) //Si la posición es mas grande que 1 grado
  { 
    pos=pos-1; //Resta 1 a la posición del servo
    digitalWrite(Buzzer,HIGH); //Enciende el buzzer
  }
  myservo.write(pos); //Dale el valor de la variable, al servo
}
else //Sino
{
  digitalWrite(LedCentral,HIGH); //Enciende el led central
  digitalWrite(LedEsquerra,LOW); //Apaga el led izquierda
  digitalWrite(LedDret,LOW); //Apaga el led derecho
  delay(20); //Espera 20ms
  digitalWrite(Buzzer,LOW); //Apaga el buzzer 
} }

//********** Funcions *************************************************************