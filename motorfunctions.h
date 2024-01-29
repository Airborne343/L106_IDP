#include <Adafruit_MotorShield.h>

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

void stop()
 {
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
 }
#include <Adafruit_MotorShield.h>

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

void stop()
 {
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
 }