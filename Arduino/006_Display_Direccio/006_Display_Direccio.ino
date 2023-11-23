/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   23/11/23                                    **
**                          Trobar direcció del display                          **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <Wire.h>

//********** Variables ************************************************************

//********** Setup ****************************************************************
void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

//********** Loop *****************************************************************
void loop() 
{
 byte codigoDeRespuesta, direccion;
 int dispositivosEncontrados = 0;
 Serial.println("\n\nBuscando dispositivos...");

  for (direccion = 1; direccion < 127; direccion++ ) {
    Wire.beginTransmission(direccion);
    codigoDeRespuesta = Wire.endTransmission();

    if (codigoDeRespuesta == 0) {
      Serial.print("Dispositivo encontrado en la dirección 0x");
      if (direccion < 16)
        Serial.print("0");
      Serial.print(direccion, HEX);
       dispositivosEncontrados++;
    }else if (codigoDeRespuesta == 4) {
      Serial.print("Error desconocido en la dirección 0x");
      if (direccion < 16)
        Serial.print("0");
      Serial.println(direccion, HEX);
    }
  }
  if (dispositivosEncontrados == 0) Serial.println("No se encontró ningún dispositivo");
  delay(1000);
}

//********** Funcions *************************************************************
