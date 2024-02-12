int counter = 0;
//count the numbers of turn  //Remember to change back counter to 0, uncomment initialise, soft=false
int i =0;


void counterfunction(){
Serial.println(counter);
if (counter == 0)
{
  Serial.println("LEFT90");
  forward();
  delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(1000);
  while(svr==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    svr=digitalRead(sr);
  }
  counter++; 
  }
  
else if (counter == 1)   //Moving into the junction
{
  Serial.println("RIGHT90"); 
  forward();
  delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(1500);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
 }
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(100);
    release();
  counter++;
  }


else if (counter==2) //Sensing and detecting the block
{ 
    stop();
    ultrasensor(ultrasensor_reading()); 
    grab();
    delay(700);
    lift();
    backward();
    delay(400);
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW || svvr == LOW){
      Serial.println("BACKWARD");
      backward();     //Backward linetracking
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
    }
    backward();
    delay(500);
    if (SOFT == true) {
        Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if SOFT
        RightMotor->setSpeed(200);
        LeftMotor->setSpeed(0);
        LeftMotor->run(FORWARD);
        RightMotor->run(FORWARD);
        delay(2000);
        while(svr==LOW){
            Serial.println("INSIDEWHILELOOP");
            LeftMotor->run(BACKWARD);
            RightMotor->run(FORWARD);
            svr=digitalRead(sr);
        }
      }
    else {                        //Turn RIGHT to the way back to the zone if HARD
    Serial.println("RIGHT90"); 
    RightMotor->setSpeed(0);
    LeftMotor->setSpeed(200);
    LeftMotor->run(FORWARD);
    RightMotor->run(FORWARD);
    delay(2000);
    while(svl==LOW){
        Serial.println("INSIDEWHILELOOP");
        LeftMotor->run(FORWARD);
        RightMotor->run(BACKWARD);
        svl=digitalRead(sl);
     }
    }
    counter++;
    }


else if (counter == 3) //moving into junction of the putting zone
{
if (SOFT == true) 
{
Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if SOFT
forward();
delay(500);
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
delay(1500);
while(svr==LOW)
{
Serial.println("INSIDEWHILELOOP");
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
svr=digitalRead(sr);
}
}

else 
{                    //TURN RIGHT to the way back to the zone if HARD
Serial.println("RIGHT90"); 
forward();
delay(500);
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(FORWARD);
RightMotor->run(BACKWARD);
delay(1500);
while(svl==LOW)
{
Serial.println("INSIDEWHILELOOP");
LeftMotor->run(FORWARD);
RightMotor->run(BACKWARD);
svl=digitalRead(sl);
}
}
counter++;
}

