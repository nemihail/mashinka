
#define left_light_pin 2
#define right_light_pin 4   // headlight pins

#define up_lift_pin 7
#define down_lift_pin 8   // lift pins

#define down_limit_pin A7
#define up_limit_pin A6     //limit switch pins

#define left_forward 3
#define left_back 5
#define right_back 6
#define right_forward 9

void setup() {
  for (byte pin = 2; pin <= 9; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(up_lift_pin, OUTPUT);
  pinMode(down_lift_pin, OUTPUT);
}

void loop() {
  analogWrite(9, 150);
  analogWrite(3, 150);
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);// turn the LED on (HIGH is the voltage level)
  delay(1000);
  analogWrite(9, 0);
  analogWrite(3, 0);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);// turn the LED off by making the voltage LOW
  delay(1000);
  for(int i=0; i<=150; i++){
   analogWrite(9, i);
  analogWrite(3, i);
  delay(10);}  
  for(int i=150; i>=0; i--){
   analogWrite(9, i);
  analogWrite(3, i);
  delay(10); 
  }
  exit(0);
}
