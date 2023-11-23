//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

Stepper myStepperX = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepperX = Stepper(stepsPerRevolution, 4, 6, 5, 7);


const int echoPin = 9;
const int trigPin = 10;

const int echoPin2 = 12;
const int trigPin2 = 13;

float duration1, distance1;
float duration2, distance2;

int xPos = 0;
int yPos = 0;

bool movingLeft = false;

void moveLeft();
void moveRight();
void moveUp();
void takeReading(int x, int y, int trigPin, int echoPin);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  while (yPos <= 25) {
    if movingLeft {
      moveLeft()
      xPos--;
      takeReading()
      if (xPos == 0) {
        move_up()
        yPos++;
        movingLeft = false
      }
    }
    else {
      moveRight()
      xPos++;
      takeReading()
      if (xPos == 3) {
        move_up()
        yPos++;
        movingLeft = true
      }
    }
  }
}

void moveLeft() {
  myStepperX.setSpeed(8);
  myStepperX.step(stepsPerRevolution);
}

void moveRight() {
  myStepperX.setSpeed(-8);
  myStepperX.step(stepsPerRevolution);
}

void moveUp() {
  myStepperY.setSpeed(8);
  myStepperY.step(stepsPerRevolution);
}

void takeReading(int x, int y, int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration1*.0343)/2;

  String output = String(x) + "," String(y) + "," + String(distance);

  Serial.println(output);
  delay(1000);
}