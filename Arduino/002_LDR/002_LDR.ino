/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   22/11/23                                    **
**                   Prova LDR i ajustar l'OFFSET de llum entre ells             **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int LDRizquierdo=A1; //Fotoresistencia pin analogico 1 de arduino
const int LDRderecho=A0;
int izquierda=0; //Valor llegit del LDR esquerra
int derecha=0;  //Valor llegit del LDR dreta

//********** Setup ****************************************************************
void setup()
{
  pinMode(LDRizquierdo,INPUT);
  pinMode(LDRderecho,INPUT);
  Serial.begin(9600);
}

//********** Loop *****************************************************************
void loop()
{
  izquierda=analogRead(LDRizquierdo)+420;
  derecha=analogRead(LDRderecho);
  Serial.print("I:");
  Serial.print(izquierda);
  Serial.print("    D:");
  Serial.println(derecha);
  delay(200);
}

//********** Funcions *************************************************************