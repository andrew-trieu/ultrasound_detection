const int echoPin = 9;
const int trigPin = 10;

const int echoPin2 = 12;
const int trigPin2 = 13;

float duration1, distance1;
float duration2, distance2;

float values[2]; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration1 = pulseIn(echoPin, HIGH);
  distance1 = (duration1*.0343)/2;
  values[0] = distance1;
  delay(1000);
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  values[1] = distance2;
  Serial.print(values[0]);
  Serial.print(",");
  Serial.println(values[1]);
  
//  Serial.print("0,");
//  Serial.println(distance1);
//  delay(1000);  
//  Serial.print("1,");
//  Serial.println(distance2);
//  delay(1000);
}
