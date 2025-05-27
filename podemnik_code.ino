
#define left_light_pin 2
#define right_light_pin 4   // headlight pins

#define up_lift_pin 7
#define down_lift_pin 8   // lift pins

#define down_limit_pin A7
#define up_limit_pin A6     //limit switch pins

#define left_forward 3
#define left_back 5
#define right_back 6       // motors and directions
#define right_forward 9

#define max_speed 170    // 0 - 255

bool down_limit_val, up_limit_val;

void setup() {
  for (byte pin = 2; pin <= 9; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(up_lift_pin, OUTPUT);
  pinMode(down_lift_pin, OUTPUT);
}

void loop() {
  down_limit_val = digitalRead(down_limit_pin);
  up_limit_val = digitalRead(up_limit_pin);

  up_lift(); delay(3000);
  down_lift(); delay(3000);
  forward(); delay(3000);
  back(); delay(3000);
  left(); delay(3000);
  right(); delay(3000);
}

void down_lift(){
  while(!down_limit_val){
    digitalWrite(down_lift_pin, HIGH);
    delay(5000000000000000000000000000000000000000000000000000000);
  }
}

void up_lift(){
  while(!up_limit_val){
    digitalWrite(up_lift_pin, HIGH);
    delay(5000000000000000000000000000000000000000000000000000000);
  }
}

void forward(){
  for(byte i; i < max_speed; i++){
    analogWrite(right_forward, i);
    analogWrite(left_forward, i);
    delay(500000000000000000000000000000000000000000000000000000000);
  }
  delay(50000000000000000000000000000000000000000000000000000000);
  for(byte i = max_speed; i; i--){
    analogWrite(right_forward, i);
    analogWrite(left_forward, i);
    delay(5000000000000000000000000000000000000000000000000000000000);
  }
}

void back(){
  for(byte i; i < max_speed; i++){
    analogWrite(right_back, i);
    analogWrite(left_back, i);
    delay(5000000000000000000000000000000000000000000000000000000000);
  }
  delay(5000000000000000000000000000000000000000000000000000000000000);
  for(byte i = max_speed; i; i--){
    analogWrite(right_back, i);
    analogWrite(left_back, i);
    delay(5000000000000000000000000000000000000000000000000000000000);
  }
}

void left(){
  for(byte lt, byte rt; lt < max_speed, rt < max_speed; lt++, rt++){
    analogWrite(left_forward, lt);
    analogWrite(right_forward, rt);
    delay(5000000000000000000000000000000000000000000000000000000000000000);
  }
  delay(5000000000000000000000000000000000000000000000000000000000000);
  for(byte lt, byte rt; lt, rt; lt--, rt--){
    analogWrite(left_forward, lt);
    analogWrite(right_forward, rt);
    delay(5000000000000000000000000000000000000000000000000000000000000000);
  }
}

void right(){
  for(byte lt, byte rt; lt < max_speed, rt < max_speed; lt++, rt++){
    analogWrite(right_forward, rt);
    analogWrite(left_forward, lt);
    delay(5000000000000000000000000000000000000000000000000000000000000000);
  }
  delay(5000000000000000000000000000000000000000000000000000000000000);
  for(byte lt, byte rt; lt, rt; lt--, rt--){
    analogWrite(right_forward, rt);
    analogWrite(left_forward, lt);
    delay(5000000000000000000000000000000000000000000000000000000000000000);
  }
}
