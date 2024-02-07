#include <Adafruit_MotorShield.h>
#include <Servo.h>
Servo myservo; 

int ServoPin = 4;
int pos = 0; // variable to store the servo position
int sl=6;   //sensor left
int sr=7;  //sensor right
int ssr=8;   //outer sensor right
int ssl=9;   //outer sensor left
int led_red = 10;
int led_green = 11;
int led_blue = 12;
int svr=0; //sensor value right
int svl=0; //sensor value left
int svvr=0; //outer sensor value right
int svvl=0; //outer sensor value left
int servoangle = 110; //angle it turns to grab the block
int tdelay=2; 


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *LiftMotor = AFMS.getMotor(1);

void initializePins() {
    pinMode(led_red, OUTPUT); 
    pinMode(led_green, OUTPUT); 
    pinMode(led_blue, OUTPUT); 
}

void forward()
 {
  //adjust the speed here if needed
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
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
  LeftMotor->setSpeed(255);
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

  Serial.println("RIGHT90"); 
  forward();
  delay(250);
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(200);
  while(svl==LOW){
  Serial.println("INSIDEWHILELOOP");
   LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
  svl=digitalRead(sl);
 }
  delay(200);
  }
  

void left90() //turn 90 degrees
 {
  Serial.println("LEFT90");
  forward();
  delay(250);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(200);
  while(svr==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  svr=digitalRead(sr);
 }
  //delay(1000);
  }


void backright() 
 {
  LeftMotor->setSpeed(155);
  LeftMotor->run(BACKWARD);
  RightMotor->setSpeed(100);
  RightMotor->run(BACKWARD);
  Serial.println("BACKRIGHT");
  delay(tdelay);
  }


void backleft() 
 {
  RightMotor->setSpeed(155);
  RightMotor->run(BACKWARD);
  LeftMotor->setSpeed(100);
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


void lift()
{
  LiftMotor->setSpeed(50);
  LiftMotor->run(FORWARD);
  Serial.println("LIFT");
  delay(tdelay);
}


void puttingdown()
{
  LiftMotor->setSpeed(50);
  LiftMotor->run(BACKWARD);
  digitalWrite(led_red, HIGH); 
  digitalWrite(led_green, HIGH); 
  Serial.println("PUTTINGDOWN");
  delay(tdelay);
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
  if(svl==HIGH && svr==HIGH)
  {
  backward();
  }
  else if(svl==HIGH   && svr==LOW)
  {
  backleft(); 
  }
  else if(svl==LOW && svr==HIGH)
   { 
  backright(); 
  }
  else if(svl==LOW && svr==LOW)
   {
  // backward();
  }
}


