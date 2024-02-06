#include <Adafruit_MotorShield.h>
#define MAX_RANG (520)//the max measurement value of the module is 520cm(a little bit longerthan effective max range)
#define ADC_SOLUTION (1023.0)//ADC accuracy of Arduino UNO is 10bit

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(4);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(1);


int sensityPin = A0; // select the input pin
float dist_t1;
float sensity_t1; 
float dist_t3;
float sensity_t3, dist_t2, sensity_t2, dist_t ;// define variables
bool Soft = false; //define block
int tdelay=2; 

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

dist_t = (dist_t1+dist_t2+dist_t3)/3;
Serial.println(dist_t);
return dist_t;

}

void ultrasensor(float distance) {
if(1<distance && distance< 5.6)
  {
    Serial.println("hard");
    Serial.println(distance);
    Soft = false;
    //counter ++; //metal block detect so go to green 
    delay(500);
  }
  // else if (6 <dist_t && dist_t < 9.5)   
  //     {
  //     Serial.println("soft soft");
  //     Serial.println(dist_t);
  //    Soft = true;
  //    //counter += 2; //foam block detect so go to red
  //    delay(500);
  //    }
else {
  Serial.println("soft");
  Serial.println(distance);
  Soft = true;
    //counter += 2; //foam block detect so go to red
  delay(500);
}
Serial.print("sense");
delay(3000);
}

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
  forward();
  delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
    delay(1300);
  }
  

void left90() //turn 90 degrees
 {
  Serial.println("LEFT90");
  forward();
  delay(500);
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
