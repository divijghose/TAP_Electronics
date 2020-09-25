#include <Servo.h> // including servo library.

Servo servo; // Giving name to servo.

const int analog_ip = A0; //Naming analog input pin

int inputVal  = 0;        //Variable to store analog input values
int noise;
int u1 = 900;
int u2 = 1000;
int l1 = 600;
int l2 = 200;

void setup (){
  servo.attach(2); // Attaching Servo to D4
  pinMode(A0, INPUT);  // Defining pin as output
  Serial.begin(115200);    // Initiating Serial communication

}

void loop(){
  inputVal = analogRead (analog_ip); // Analog Values 0 to 1023
  Serial.println (inputVal);
  noise = inputVal;
  if((noise >= u1 && noise <u2) || (noise<=l1 && noise>l2)){
    servo.write(90);
  }
  else if (noise >=u2 || noise <=l2){
    servo.write(0);
    
  }
else{
  servo.write(180);
}
  delay(1500);
 
}



                                                                                                                                                                                                                         
