//***********************************************************************
//Dans ce projet, nous faisons clignoter deux LED en altenance.
//Nous utilisons l'opérateur NOT pour changer le l'état de l'éclairage 
//des LED
//***********************************************************************

//Affecter à la variable LED1 la broche 2 et LED2 broche 5 de l'ARDUINO UNO
//Affectation à la variable state (état) la valeur haute (1 logique)
int LED1 = 2, LED2 = 5, state = HIGH;

void setup() {
  //Décalation de la broche 2 en sortie pour le LED1
  pinMode(LED1, OUTPUT);
    
  //Décalation de la broche 5 en sortie pour le LED2
  pinMode(LED2, OUTPUT);

}

void loop() {
  //Etat de la variable state (état) pour la LED1
  digitalWrite(LED1, state);
  //L'opérateur NOT (!) inverse état de la variable state (état) pour la LED2
  digitalWrite(LED2, !state);
  //Attendre 500 milisecondes soit une demi seconde
  delay(500);
  //Change l'état de la variable state (état)
  state=!state;

}
