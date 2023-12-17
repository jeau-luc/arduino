//*****************************************************************************
//Dans ce projet, nous faisons un commutateur (bascule).
//Nous utilisons un bouton poussoir sur la broche 8 de l'ARDUINO UNO
// et une LED sur la broche 2 de l'ARDUINO UNO
//A chaque activation du bouton poussoir alumons ou éteignons
//*****************************************************************************

//Affecter à la variable LED1 la broche 2 de l'ARDUINO UNO
//Affectation à la variable BUTTON1 la broche 8 de l'ARDUINO UNO
//Affectation à la variable STATE l'état faux
int LED1 = 2, BUTTON1 = 8, STATE = false;

void setup() {
  //Décalation de la broche 2 en sortie pour le LED1
  pinMode(LED1, OUTPUT);
    
  //Décalation de la broche 8 en sortie pour le BUTTON1
  pinMode(BUTTON1, INPUT);

}

void loop() {
  // A chaque appuie sur le bouton poussoir BUTTON1 alumons ou éteignons la LED1
  if (digitalRead(BUTTON1) == HIGH) {
    // ON chage l'état de la variable STATE
    STATE =!STATE;
    digitalWrite(LED1, STATE);
    
    while (digitalRead(BUTTON1) == HIGH){
      // Vérification de l'anti-rebon du bouton poussoir
      delay(20);
    }
  }
}
