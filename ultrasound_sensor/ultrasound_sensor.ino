#include <Stepper.h>

// Motor constants
const int stepsPerRevolution = 2038;
int num_iterations = 0;


// Ultrasound constants
// Add more echo and trig pins equal to number of ultrasound modules
const int echoPin = 9;
const int trigPin = 10;

const int echoPin2 = 12;
const int trigPin2 = 13;

float duration1, distance1;
float duration2, distance2;

float values[2]; 



//***************************************************
// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);


void move_left() {
  // Rotate CW slowly at x RPM
  myStepper.setSpeed(10);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
}

void move_right() {
  // Rotate CCW quickly at x RPM
  myStepper.setSpeed(10);
  Serial.println("moving 1");
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  Serial.println("moving 2");
}


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("MOving left");
  move_left();
  Serial.println("done MOving left");
  delay(2000);
  Serial.println("MOving right");
  move_right();
  Serial.println("done moving right");
  delay(2000);
}
