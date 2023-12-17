//*****************************************************************************
//Dans ce projet, nous faisons une éclairage de nuit (interupteur crépusculaire).
//Nous utilisons un potentiomètre sur les broches A0 pour réglé la sensibilité 
// de la celulle (photorésistance). Une photo résistance pour mesurer la lumière
// et une LED sur la broche 2 de l'ARDUINO UNO
//Nous montons une LED qui va s'allumer selon la luminosité sur la photorésistance
// Le réglage de la sensibilité fait à l'aide d'un potentiomètre.
// Formule :
// R = 500/L 
// avec R = résistance de la photoristance (en KOhm).
//      L = éclairement (en lux).
//*****************************************************************************

int POT = A0;
int LDR = A2;
int LED1 = 2;
int LIGHT, THRESHOLD;

void setup() {
  pinMode(LED1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Affecter la valeur lu sur l'entrée du potentiométre à la variable THRESHOLD
  THRESHOLD = analogRead(POT);
  // Affecter la valeur lu sur l'entrée du de la photorésistance à la variable LIGHT
  LIGHT = analogRead(LDR);

  // Si la valeur de la photorésistance et inférieur à la valeur du potentiométre 
  // alumer la LED1
  if (LIGHT < THRESHOLD) {
    digitalWrite(LED1, HIGH);
  }

  // Si la valeur de la photorésistance et supperieur à la valeur du potentiométre 
  // alumer la LED1
   if (LIGHT > THRESHOLD + 10) {
    digitalWrite(LED1, LOW);
  }

  
  Serial.print(THRESHOLD);
  Serial.print(" ");
  Serial.println(LIGHT);
  delay(500);
}
