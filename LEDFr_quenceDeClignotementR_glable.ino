//*****************************************************************************
//Dans ce projet, nous faisons une LED à fréquence de clignotement réglable.
//Nous utilisons un potentiomètre sur les broches A0 de l'ARDUINO UNO
// et une LED sur la broche 2 de l'ARDUINO UNO
//Nous montons une LED dont la fréquence de clignotement sera réglée à l'aide 
// d'un potentiomètre.
//*****************************************************************************

int POT = A0;
int LED1 = 2;
int STATE = false;
int VALUE;
int TEMPS; 


void setup() {

  //Ouvrir le port serie de l'IDE ARDUINO
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);

}

void loop() {
  VALUE = analogRead(POT);
  TEMPS = VALUE+50;
  digitalWrite(LED1, STATE);
  STATE=!STATE;
  delay(analogRead(TEMPS));
  Serial.print("Période de clignotement est ");
  Serial.print(TEMPS);
  Serial.println(" millisecondes");

}
