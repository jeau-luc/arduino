//*****************************************************************************
//Dans ce projet, nous faisons une sonnerie avec code d'autorisation.
//Nous utilisons deux boutons poussoirs sur les broches 8 et 11 de l'ARDUINO UNO
// et une LED sur la broche 2 de l'ARDUINO UNO
//Pour activation la sonnerie, il convient de saisir un code de quatre chiffre
// dans un bonne ordre.
//Nous définissons un tableau pour le code d'autorisation 1-1-2-2, 
//*****************************************************************************

//tableau qui réceptionne le code qui provient des boutons poussoirs 
int BELL[4];
// le code à trouver pour la sonnerie
int CODE[]={1,1,2,2};
//Affectation à la variable BUTTON1 la broche 8 de l'ARDUINO UNO
int BUTTON1 = 8;
//Affectation à la variable BUTTON1 la broche 8 de l'ARDUINO UNO
int BUTTON2 = 11;
//Affecter à la variable LED1 la broche 2 de l'ARDUINO UNO
int LED1 = 2;
//Déclaration des variables CORRECT pour valider le code correcte
//Déclaration des variables CORRECT pour la pression sur d'un bouton
int CORRECT, PRESSEDS;

void setup() {
   //Décalation de la broche 2 en sortie pour le LED1
  pinMode(LED1, OUTPUT);
    
  //Décalation de la broche 8 en sortie pour le BUTTON1
  pinMode(BUTTON1, INPUT);

  //Décalation de la broche 11 en sortie pour le BUTTON2
  pinMode(BUTTON2, INPUT);
}

void loop() {
  // Check the bottons
  PRESSEDS=0;

  if (digitalRead(BUTTON1) == HIGH) {
    PRESSEDS=1;
  }

  if (digitalRead(BUTTON2) == HIGH) {
    PRESSEDS=2;
  }
  
  if (PRESSEDS!=0) {
  
    //Antirebondissement
    while ((digitalRead(BUTTON1) == HIGH) or (digitalRead(BUTTON2) == HIGH)){
        // Vérification de l'anti-rebon du bouton poussoir
        delay(20);
      }
      
    //Déplacement
    for (int t=0; t<3; t++){
      BELL[t] = BELL[t+1];
    }
    BELL[3] = PRESSEDS;
  
    //Comparaison
    CORRECT = 0;
    for (int t=0; t<4; t++){
      if (BELL[t] == CODE[t]){
          CORRECT++;
       }
    }
    //Contrôle de code
    if (CORRECT==4){
      digitalWrite(LED1, HIGH);
      delay(1000);
      digitalWrite(LED1, LOW);
    }
   }
  
}
