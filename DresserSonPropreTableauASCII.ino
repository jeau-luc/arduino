//***********************************************************************
//Dresser son propre tableau ASCII avec le Hyper terminal VT100
//***********************************************************************

void setup() {
  Serial.begin(9600);
  Serial.print("sign");
  Serial.print("\t");
  Serial.print("value");
}

void loop() {
  
 for(int t=33;t<127;t++){
  Serial.write(t);
  Serial.print("\t");
  Serial.println(t);
  delay(100);
 }
 while(1);

}
