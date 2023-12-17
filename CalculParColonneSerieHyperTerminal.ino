int t=0, a, b, c, dummy;

void setup() {
  // Ouvrir le port serie
  Serial.begin(9600);

}

void loop() {

  // Caculs à effectuer
  a=t+1;
  b=t*5;
  c=3*b-a;

  //Pour la variable t
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  // Déplacer le curseur à la pousition 1 en x et tx8 en y
  Serial.print("[1;"+String(t*8)+"H");
  // Ecrire le texte ci-dessous et la variable t
  Serial.print("t = ");
  Serial.println(t);

  //Pour la variable a
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  // Déplacer le curseur à la pousition 1 en x et tx8 en y
  Serial.print("[2;"+String(t*8)+"H");
  // Ecrire le texte ci-dessous et la variable t
  Serial.print("a = ");
  Serial.println(a);
  
  //Pour la variable b
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  // Déplacer le curseur à la pousition 1 en x et tx8 en y
  Serial.print("[3;"+String(t*8)+"H");
  // Ecrire le texte ci-dessous et la variable t
  Serial.print("b = ");
  Serial.println(b);

  //Pour la variable c
  // Envoyer le caractère échappement à chaque ligne
  Serial.write(27);
  // Déplacer le curseur à la pousition 1 en x et tx8 en y
  Serial.print("[4;"+String(t*8)+"H");
  // Ecrire le texte ci-dessous et la variable t
  Serial.print("c = ");
  Serial.println(c);

  while(!Serial.available());
  dummy=Serial.read();
  t++;
}
