
// Motor Wheel Pins
const int LEFT_BACK_WHEEL_FORWARDS = 45;
const int LEFT_BACK_WHEEL_BACKWARDS = 44;
const int LEFT_FRONT_WHEEL_FORWARDS = 43;
const int LEFT_FRONT_WHEEL_BACKWARDS = 42;
const int RIGHT_BACK_WHEEL_FORWARDS = 50;
const int RIGHT_BACK_WHEEL_BACKWARDS = 51;
const int RIGHT_FRONT_WHEEL_FORWARDS = 53;
const int RIGHT_FRONT_WHEEL_BACKWARDS = 52;

int wheel_motor_pins[8] = {LEFT_BACK_WHEEL_FORWARDS, LEFT_FRONT_WHEEL_FORWARDS, RIGHT_FRONT_WHEEL_FORWARDS, RIGHT_BACK_WHEEL_FORWARDS, LEFT_FRONT_WHEEL_BACKWARDS, LEFT_BACK_WHEEL_BACKWARDS, RIGHT_BACK_WHEEL_BACKWARDS, RIGHT_FRONT_WHEEL_BACKWARDS};

// Sensor Pins 
const int LEFT_SENSOR_TRIGGER = 36;
const int LEFT_SENSOR_ECHO = 37;
const int RIGHT_SENSOR_TRIGGER = 3;
const int RIGHT_SENSOR_ECHO = 4;
const int LEDGE_SENSOR_TRIGGER = 10;
const int LEDGE_SENSOR_ECHO = 9;

int sensor_pins[6] = {LEFT_SENSOR_TRIGGER, RIGHT_SENSOR_TRIGGER, LEDGE_SENSOR_TRIGGER, LEFT_SENSOR_ECHO, RIGHT_SENSOR_ECHO, LEDGE_SENSOR_ECHO};

// Scooper Motor Pins

const int EXTENDER_FORWARDS = x;
const int EXTENDER_BACKWARDS = x;
const int EXTENDER_SPEED = x;
const int BALL_REMOVER_FORWARDS = x;
const int BALL_REMOVER_BACKWARDS = x;
const int BALL_REMOVER_SPEED = x;
const int LIFTER_FORWARDS = x;
const int LIFTER_BACKWARDS = x;
const int LIFTER_SPEED = x;

int scooper_motor_pins[9] = {EXTENDER_FORWARDS, EXTENDER_BACKWARDS, EXTENDER_SPEED, BALL_REMOVER_FORWARDS, BALL_REMOVER_BACKWARDS, BALL_REMOVER_SPEED, LIFTER_FORWARDS, LIFTER_BACKWARDS, LIFTER_SPEED};

int state = 0;

