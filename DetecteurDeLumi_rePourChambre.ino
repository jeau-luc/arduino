//*****************************************************************************
//Dans ce projet, nous allons fabriquer un détecteur de lumière pour chambre 
// d'enfant, le montage doit détecter les changements abrupts de luminosité
// dans la pièce. Nous mesurons la luminosité pour la comparer avec la mesure 
// précédente qui sert à chaque fois de valeur de seuil.
// Une photorésistance pour mesurer la lumière à comparer.
//
//Nous montons la photorésistance avec résistance 10KOhm en pont diviseur
// brancheé sur l'entrée analogique A2.
//D'une led LED1 sur la sortie 2 et un bouton BUTTON1 sur l'entrée 8 de 
// l'Arduino
//*****************************************************************************


int LRD = A2;
int LED1 = 2;
int BUTTON1 = 8;
int THRESHOLD = 1023, VALUE;

void setup() {
  
  Serial.begin(9600);
  pinMode(BUTTON1, INPUT);
  pinMode(LED1, OUTPUT);  
  
}

void loop() {
  
  VALUE = analogRead(LRD);
  
  if (VALUE > THRESHOLD + 20){
    digitalWrite(LED1, HIGH);
  }

  THRESHOLD = VALUE;

   if (digitalRead(BUTTON1) == HIGH){
    digitalWrite(LED1, LOW);
  }
  delay(500);
  
}
