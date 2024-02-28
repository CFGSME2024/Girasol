/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   23/11/23                                    **
**                                Prova dels leds                                **
**                                                                               **
**********************************************************************************/
//********** Includes *************************************************************

//********** Variables ************************************************************
const int LedDret=2;
const int LedCentral=3; 
const int LedEsquerra=4; 

//********** Setup ****************************************************************
void setup() 
{
  pinMode (LedDret,OUTPUT);
  pinMode (LedCentral,OUTPUT);
  pinMode (LedEsquerra,OUTPUT);

}

//********** Loop *****************************************************************
void loop() 
{
  digitalWrite(LedDret,HIGH);
  digitalWrite(LedCentral,LOW);
  digitalWrite(LedEsquerra,LOW);
  delay(200);

  digitalWrite(LedEsquerra,HIGH);
  digitalWrite(LedCentral,LOW);
  digitalWrite(LedDret,LOW);
  delay(200);
  
  digitalWrite(LedCentral,HIGH);
  digitalWrite(LedEsquerra,LOW);
  digitalWrite(LedDret,LOW);
  delay(200);

}

//********** Funcions *************************************************************
