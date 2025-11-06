
// nano old bootloader required

#define left_motor_forward 3
#define left_motor_back 5
                                            // motors
#define right_motor_forward 9
#define right_motor_back 6

#define down_limit_pin A7                   // limit switches
#define up_limit_pin A6

#define left_backlight_pin 2                // backlights
#define right_backlight_pin 4


/*
 *     _    _                          _    _
 *    \ \  / /                        \ \  / /
 *     \ \/ / _   _   _   __   _   __  \ \/ / _    _
 *      \  / | | | | | | /  | | | / /   \  / | \  / |
 *      / /  | |_| | | |/   | | |/ /    / /  |  \/  |
 *     / /   |  _  | |   /| | | |\ \   / /   | |\/| |
 *    /_/    |_| |_| |__/ |_| |_| \_\ /_/    |_|  |_|
 */


void setup() {
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_back, OUTPUT);
  pinMode(right_motor_back, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);

  pinMode(left_backlight_pin, OUTPUT);
  pinMode(right_backlight_pin, OUTPUT);
}

void loop() {
  switches_lights();
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

void switches_lights(){
  if(analogRead(down_limit_pin)){
    digitalWrite(left_backlight_pin, HIGH);
  }else{
    digitalWrite(left_backlight_pin, LOW);
  }
  if(analogRead(up_limit_pin)){
    digitalWrite(right_backlight_pin, HIGH);
  }else{
    digitalWrite(right_backlight_pin, LOW);
  }
}
