// defines pins numbers
const int trigPin = 0;
const int echoPin = 2;  //D3
int PWMR=4;//Right side 
int PWML=5;//Left side 
int FL=14;//Left forward
int FR=12;//Right forward
int RR=15;//Right reverse 
int RL=13;//Left reverse 
// defines variables

long distance;
long duration;
long dist;
void setup() {

pinMode(trigPin, OUTPUT);// Sets the trigPin as an Output
pinMode(echoPin, INPUT);// Sets the echoPin as an Input
pinMode(PWMR, OUTPUT); 
pinMode(PWML, OUTPUT); 
pinMode(RR, OUTPUT); 
pinMode(RL, OUTPUT);
pinMode(FR, OUTPUT); 
pinMode(FL, OUTPUT); 
digitalWrite(PWML, HIGH); 
digitalWrite(PWMR, HIGH); 
Serial.begin(115200); // Starts the serial communication
}

void loop() {

SonarSensor( trigPin, echoPin);
distance = dist;
if (distance >= 25){
  digitalWrite(RR, LOW); 
  digitalWrite(FR, HIGH); 
  digitalWrite(FL, HIGH);
  digitalWrite(RL, LOW); 
  
} 
else if (distance <25){
  digitalWrite(RR, LOW); 
  digitalWrite(RL, LOW); 
  digitalWrite(FR, LOW); 
  digitalWrite(FL, LOW); 
  delay(1000);
  digitalWrite(FR, LOW); 
  digitalWrite(RR, HIGH); 
  digitalWrite(FL, HIGH);
  digitalWrite(RL, LOW);
  delay(1000); 
  digitalWrite(RR, LOW); 
  digitalWrite(RL, LOW); 
  digitalWrite(FR, LOW); 
  digitalWrite(FL, LOW); 
  delay(1000);
}

/*// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.print(distance);


delay(2000);*/
}

void SonarSensor(int trigP, int echoP){
  digitalWrite(trigP, LOW);
  delayMicroseconds(2);
  digitalWrite(trigP, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP, LOW);
  
duration = pulseIn(echoP, HIGH);
dist= duration*0.034/2;
}
  
