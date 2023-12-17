//*****************************************************************************
//Dans ce projet, nous proposons ici de régler la luminosité de la led LED2 en
// en nous servant d'un potentiométre.
// Nous allons utiliser pour cela la modulation de large impultion (MLI ou 
// PWM en anglais).
//La solution consiste à maintenir la tension constamment au maximum pour nous
// +5V et d'interrompre cette tension plus ou souvent ou longtenps.
// Plus la tension reste longtemps présents plus la lumière de la LED est forte.
//Nous utilisons un potentiométre sur la broche A0 de l'ARDUINO UNO
// et une LED sur la broche 5 (PWM) de l'ARDUINO UNO 
//*****************************************************************************

//Affecter à la variable LED2 la broche 5 (PWM) de l'ARDUINO UNO
//Affectation à la variable POT la broche A0 de l'ARDUINO UNO
int LED2 = 5, POT = 8, VALUE;


void setup() {
  pinMode(LED2, OUTPUT);
 }

void loop() {
  
  //L'instruction permet de transformer les valeurs du résultat de la mesure 
  //anlogique dans une fourchette comprise entre 0 et 1023 dans une fourchette
  //comprise entre 0 et 255.
  VALUE = map(analogRead(POT), 0, 1023, 0, 255);
  analogWrite(LED2, VALUE);

}
