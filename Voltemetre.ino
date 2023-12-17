//*****************************************************************************
//Dans ce projet, nous faisons un voltemètre.
//Nous utilisons un potentiomètre sur les broches A0 de l'ARDUINO UNO
// et une LED sur la broche 2 de l'ARDUINO UNO
// Nous mesurans la tension appliquée à la broche A0 pour ensuite l'afficher 
// à l'écran de l'ordinateur.
//*****************************************************************************

int POT = A0;
int LED1 = 2;
int VALUE;
float VOLTAGE; 


void setup() {

  //Ouvrir le port serie de l'IDE ARDUINO
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);

  //La suite de commandes ci-dessous rend le curseur invisble
  //*********************************************************
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  
  // Faire disparaitre le curseur
  Serial.print("[?25l");
  //*********************************************************
}

void loop() {
  
  VALUE = analogRead(POT);
  VOLTAGE = (VALUE*5.0/1023);

  //Mesure
    Serial.write(27);
    Serial.print("[2;5H");
    Serial.print("Mesure ");
    Serial.print(VALUE);
    Serial.print(" unitées   ");
    
//Tension
    Serial.write(27);
    Serial.print("[4;5H");
    Serial.print("Tension ");
    Serial.print(VOLTAGE);
    Serial.print( " V   ");

//Barre de tension
    Serial.write(27);
    Serial.print("[6;5H");
    for (int t=0; t<VALUE/50; t++){
      Serial.print("##");
    }
    for (int t = VALUE/50; t<=1023/50; t++){
      Serial.print(" ");
    }
    delay(500);
}
