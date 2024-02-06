#include <Adafruit_MotorShield.h>
#include <Servo.h>
#define MAX_RANG (520)//the max measurement value of the module is 520cm(a little bit longerthan effective max range)
#define ADC_SOLUTION (1023.0)//ADC accuracy of Arduino UNO is 10bit

Servo myservo;

bool linetrack = false;
int sensityPin = A0; // select the input pin
float dist_t1;
float sensity_t1; 
float dist_t3;
float sensity_t3, dist_t2, sensity_t2, dist_t ;// define variables
float dist_t4;
float sensity_t4;
float dist_t5;
float sensity_t5;
float dist_t6;
float sensity_t6;   
bool Soft = false; //define block
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
int servoangle = 110; //angle it turns to grab the block
int tdelay=2; 
int buttonPin = 4;
int led=13;
int motorspeed=150; //0-255  

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(4);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *LiftMotor = AFMS.getMotor(3);


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

float ultrasensor_reading(){
   // read the value from the sensor:
sensity_t1 = analogRead(sensityPin);
dist_t1 = sensity_t1 * MAX_RANG / ADC_SOLUTION;//
delay(10);
sensity_t2 = analogRead(sensityPin);
dist_t2 = sensity_t2 * MAX_RANG / ADC_SOLUTION;//
delay(10);
sensity_t3 = analogRead(sensityPin);
dist_t3 = sensity_t3 * MAX_RANG / ADC_SOLUTION;//
delay(10);
sensity_t4 = analogRead(sensityPin);
dist_t4 = sensity_t4 * MAX_RANG / ADC_SOLUTION;//
delay(10);
sensity_t5 = analogRead(sensityPin);
dist_t5 = sensity_t5 * MAX_RANG / ADC_SOLUTION;//
delay(10);
sensity_t6 = analogRead(sensityPin);
dist_t6 = sensity_t6 * MAX_RANG / ADC_SOLUTION;//
delay(10);

dist_t = (dist_t1+dist_t2+dist_t3+dist_t4+dist_t5+dist_t6)/3;
Serial.println(dist_t);
return dist_t;
}

void ultrasensor(float distance) {
if(1<distance && distance< 5.5)
  {
    Serial.println("hard");
    Serial.println(distance);
    Soft = false;
    //counter ++; //metal block detect so go to green 
    delay(500);
  }
else {
  Serial.println("soft");
  Serial.println(distance);
}
}
