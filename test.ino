
void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(9, 0);
  digitalWrite(3, 1);
  delay(1000);
  digitalWrite(3, 0);
  digitalWrite(5, 1);
  delay(1000);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  delay(1000);
  digitalWrite(6, 0);
  digitalWrite(9, 1);
}
