//***********************************************************************
//Dans ce projet, nous faisons minuteur redéclenchable.
//Nous utilisons un bouton poussoir sur la broche 8 de l'ARDUINO UNO
// et une LED sur la broche 2 de l'ARDUINO UNO
//***********************************************************************

//Affecter à la variable LED1 la broche 2 de l'ARDUINO UNO
//Affectation à la variable BUTTON1 la broche 8 de l'ARDUINO UNO
int LED1 = 2, BUTTON1 = 8;

void setup() {
  //Décalation de la broche 2 en sortie pour le LED1
  pinMode(LED1, OUTPUT);
    
  //Décalation de la broche 8 en sortie pour le BUTTON1
  pinMode(BUTTON1, INPUT);

}

void loop() {
  if (digitalRead(BUTTON1) == HIGH) {
    //Etat de la LED1 à HIGH
    digitalWrite(LED1, HIGH);
    // Eclarage de la LED1 5 secondes
    delay(5000);
    digitalWrite(LED1, LOW);
  }
}
