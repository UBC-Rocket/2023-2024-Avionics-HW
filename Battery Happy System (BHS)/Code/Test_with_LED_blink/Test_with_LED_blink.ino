void setup() {
  pinMode9(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(500);
  
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(500);
}
