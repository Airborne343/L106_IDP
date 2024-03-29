#include <Adafruit_MotorShield.h>
#include <Servo.h>
Servo myservo; 

int ServoPin = 9;
int pos = 0; // variable to store the servo position
int sl=5;   //sensor left
int sr=6;  //sensor right
int ssr=7;   //outer sensor right
int ssl=8;   //outer sensor left
int led_red = 2;    //light sensors
int led_green = 3;
int led_blue = 4;
int svr=0; //sensor value right
int svl=0; //sensor value left
int svvr=0; //outer sensor value right
int svvl=0; //outer sensor value left
int servoangle = 90; //angle it turns to grab the block
int tdelay=10; 


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *LiftMotor = AFMS.getMotor(1);

void pininitialise() {    //output for led lights
    pinMode(led_red, OUTPUT); 
    pinMode(led_green, OUTPUT); 
    pinMode(led_blue, OUTPUT); 
}
void blue_led_flashing(){    //function to turn blue led on during motion
  digitalWrite(led_blue, LOW); //Turn on led_blue
  delay(100);
  digitalWrite(led_blue, HIGH); //Turn off led_blue
  delay(100);

}
void forward()        //forward function
 {
  //adjust the speed here if needed
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
  Serial.println("FORWARD");
  delay(tdelay);
 } 


void backward()        //backwards function
   {
    LeftMotor->setSpeed(225);
    RightMotor->setSpeed(225);
    LeftMotor->run(BACKWARD);
    RightMotor->run(BACKWARD);
    Serial.println("BACKWARD");
    delay(tdelay);
   }


void right()     //slight right for linetracking, by one motor faster than the other
 {
  LeftMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->setSpeed(100);
  RightMotor->run(FORWARD);
  Serial.println("RIGHT");
  delay(tdelay);
  }


void left()     //slight left for linetracking, by one motor faster than the other
 {
  RightMotor->setSpeed(255);
  RightMotor->run(FORWARD);
  LeftMotor->setSpeed(100);
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
  }

void stop()
 {
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
 }

void grab()        //close crawls
{
   for (pos = 20; pos <= servoangle; pos += 1) { // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  myservo.write(pos); // tell servo to go to position in variable 'pos'
  delay(30); // waits 15 ms for the servo to reach the position
  }
}


void lift()        //lift crawls
{
  LiftMotor->setSpeed(250);
  LiftMotor->run(FORWARD);
  Serial.println("LIFT");
  delay(500);
  LiftMotor->run(RELEASE);
}


void puttingdown()     //put crawls down
{
  LiftMotor->setSpeed(150);
  LiftMotor->run(BACKWARD);
  digitalWrite(led_red, LOW); 
  digitalWrite(led_green, LOW); 
  Serial.println("PUTTINGDOWN");
  delay(500);
  LiftMotor->run(RELEASE);
}

void release()        //open crawls
{
  myservo.write(20); // tell servo to release to 0 degrees
  }
  
//LINETRACKING FUNCTIONS
void linetracking(){
  blue_led_flashing();
 svl=digitalRead(sl);
 svr=digitalRead(sr);
 svvr=digitalRead(ssr);
 svvl=digitalRead(ssl);
   
  if(svl==HIGH   && svr==LOW)
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
  }
}
