#include <Adafruit_MotorShield.h>
#include <Servo.h>

Servo myservo; 

int ServoPin = 10;
int pos = 0; // variable to store the servo position
int sl=6;   //sensor left
int sr=7;  //sensor right
int ssr=8;   //outer sensor right
int ssl=9;   //outer sensor left
int svr=0; //sensor value right
int svl=0; //sensor value left
int svvr=0; //outer sensor value right
int svvl=0; //outer sensor value left
int servoangle = 180; //angle it turns to grab the block


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(4);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(1);

int tdelay=2; 

void forward()
 {
  //adjust the speed here if needed
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
  Serial.println("FORWARD");
  delay(tdelay);
 } 

void backward()
   {
    LeftMotor->run(BACKWARD);
    RightMotor->run(BACKWARD);
    Serial.println("BACKWARD");
    delay(tdelay);
   }

void right() 
 {
  LeftMotor->setSpeed(225);
  LeftMotor->run(FORWARD);
  RightMotor->setSpeed(25);
  RightMotor->run(FORWARD);
  Serial.println("RIGHT");
  delay(tdelay);
  }


void left() 
 {
  RightMotor->setSpeed(225);
  RightMotor->run(FORWARD);
  LeftMotor->setSpeed(25);
  LeftMotor->run(FORWARD);
  Serial.println("LEFT");
  delay(tdelay); 
}  

void right90() //turn 90 degrees
 {
  //unsigned long current_time = millis(); 
  // Serial.println(current_time);
  // int interval = 2000;
  // while((millis()-current_time) < interval){
  // Serial.println(millis());
  Serial.println("RIGHT90");
 
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(1300);
  }
  

void left90() //turn 90 degrees
 {
  Serial.println("LEFT90");
  //forward();
  //delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
    delay(1300);
  }


void backright() 
 {
  LeftMotor->setSpeed(225);
  LeftMotor->run(BACKWARD);
  RightMotor->setSpeed(25);
  RightMotor->run(BACKWARD);
  Serial.println("BACKRIGHT");
  delay(tdelay);
  }


void backleft() 
 {
  RightMotor->setSpeed(225);
  RightMotor->run(BACKWARD);
  LeftMotor->setSpeed(25);
  LeftMotor->run(BACKWARD);
  Serial.println("BACKLEFT");
  delay(tdelay); 
}  


void stop()
 {
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
 }

void grab()
{
   for (pos = 0; pos <= servoangle; pos += 1) { // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  myservo.write(pos); // tell servo to go to position in variable 'pos'
  delay(15); // waits 15 ms for the servo to reach the position
  }
}


void release()
{
  myservo.write(0); // tell servo to release to 0 degrees
  }
  
void backwardlinetracking()
{
 svl=digitalRead(sl);
 svr=digitalRead(sr);
 svvr=digitalRead(ssr);
 svvl=digitalRead(ssl); 
  if(svl==LOW && svr==LOW)
  {
  //backward(); 
  //delay(tdelay);
  }
  else if(svl==HIGH   && svr==LOW)
  {
  backleft(); 
  }
  else if(svl==LOW && svr==HIGH)
   { 
  backright(); 
  }
  else if(svl==HIGH && svr==HIGH)
   {
  backward();
  }
}


