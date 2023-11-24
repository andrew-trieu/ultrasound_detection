//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 200;
int num_iterations = 0;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {
  // Rotate CW slowly at 5 RPM
  myStepper.setSpeed(15);
  myStepper.step(stepsPerRevolution);
  
  // Rotate CCW quickly at 10 RPM
//  myStepper.setSpeed(15);
//  myStepper.step(-stepsPerRevolution);
//  delay(1000);
}
