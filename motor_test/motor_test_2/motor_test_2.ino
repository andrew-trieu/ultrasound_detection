//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepperX = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepperY = Stepper(stepsPerRevolution, 4, 6, 5, 7);

const int echoPin = 22;
const int trigPin = 24;

int xPos = -1;
int yPos = 0;

bool movingLeft = false;

float duration, distance;

void moveLeft();
void moveRight();
void moveUp();
void takeReading(int x, int y, int trigPin, int echoPin);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  if (movingLeft) {
    // CCW doesn't work right now
    // Serial.println("Rotating x motor CCW");
    moveLeft();
    delay(1000);
    xPos--;
    takeReading(xPos, yPos, trigPin, echoPin);
    if (xPos == 0) {
      moveUp();
      yPos++;
      takeReading(xPos, yPos, trigPin, echoPin);
      movingLeft = false;
    }
  }
  else {
    // Serial.println("Rotating x motor");
    moveLeft(); // change to move right once we figure out CCW
    delay(1000);
    xPos++;
    takeReading(xPos, yPos, trigPin, echoPin);
    if (xPos == 3) {
      moveUp();
      yPos++;
      takeReading(xPos, yPos, trigPin, echoPin);
      movingLeft = true;
    }
  }
}

void moveLeft() {
  myStepperX.setSpeed(8);
  myStepperX.step(stepsPerRevolution);
}

void moveRight() {
  // Need to figure out how to move motor CCW
  myStepperX.setSpeed(-8);
  myStepperX.step(stepsPerRevolution);
}

void moveUp() {
  myStepperY.setSpeed(8);
  myStepperY.step(stepsPerRevolution);
}

void takeReading(int x, int y, int trigPin, int echoPin) {
  
  // Serial.println("Taking reading");
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  // String output = String(x) + "," String(y) + "," + String(distance);
  Serial.print("X position: ");
  Serial.print(x);
  Serial.print(", Y position: ");
  Serial.print(y);
  Serial.print(", Distance: ");
  Serial.println(distance);
  delay(1000);
}