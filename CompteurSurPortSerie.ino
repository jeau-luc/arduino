//**********************************************************
//Afficher un compteur sur le port serie de l'IDE ARDUINO
//**********************************************************

//Affectation à la variable t la valeur zéro
int t = 0;

void setup() {
  //Ouvrir le port serie de l'IDE ARDUINO
  Serial.begin(9600);
}

void loop() {
  //Envoyer le calcul sur l'écran de l'IDE ARDUINO
  Serial.print(t);
  //Ajouter 1 à la variable t
  t++;
  //Attendre 500 milisecondes soit une demi seconde
  delay(100);

}
