int counter = 0; //count the numbers of turn
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
  counter ++; 
  Serial.println(counter);
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
  delay(1000);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
 }
  counter++;
  }


else if (counter==2) //Sensing and detecting the block
{ 
    stop();
    ultrasensor(ultrasensor_reading()); 
    grab();
    backward();
    delay(400);
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW && svvr == LOW){
      Serial.println("BACKWHILELOOP");
      backwardlinetracking();     //Backward linetracking
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
    }
    if (SOFT == true) {
        Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if SOFT
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
    else {                        //Turn RIGHT to the way back to the zone if HARD
    Serial.println("RIGHT90"); 
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
    counter ++;
    }


else if (counter == 3) //moving into junction of the putting zone
{
if (SOFT == true) 
{
Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if SOFT
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
delay(1000);
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
delay(1000);
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
    release();
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW && svvr == LOW && i<2){
      Serial.println("BACKWHILELOOP");
      backwardlinetracking();     //Backward linetracking
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
      if (svvl == HIGH || svvr == HIGH){
        i+=1;
      }
    }
    if (SOFT == true) {
      Serial.println("LEFT90");    //TURN LEFT to the way to grab the second block
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
  else {                    //TURN RIGHT to the way to grab the second block
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
  }
  counter++;
  }


  else if (counter == 5)
  {
  if (SOFT == true) {       //Turn Right into the second block junction if SOFT
  forward();
  delay(250);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(300);
  while(svl==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  svl=digitalRead(sl);
 }
    }
    else {                //Turn Left into the second block junction if HARD
  Serial.println("LEFT90");
  backward();             //why it has backward here??
  delay(250);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(300);
  while(svr==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  svr=digitalRead(sr);
 }
    }
    counter ++;
  }


  else if (counter == 6)   //Sensing the second block and backwardlinetracking and turn
  {
    stop();
    ultrasensor(ultrasensor_reading());
    grab(); //Sensing and detecting the block
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW && svvr == LOW){
    Serial.println("BACKWHILELOOP");
      backwardlinetracking();
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
    }
  if (SOFT == true) {
  Serial.println("RIGHT90"); //foam then right turn
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(800);
  while(svl==LOW){
    Serial.println("INSIDEWHILELOOP");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
 }
    }
  else {                        
  Serial.println("LEFT90");    //metal then left
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(800);
  while(svr==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  svr=digitalRead(sr);
  }
    }
  counter++;
  }


  else if (counter == 7)   //Turning to the way back to the putting zone for the second block
  {
  if (SOFT == true) {
  Serial.println("LEFT90");    //left coutinue motion
  backward();
  delay(300);
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(800);
  while(svr==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  svr=digitalRead(sr);
  }
    }

  else {                        
  backward();
  delay(300);
  Serial.println("RIGHT90"); // countinue motion and turn right
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(800);
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
  release();
  svvl = LOW;
  svvr = LOW;
  while(svvl == LOW && svvr == LOW){
    Serial.println("BACKWHILELOOP");
    backwardlinetracking();     //Backward linetracking
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
  Serial.println("RIGHT90"); //foam then right turn
  RightMotor->setSpeed(150);
  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(800);
  while(svl==LOW){
  Serial.println("INSIDEWHILELOOP");
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  svl=digitalRead(sl);
 }
    }
else {                        
Serial.println("LEFT90");    //metal then left
RightMotor->setSpeed(150);
LeftMotor->setSpeed(150);
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
delay(800);
while(svr==LOW){
Serial.println("INSIDEWHILELOOP");
LeftMotor->run(BACKWARD);
RightMotor->run(FORWARD);
svr=digitalRead(sr);
  }
    }
counter++;
}


else if(counter == 10){
  forward();
  delay(500);
  stop();         //go back original position and stop moving
                 // not going to industrial
}
}
