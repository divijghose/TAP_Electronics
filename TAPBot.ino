#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = //"your auth key"; 
// Your WiFi credentials. 
// Set password to "" for open networks. 
char ssid[] = //"your network ssid"; 
char pass[] = //"your network password"; 
int PWMR=4;//Right side 
int PWML=5;//Left side 
int FL=14;//Left forward
int FR=12;//Right forward
int RR=15;//Right reverse 
int RL=13;//Left reverse 
void setup(){ 
 // Debug console 
 Serial.begin(115200); 
 Blynk.begin(auth, ssid, pass); 
 pinMode(PWMR, OUTPUT); 
 pinMode(PWML, OUTPUT); 
 pinMode(RR, OUTPUT); 
 pinMode(RL, OUTPUT);
 pinMode(FR, OUTPUT); 
 pinMode(FL, OUTPUT);  
 
} 
void loop(){
  Blynk.run();
}
 //Handling Jostick Data
 BLYNK_WRITE(V1){
  int x = param[0].asInt();
  int y = param[1].asInt();
   
  if(x==-1 && y==-1){
     //digitalWrite(PWML, LOW); 
     //digitalWrite(PWMR, HIGH); 
     digitalWrite(RL, LOW); 
     digitalWrite(FR, LOW); 
     digitalWrite(FL, LOW);
     digitalWrite(RR, HIGH); 
}else if(x==-1 && y==0){        //Left Turn 
     //digitalWrite(PWMR, HIGH);
     //digitalWrite(PWML, HIGH);  
     digitalWrite(FR, HIGH); 
     digitalWrite(RR, LOW); 
     digitalWrite(RL, HIGH); 
     digitalWrite(FL, LOW); 
}else if(x==-1 && y==1){        //Forward and Left     
     //digitalWrite(PWML, LOW); 
     //digitalWrite(PWMR, HIGH);

     digitalWrite(FR, LOW); 
     digitalWrite(RR, HIGH); 
     digitalWrite(RL, LOW); 
      
     digitalWrite(RL, LOW); 
}else if(x==0 && y==-1){        //Backward     
     //digitalWrite(PWMR, HIGH);
     //digitalWrite(PWML, HIGH);  
     digitalWrite(RR, HIGH); 
     digitalWrite(FR, LOW); 
     digitalWrite(FL, LOW);
     
     digitalWrite(RL, HIGH);
}else if(x==0 && y==0){        //Stay 
     //digitalWrite(PWMR, LOW);
     //digitalWrite(PWML, LOW);  
     digitalWrite(RR, LOW); 
     digitalWrite(RL, LOW); 
     digitalWrite(FR, LOW); 
     
     digitalWrite(FL, LOW); 
}else if(x==0 && y==1){        //Forward 
     //digitalWrite(PWMR, HIGH); 
     //digitalWrite(PWML, HIGH);
     digitalWrite(RR, LOW); 
     digitalWrite(FR, HIGH); 
     
      
     digitalWrite(FL, HIGH);
     digitalWrite(RL, LOW); 
}else if(x==1 && y==-1){        //Backward and Right     
     //digitalWrite(PWML, HIGH); 
     //digitalWrite(PWMR, LOW);
     digitalWrite(RL, HIGH);
     digitalWrite(FR, LOW);
     digitalWrite(FL, LOW);
      
     digitalWrite(RR, LOW); 
}else if(x==1 && y==0){        //Right turn 
     //digitalWrite(PWMR, HIGH);
     //digitalWrite(PWML, HIGH);  
     digitalWrite(FR, LOW); 
     digitalWrite(RR, HIGH); 
     digitalWrite(FL, HIGH);
     digitalWrite(RL, LOW); 
}else if(x==1 && y==1){        //Forward and Right 
     //digitalWrite(PWML, HIGH); 
     //digitalWrite(PWMR, LOW); 
     digitalWrite(RL, LOW); 
     digitalWrite(FL, HIGH);
     digitalWrite(RR, LOW);
     
     digitalWrite(FR, LOW);
 } 
}  
