
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

#define t 1000

bool up_limit_val;
bool down_limit_val;

void setup() {
  for (byte pin = 2; pin <= 9; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(up_lift_pin, OUTPUT);
  pinMode(down_lift_pin, OUTPUT);
}

void loop() {
  delay(t);
  forward(); delay(t);
  back(); delay(t);
  turn_left(500); delay(t);
  turn_right(); delay(t);
  lift_up(); delay(t);
  lift_down(); delay(t);
  turn_left(0); delay(t);

  for (byte _; _ <= 2; _++) {
    digitalWrite(left_light_pin, 1);
    delay(500);
    digitalWrite(right_light_pin, 1);
    delay(500);
    digitalWrite(left_light_pin, 0);
    delay(500);
    digitalWrite(right_light_pin, 0);
    delay(500);
  }
  exit(0);
}

void forward() {
  for (byte i; i < 255; i++) {
    analogWrite(left_forward, i);
    analogWrite(right_forward, i);
    delay(5);
  }
  delay(1000);
  for (byte i = 255; i; i--) {
    analogWrite(left_forward, i);
    analogWrite(right_forward, i);
    delay(5);
  }
}

void back() {
  for (byte i; i < 255; i++) {
    analogWrite(left_forward, i);
    analogWrite(right_forward, i);
    delay(5);
  }
  delay(1000);
  for (byte i = 255; i; i--) {
    analogWrite(left_back, i);
    analogWrite(right_back, i);
    delay(5);
  }
}

void turn_left(int d) {
  for (byte i; i < 255; i++) {
    analogWrite(right_forward, i);
    analogWrite(left_back, i);
    delay(5);
  }
  delay(d);
  for (byte i = 255; i; i--) {
    analogWrite(right_forward, i);
    analogWrite(left_back, i);
    delay(5);
  }
}

void turn_right() {
  for (byte i; i < 255; i++) {
    analogWrite(left_forward, i);
    analogWrite(right_back, i);
    delay(5);
  }
  delay(500);
  for (byte i = 255; i; i--) {
    analogWrite(left_forward, i);
    analogWrite(right_back, i);
    delay(5);
  }
}

void lift_up() {
  up_limit_val = digitalRead(up_limit_pin);
  while (!up_limit_val) {
    digitalWrite(up_lift_pin, 1);
  }
}

void lift_down() {
  down_limit_val = digitalRead(down_limit_pin);
  while (!down_limit_val) {
    digitalWrite(down_lift_pin, 1);
  }
}
