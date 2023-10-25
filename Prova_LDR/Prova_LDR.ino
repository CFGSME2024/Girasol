int LDRizquierdo=A1; //Fotoresistencia pin analogico 1 de arduino
int LDRderecho=A0;
int izquierda=0; //Valor llegit del LDR esquerra
int derecha=0;  //Valor llegit del LDR dreta

void setup() {
pinMode(LDR,INPUT);
pinMode(LDR2,INPUT);
Serial.Beginln(9600);

}

void loop() {
izquierda=analogRead(LDRizquierdo)+320;
derecha=analogRead(LDRderecho);
Serial.print(izquierda);
Serial.print("    ");
Serial.println(derecha);


}
