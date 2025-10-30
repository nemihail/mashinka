
// nano old bootloader required

#define left_motor_forward 3
#define left_motor_back 5

#define right_motor_forward 9
#define right_motor_back 6

#define down_limit_pin A7
#define up_limit_pin A6


/*
 *     _    _                          _    _
 *    \ \  / /                        \ \  / /
 *     \ \/ / _   _   _   __   _   __  \ \/ /  _    _
 *      \  / | | | | | | /  | | | / /   \  /  | \  / |
 *      / /  | |_| | | |/   | | |/ /    / /   |  \/  |
 *     / /   |  _  | |   /| | | |\ \   / /    | |\/| |
 *    /_/    |_| |_| |__/ |_| |_| \_\ /_/     |_|  |_|
 */


void setup() {
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_back, OUTPUT);
  pinMode(right_motor_back, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
}

void loop() {
  wheels();
}

void wheels(){
  digitalWrite(right_motor_back, 0);
  digitalWrite(left_motor_forward, 1);
  delay(1000);
  digitalWrite(left_motor_forward, 0);
  digitalWrite(left_motor_back, 1);
  delay(1000);
  digitalWrite(left_motor_back, 0);
  digitalWrite(right_motor_forward, 1);
  delay(1000);
  digitalWrite(right_motor_forward, 0);
  digitalWrite(right_motor_back, 1);
  delay(1000);
}
