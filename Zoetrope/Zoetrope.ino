byte state_switch_val = 0; 
byte direction_switch_val = 0; 
byte prev_state_switch_val = 0;
byte prev_direction_switch_val = 0; 
byte motor_is_enabled = 0;
byte motor_direction = 0;
unsigned short motor_speed = 0;

int DIRECTION_SWITCH_PIN = 5;
int STATE_SWITCH_PIN = 4;
int IC_INPUT_1 = 3;
int IC_INPUT_2 = 2;
int IC_ENABLE_1 = 9;
int POT_PIN = A0;

void setup() {
pinMode(DIRECTION_SWITCH_PIN, INPUT); 
pinMode(STATE_SWITCH_PIN, INPUT);
pinMode(IC_INPUT_1, OUTPUT);
pinMode(IC_INPUT_2, OUTPUT);
pinMode(IC_ENABLE_1, OUTPUT);  

}

void loop() {
  state_switch_val = digitalRead(STATE_SWITCH_PIN); 
  delay(1);
  direction_switch_val = digitalRead(DIRECTION_SWITCH_PIN);
  motor_speed = analogRead(POT_PIN) / 4;
  
// process the on/off state of the motor from the state switch 
if (state_switch_val != prev_state_switch_val) { if (state_switch_val) { 
  motor_is_enabled = !motor_is_enabled; } }
  
// process the direction of the motor from the direction switch
if (direction_switch_val != prev_direction_switch_val) { 
  if (direction_switch_val) { motor_direction = !motor_direction; } }
  
// control the direction of the motor using the IC
if (motor_direction) {
  digitalWrite(IC_INPUT_1, LOW);
  digitalWrite(IC_INPUT_2, HIGH);
  } else { 
    digitalWrite(IC_INPUT_1, HIGH); 
    digitalWrite(IC_INPUT_2, LOW);
    }
// control the on/off state of the motor using PWM 
if (motor_is_enabled) { 
  analogWrite(IC_ENABLE_1, motor_speed);
  } else {
    analogWrite(IC_ENABLE_1, 0); }
// prep for next inputs 
prev_state_switch_val = state_switch_val; 
prev_direction_switch_val = direction_switch_val; 

}