void setup() {

  // Set Wheel Motor Pins

  for(int i = 0; i < 8; i++) {
    pinMode(wheel_motor_pins[i], OUTPUT);
  }
 
  // Set Sensor Pins

  for (int i = 0; i < 6; i++) {

    if (i < 3) {
      pinMode(sensor_pins[i], OUTPUT);
    }
    else {
      pinMode(sensor_pins[i], INPUT);
    }
  }

  // Set Scooper Motor Pins

  for(int i = 0; i < 9; i++) {
    pinMode(scooper_motor_pins[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  Serial.println(state);
  Serial.println("Pissing my pants rn fr");
  state = 0;

  
  switch (state) {

    case 0: 
    // drive right
      int distance_ledge = sensorDistance(LEDGE_SENSOR_TRIGGER, LEDGE_SENSOR_ECHO);
      
      if (distance_ledge > 5) {
        stopWheels(20);
        state = 1;
      }
      else {
        wheelsGoRight(20);
      }
      break;
      
    case 1: 
    // drive forward
      int distance_left = sensorDistance(LEFT_SENSOR_TRIGGER, LEFT_SENSOR_ECHO);

      Serial.println(distance_left);
      
      if (distance_left < 18) {
        stopWheels(20);
        state = 2;
        Serial.println("I am here, look at me");
      }
      else {
        wheelsGoForward(20);
      }
      break;
    case 2:
      // lift arm
  }

/**
  switch (state) {

    case 0: 
      int distance_ledge = sensorDistance(LEDGE_SENSOR_TRIGGER, LEDGE_SENSOR_ECHO);
      
      if (distance_ledge > 5) {
        stopWheels(20);
        state = 1;
      }
      else {
        wheelsGoRight(20);
      }
      break;
      
    case 1: 
    
      Serial.println("I am here");
      
      int distance_left = sensorDistance(LEFT_SENSOR_TRIGGER, LEFT_SENSOR_ECHO);
      int distance_right = sensorDistance(RIGHT_SENSOR_TRIGGER, RIGHT_SENSOR_ECHO);
      
      if (distance_left < 18 && distance_right < 18) {
        stopWheels(20);
        state = 2;
      }
      else {
        wheelsGoForward(20);
      }
      break;
  }
*/
  
/**
  int distance_ledge = sensorDistance(LEDGE_SENSOR_TRIGGER, LEDGE_SENSOR_ECHO);
  Serial.println(distance_ledge);

  if (distance_ledge > 5) {
    stopWheels(20);
  }
  else {
    wheelsGoRight(20);
  }
*/

  
/**
  int distance_left = sensorDistance(LEFT_SENSOR_TRIGGER, LEFT_SENSOR_ECHO);
  int distance_right = sensorDistance(RIGHT_SENSOR_TRIGGER, RIGHT_SENSOR_ECHO);

  if (distance_left < 5 && distance_right < 5) {
    stopWheels(20);
  }
  else {
    wheelsGoForward(20);
  }
*/

  

/**
  wheelsGoForward(4000);

  wheelsGoLeft(4000);

  wheelsGoBackwards(4000);

  wheelsGoRight(4000);

  wheelsRoateLeft(4000);
*/
}

void stopWheels(int delay_time){

  for(int i = 0; i < 8; i++) {
    
    digitalWrite(wheel_motor_pins[i], LOW);
  }

  delay(delay_time);
}


void wheelsGoForward(int delay_time) {


  for(int i = 0; i < 4; i++) {
    
    digitalWrite(wheel_motor_pins[i], HIGH);
  }

  delay(delay_time);

}

void wheelsGoBackwards(int delay_time) {

  for(int i = 4; i < 8; i++) {
    
    digitalWrite(wheel_motor_pins[i], HIGH);
  }

  delay(delay_time);
}


void wheelsGoLeft(int delay_time) {

  for(int i = 0; i < 8; i += 2) {
    
    digitalWrite(wheel_motor_pins[i], HIGH);
  }

  delay(delay_time);
  
}

void wheelsGoRight(int delay_time) {


  for(int i = 1; i < 8; i += 2) {
    
    digitalWrite(wheel_motor_pins[i], HIGH);
  }

  delay(delay_time);
  
}

void wheelsRotateLeft(int delay_time) {

  for(int i = 2; i < 6; i++) {
    
    digitalWrite(wheel_motor_pins[i], HIGH);
  }

  delay(delay_time);
  
}

void liftArm() {
  int motor_speed = x;
  int delay_time = x;

  analogWrite(scooper_motor_pins[9], motor_speed);
  digitalWrite(scooper_motor_pins[7], HIGH);

  delay(delay_time);

  digitalWrite(scooper_motor_pins[7], LOW);

}

void dropArm() {
  int motor_speed = x; // motor speed (0-255)
  int delay_time = x; // time of motor operation (ms)

  analogWrite(scooper_motor_pins[9], motor_speed);
  digitalWrite(scooper_motor_pins[8], HIGH);

  delay(delay_time);

  digitalWrite(scooper_motor_pins[8], LOW);

}

void extendArm() {
  int motor_speed = x; // motor speed (0-255)
  int delay_time = x; // time of motor operation (ms)

  analogWrite(scooper_motor_pins[3], motor_speed);
  digitalWrite(scooper_motor_pins[1], HIGH);

  delay(delay_time);

  digitalWrite(scooper_motor_pins[1], LOW);

}

void retractArm() {
  int motor_speed = x; // motor speed (0-255)
  int delay_time = x; // time of motor operation (ms)

  analogWrite(scooper_motor_pins[3], motor_speed);
  digitalWrite(scooper_motor_pins[2], HIGH);

  delay(delay_time);

  digitalWrite(scooper_motor_pins[2], LOW);

}

void rackOut() {
  int motor_speed = x; // motor speed (0-255)
  int delay_time = x; // time of motor operation (ms)

  analogWrite(scooper_motor_pins[6], motor_speed);
  digitalWrite(scooper_motor_pins[4], HIGH);

  delay(delay_time);

  digitalWrite(scooper_motor_pins[4], LOW);

}

void rackIn() {
  int motor_speed = x; // motor speed (0-255)
  int delay_time = x; // time of motor operation (ms)

  analogWrite(scooper_motor_pins[6], motor_speed);
  digitalWrite(scooper_motor_pins[5], HIGH);

  delay(delay_time);

  digitalWrite(scooper_motor_pins[5], LOW);

}

int sensorDistance(int trigger_pin, int echo_pin) {

  unsigned long duration;
  int distance; 

  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  delay(20);
  
  return distance;
}
