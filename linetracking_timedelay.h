//LINETRACKING FUNCTION
#include <Adafruit_MotorShield.h>
#include "motorfunctions.h"

bool linetrack = false;
int buttonPin = 4;
int led=13;
int motorspeed=150; //0-255        

void initialise(){
  //move forward for 2 seconds
  Serial.println("INITIALISE");
  LeftMotor->setSpeed(200);
  LeftMotor->run(FORWARD);
  RightMotor->setSpeed(200);
  RightMotor->run(FORWARD);
  delay(1500);
  //need to add a release here? myMotor->run(RELEASE);
}

void linetracking(){
 svl=digitalRead(sl);
 svr=digitalRead(sr);
 svvr=digitalRead(ssr);
 svvl=digitalRead(ssl);
   
  if(svl==LOW && svr==LOW)
  {
  stop();
  }

  else if(svl==HIGH   && svr==LOW)
  {
  left(); 
  }
  else if(svl==LOW && svr==HIGH)
   { 
  right(); 
  }
  else if(svl==HIGH && svr==HIGH)
   {
  forward();
  }}

void loop() {
  // put your main code here, to run repeatedly
  int val = digitalRead(buttonPin); // read input value
  LeftMotor->setSpeed(150);
  RightMotor->setSpeed(150);
  if (val==HIGH){
    Serial.print("ON");
    initialise();
    Serial.println("RUN");
  }
 
  while (linetrack==1){
    linetracking();
    }
  
}

//TIME DELAY FUNCTION
void time_delay(){
  unsigned long previousMillis = 0; //store time for second event
  const long interval = 1000; //interval for second event
  unsigned long currentMillis = millis(); //conditional that checks whether 2 seconds have passed since last event
  if (currentMillis - previousMillis >= interval) {
    previousMillis = millis();
    //execute a piece of code, every *2 seconds*
   }
}