else if (counter==4)    //Putting the block and backtracking until the second line
  {
    LeftMotor->run(RELEASE);
    RightMotor->run(RELEASE);
    puttingdown();
    release();
    svvl = LOW;
    svvr = LOW;
    backward();
    delay(500);
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    delay(1500);
    svr=digitalRead(sr);
    while(svr==LOW){
    Serial.println("TURN180");
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    svr=digitalRead(sr);
    }
    while(i<2){
      linetracking();
      Serial.println("LINETRACKING");
      // backwardlinetracking();     //Backward linetracking
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
      if (svvl == HIGH || svvr == HIGH){
        Serial.println("DETECTWHITELINE");
        i+=1;
        delay(800);
      }
    }
if (SOFT == false) {
        Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if SOFT
        backward();
        delay(750);
        RightMotor->setSpeed(200);
        LeftMotor->setSpeed(0);
        LeftMotor->run(FORWARD);
        RightMotor->run(FORWARD);
        delay(2000);
        while(svr==LOW){
            Serial.println("INSIDEWHILELOOP");
            LeftMotor->run(BACKWARD);
            RightMotor->run(FORWARD);
            svr=digitalRead(sr);
        }
      }
else {                        //Turn RIGHT to the way back to the zone if HARD
    Serial.println("RIGHT90"); 
    backward();
    delay(750);
    RightMotor->setSpeed(0);
    LeftMotor->setSpeed(200);
    LeftMotor->run(FORWARD);
    RightMotor->run(FORWARD);
    delay(2000);
    while(svl==LOW){
        Serial.println("INSIDEWHILELOOP");
        LeftMotor->run(FORWARD);
        RightMotor->run(BACKWARD);
        svl=digitalRead(sl);
     }
    }
  counter++;
  }


  else if (counter == 5)
  {
  if (SOFT == true) {       //Turn Right into the second block junction if SOFT
  Serial.println("RIGHT90"); 
  forward();
  delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(1500);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
 }
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(100);
  
    }
    else {                //Turn Left into the second block junction if HARD
  Serial.println("LEFT90");
  forward();             //why it has backward here??
  delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(1500);
  while(svr==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  svr=digitalRead(sr);
 }
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    delay(100);
    }
    counter++;
  }


  else if (counter == 6)   //Sensing the second block and backwardlinetracking and turn
  {
    stop();
    ultrasensor(ultrasensor_reading()); 
    grab();
    delay(700);
    lift();
    backward();
    delay(400);
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW || svvr == LOW){
      Serial.println("BACKWARD");
      backward();     //Backward linetracking
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
    }
    backward();
    delay(300);
 
    if (SOFT == false) {
        Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if SOFT
        RightMotor->setSpeed(200);
        LeftMotor->setSpeed(0);
        LeftMotor->run(FORWARD);
        RightMotor->run(FORWARD);
        delay(2000);
        while(svr==LOW){
            Serial.println("INSIDEWHILELOOP");
            LeftMotor->run(BACKWARD);
            RightMotor->run(FORWARD);
            svr=digitalRead(sr);
        }
      }
    else {                        //Turn RIGHT to the way back to the zone if HARD
    Serial.println("RIGHT90"); 
    RightMotor->setSpeed(0);
    LeftMotor->setSpeed(200);
    LeftMotor->run(FORWARD);
    RightMotor->run(FORWARD);
    delay(2000);
    while(svl==LOW){
        Serial.println("INSIDEWHILELOOP");
        LeftMotor->run(FORWARD);
        RightMotor->run(BACKWARD);
        svl=digitalRead(sl);
     }
    }
  counter++;
  }


  else if (counter == 7)   //Turning to the way back to the putting zone for the second block
  {
  if (SOFT == true) {
  Serial.println("LEFT90");
  forward();
  delay(300);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(1000);
  while(svr==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    svr=digitalRead(sr);
  }
    }

  else {                        
  Serial.println("RIGHT90");
  forward();
  delay(300);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(1000);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
  }
    }
  counter++;
  }


  else if (counter == 8){   //Putting the second block and backwardlinetracking and turning into the junction
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
  puttingdown();
  release();
  backward();
  delay(500);
  svvl = LOW;
  svvr = LOW;
  while(svvr==LOW && svvl==LOW){
      backward();
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
  }
  
  if (SOFT == true) {   //Left turn back to the original zone if the block is SOFT
  Serial.println("LEFT90");  
  forward();
  delay(300); 
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(1000);
  svr=LOW;
  while(svr==LOW){
      Serial.println("INSIDEWHILELOOP");
      LeftMotor->run(BACKWARD);
      RightMotor->run(FORWARD);
      svr=digitalRead(sr);
      }
    }

  else {                     //Right turn back to the original zone if the block is HARD
    Serial.println("RIGHT90"); 
    forward();
    delay(300);
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(1000);
    svl=LOW;
    while(svl==LOW){
      Serial.println("INSIDEWHILELOOP");
      LeftMotor->run(FORWARD);
      RightMotor->run(BACKWARD);
      svl=digitalRead(sl);
    }                  
  }
  counter++;
  }


else if (counter == 9){   //Turning back to the end zone
 if (SOFT == true) {
  Serial.println("RIGHT90"); 
  forward();
  delay(800);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(1500);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
 }
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(100);
    }
else {                        
  Serial.println("LEFT90"); 
  forward();
  delay(800);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(1500);
  while(svr==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    svr=digitalRead(sr);
 }
    LeftMotor->run(BACKWARD);
    RightMotor->run(FORWARD);
    delay(100);
    }
counter++;
}


else if(counter == 10){        //Go back to the starting point
  forward();
  delay(1500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(4500);                 //PAUSE if industrial zone block is not needed
  forward();
  delay(1500);
  counter++;
  Serial.println(counter);     //Move forward out of the starting zone to the industrial zone block
}


else if (counter == 11)         //RIGHT 90 to the way of industrial zone
{
  Serial.println("RIGHT90");
  forward();
  delay(500);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(1000);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
  }
  counter++; 
  }

else if(counter == 12)      //LEFT 90 to the way of industrial zone
{ 
Serial.println("LEFT90");    
forward();
delay(500);
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
delay(1500);
while(svr==LOW)
{
Serial.println("INSIDEWHILELOOP");
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
svr=digitalRead(sr);
}
counter++;
}

else if(counter == 13)
{ 
Serial.println("LEFT90");    //LEFT 90 to the way of industrial zone
forward();
delay(500);
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
delay(1500);
while(svr==LOW)
{
Serial.println("INSIDEWHILELOOP");
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
svr=digitalRead(sr);
}
counter++;
}

else if(counter == 14)    //RIGHT 90 to the way of industrial zone
{ 
Serial.println("RIGHT90");    
forward();
delay(500);
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(FORWARD);
RightMotor->run(BACKWARD);
delay(1500);
while(svl==LOW)
{
Serial.println("INSIDEWHILELOOP");
LeftMotor->run(FORWARD);
RightMotor->run(BACKWARD);
svl=digitalRead(sl);
}
RightMotor->setSpeed(50);
LeftMotor->setSpeed(50);
forward();
delay(5000);
//add distance ranging function
counter++;
}
}
