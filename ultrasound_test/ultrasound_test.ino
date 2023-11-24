//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepperX = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepperY = Stepper(stepsPerRevolution, 4, 6, 5, 7);

const int echoPin1 = 22;
const int trigPin1 = 24;
const int echoPin2 = 26;
const int trigPin2 = 28;

int xPos = -1;
int yPos = 0;

int prevValue = 0;

bool movingLeft = false;

float duration1, distance1;
float duration2, distance2;

void moveLeft();
void moveRight();
void moveUp();
void takeReading(int x, int y);

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop() {

  if (movingLeft) {
    // CCW doesn't work right now
    // Serial.println("Rotating x motor CCW");
    moveLeft();
    delay(1000);
    xPos--;
    takeReading(xPos, yPos);
    if (xPos == 0) {
      moveUp();
      yPos++;
      takeReading(xPos, yPos);
      movingLeft = false;
    }
  }
  else {
    // Serial.println("Rotating x motor");
    moveLeft(); // change to move right once we figure out CCW
    delay(1000);
    xPos++;
    takeReading(xPos, yPos);
    if (xPos == 4) {
      moveUp();
      yPos++;
      takeReading(xPos, yPos);
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

void takeReading(int x, int y) {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  long duration1 = pulseIn(echoPin1, HIGH);
  int distance1 = duration1 * 0.034 / 2;

  // Sensor 2 measurement
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 * 0.034 / 2;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm | Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  delay(100); // Delay between readings
}