//*****************************************************************************
//Dans ce projet, nous allons fabriquer un analyseur de transistor, les mesures
// sont affichées à l'écran de l'ordinateur , en nous servant de l'HyperTerminal. 
// Nous mesurons les Vc, Vb et Vin (varieà l'aide d'un potentiométre).
//Nous montons un transistor NPN 
// le gain = 
// l'intensité de son courant de collecteur Max Ic =
// La chute de tension dans la jonction collecteur-emetteur du transistor Vce = 
// le calcul resistance du collecteur :
// Rc = U/I = (Valim - Vce) / Ic
//
// Le courant de saturation des la base Isbase=
// calcul de la valeur de la resistance de limitation de courant de la base:
// Rb = U/I = Valim/Isbase
//*****************************************************************************

// variables le mesures 
float Vb, Vc, Vin, Ib, Ic, hFE;
float Rb = 1000, Rc = 50;
int Vcc = 5;
int t = 0;
int BUTTON = 8;

void setup() {
 //Configuration 
 Serial.begin(9600);
 pinMode(BUTTON, INPUT);
 //En-tête
 Serial.print("t");
 Serial.print("\t");
 Serial.print("Ib");
 Serial.print("\t");
 Serial.print("Ic");
 Serial.print("\t");
 Serial.println("hFE");

}

void loop() {
  //Collectr les données
  Vb = analogRead(A3);
  Vc = analogRead(A4);
  Vin = analogRead(A5);

  //Calcul des tensions
  Vb = Vb * Vcc / 1023;
  Vin = Vin * Vcc / 1023;
  Vc = Vc * Vcc / 1023;
  
  // Intensité du courant de la base (ibase) en mA (donc x 1000)
  Ib = ((Vin - Vb) / Rb) * 1000;
  
  // Intensité du courant du collecteur (icol) en mA (donc x 1000)
  Ic = ((Vcc - Vc) / Rc) * 1000;
  
  // hFE (gain ce facteur est une valeur sans dimansion
  hFE = Ic / Ib;
  
  // Affichage des resultats
  t++;
  Serial.print(t);
  Serial.print("\t");
  Serial.print(Ib);
  Serial.print("\t");
  Serial.print(Ic);
  Serial.print("\t");
  if (Ib > 0){
    Serial.println(hFE);
      }
    else {
      Serial.println("Débordement");
    }

  // Attendre l'utilisateur
  while (digitalRead(BUTTON) == LOW);
  while (digitalRead(BUTTON) == HIGH);
  delay(2);

}
