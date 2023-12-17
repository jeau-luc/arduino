//*********************************************************************
//Le programme fait clignoter une LED sur la broche 2 de l'ARDUINO UNO
//*********************************************************************

//Affecter à la variable LED la broche 2 de l'ARDUINO UNO
int LED = 2;
void setup() {
  //Décalation de la broche 2 en sortie pour le LED
  pinMode(LED, OUTPUT);

}

void loop() {
  //Allumer la LED
  digitalWrite(LED, HIGH);
  //Attendre 1 000 milisecondes soit une seconde
  delay(500);
  //Eteindre la LED
  digitalWrite(LED, LOW);
  //Attendre 1 000 milisecondes soit une seconde
  delay(500);

}
