//*****************************************************************************
//Dans ce projet, nous allons fabriquer un luxmétre simple et fare afficher à
// l'écran de l'ordinateur la luminosité mesurée, en nous servant de l'HyperTerminal. 
// de la celulle (photorésistance). Une photo résistance pour mesurer la lumière
//Nous montons la photorésistance avec résistance 10KOhm en pot diviseur
// Formules :
// R = 500/L 
// L = 1 800 000/R
// avec R = résistance de la photoristance (en KOhm).
//      L = éclairement (en lux).
// L = 1800/((10 230/AD)-10)
// avec AD la mesure analogique présente un résultat compris entre 0 et 1023.
//  1 023 correspond à la valeur +5V.
//*****************************************************************************

int LDR = A2;
int AD;
float L;

void setup() {
  Serial.begin(9600);
  
   //La suite de commandes ci-dessous rend le curseur invisble
  //*********************************************************
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  
  // Faire disparaitre le curseur
  Serial.print("[?25l");
  //*********************************************************
}

void loop() {
  //Mesurer et calculer
  AD = analogRead(LDR);
  L = 10230.0 / AD;
  L = L - 10;
  L = 1800 / L;

  //Display
  
  Serial.write(27);
  Serial.print("[3;5H");
  Serial.print("Mesure analogique ");
  Serial.print(AD);
  
  Serial.write(27);
  Serial.print("[4;5H");
  Serial.print("Intensité lumineuse ");
  Serial.print(L);
  Serial.print(" lux    ");
  delay(500);
}
