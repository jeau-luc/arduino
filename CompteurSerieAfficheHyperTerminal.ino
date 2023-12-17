int t;

void setup() {
  
  Serial.begin(9600);
  
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  
  // Faire apparaitre le curseur
  Serial.print("[?25l");
}

void loop() {
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  // Déplacer le curseur à la pousition 10 en x et 20 en y
  Serial.print("[10;20H");
  // Ecrire le texte ci-dessous et la variable t
  Serial.print("La variable t est maintemant : ");
  Serial.print(t);
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  // Déplacer le curseur à la pousition 11 en x et 25 en y
  Serial.print("[11;25H");
   // Ecrire le texte ci-dessous et la variable t
  Serial.print("La Compteur t est maintemant : ");
  Serial.print(t);
  
  t++;
  delay(500);
 }
