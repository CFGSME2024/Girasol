/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   23/11/23                                    **
**                   Provar si funciona i2c escribint un missatge                **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <LiquidCrystal_I2C.h>

//********** Variables ************************************************************

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

//********** Setup ****************************************************************
void setup()
{
  lcd.begin();
  lcd.clear();         
  lcd.backlight();      
  
  
  lcd.setCursor(2,0);   
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);   
  lcd.print("LCD Tutorial");
}

//********** Loop *****************************************************************
void loop() {
}

//********** Funcions *************************************************************
