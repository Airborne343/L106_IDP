int counter = 8;
//count the numbers of turn  //Remember to change back counter to 0, uncomment initialise, soft=false
int i =0;


void counterfunction(){
// Serial.println(counter);
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


else if (counter == 2) //Sensing and detecting the block
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
    while(svvl == LOW && svvr == LOW){
      Serial.println("BACKWARD");
      backward();    
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

else if (counter==4)    //Putting the block and linetracking until the second line
  {
    LeftMotor->run(RELEASE);
    RightMotor->run(RELEASE);
    puttingdown();
    release();
    svvl = LOW;
    svvr = LOW;
    backward();
    delay(1000);
    if (SOFT==true){
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
    }
    else{
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(1500);
    svl=digitalRead(sl);
    while(svl==LOW){
    Serial.println("TURN180");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
    }
    }
    i=0;
    while(i<2){
      linetracking();
      Serial.println("LINETRACKING");
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
      if (svvl == HIGH || svvr == HIGH){
        Serial.println("DETECTWHITELINE");
        i+=1;
        delay(800);
      }
    }
if (SOFT == false) {
        Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if HARD
        backward();
        delay(1000);
        RightMotor->setSpeed(200);
        LeftMotor->setSpeed(0);
        LeftMotor->run(FORWARD);
        RightMotor->run(FORWARD);
        delay(2500);
        while(svr==LOW){
            Serial.println("INSIDEWHILELOOP");
            LeftMotor->run(BACKWARD);
            RightMotor->run(FORWARD);
            svr=digitalRead(sr);
        }
      }
else {                        //Turn RIGHT to the way back to the zone if SOFT
    Serial.println("RIGHT90"); 
    backward();
    delay(1000);
    RightMotor->setSpeed(0);
    LeftMotor->setSpeed(200);
    LeftMotor->run(FORWARD);
    RightMotor->run(FORWARD);
    delay(2500);
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
  forward();             
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
    while(svvl == LOW && svvr == LOW){
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


  else if (counter == 8){   //Putting the second block and backwardlinetracking till second line
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
  puttingdown();
  release();
  svvl = LOW;
  svvr = LOW;
  backward();
  delay(1000);
  if (SOFT==true){
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
    }
    else{
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(1500);
    svl=digitalRead(sl);
    while(svl==LOW){
    Serial.println("TURN180");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
    }
    }
    i=0;
  while(i<2){
    linetracking();
    Serial.println("LINETRACKING");
    svvr=digitalRead(ssr);
    svvl=digitalRead(ssl);
    if (svvl == HIGH || svvr == HIGH){
      Serial.println("DETECTWHITELINE");
      i+=1;
      delay(800);
    }
  }
  
  if (SOFT == false) { 
      Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if HARD
      backward();
      delay(1000);
      RightMotor->setSpeed(200);
      LeftMotor->setSpeed(0);
      LeftMotor->run(FORWARD);
      RightMotor->run(FORWARD);
      delay(2500);
      while(svr==LOW){
          Serial.println("INSIDEWHILELOOP");
          LeftMotor->run(BACKWARD);
          RightMotor->run(FORWARD);
          svr=digitalRead(sr);
      }
      svvr = LOW;
      while(svvr==LOW){
        linetracking();
        svvr = digitalRead(ssr);
      }
      }
  
  else {                        //Turn RIGHT to the way back to the zone if SOFT
      Serial.println("RIGHT90"); 
      backward();
      delay(1000);
      RightMotor->setSpeed(0);
      LeftMotor->setSpeed(200);
      LeftMotor->run(FORWARD);
      RightMotor->run(FORWARD);
      delay(2500);
      while(svl==LOW){
          Serial.println("INSIDEWHILELOOP");
          LeftMotor->run(FORWARD);
          RightMotor->run(BACKWARD);
          svl=digitalRead(sl);
      }
      }
    counter++;
  }

else if (counter == 9){   //Reaching the junction next to the industrial zone
Serial.println('hello');
  if (SOFT == true) {       //Turn left into industrial zone if SOFT
    Serial.println("LEFT90");
    forward();            
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


    else {                //Turn right into industrial zone if HARD
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
      delay(500);
    }
    detect = false;
    while (detect == false){
      linetracking();
      distancesensordetection();
    }
    //left();
    //delay(1000);
    while (ultrasensor_reading() > 12){  //Change the value if needed
      forward();
    }
    ultrasensor(ultrasensor_reading()); 
    grab();
    delay(700);
    lift();
    backward();
    delay(400);
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW && svvr == LOW){
      Serial.println("BACKWARD");
      backward();     //Backward linetracking
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
    }
    backward();
    delay(500);
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
  counter++;
}


else if (counter == 10)         // return to base
{
  Serial.println(counter);
  if (SOFT == true) {       //Turn right out of industrial zone if SOFT
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
    
    else {                //Turn left out of industrial zone if HARD
      Serial.println("LEFT90");
      forward();            
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

else if(counter == 11)      //turning to the line that drops block
{ 
  Serial.println(counter);
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

else if(counter == 12)
{ 
  Serial.println(counter);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
  puttingdown();
  release();
  svvl = LOW;
  svvr = LOW;
  backward();
  delay(1000);
    if (SOFT==true){
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
    }
    else{
    RightMotor->setSpeed(150);
    LeftMotor->setSpeed(150);
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    delay(1500);
    svl=digitalRead(sl);
    while(svl==LOW){
    Serial.println("TURN180");
    LeftMotor->run(FORWARD);
    RightMotor->run(BACKWARD);
    svl=digitalRead(sl);
    }
    }
  i=0;
  while(i<2){
    linetracking();
    Serial.println("LINETRACKING");
    svvr=digitalRead(ssr);
    svvl=digitalRead(ssl);
    if (svvl == HIGH || svvr == HIGH){
      Serial.println("DETECTWHITELINE");
      i+=1;
      delay(800);
    }
  }
  
  if (SOFT == false) {
      Serial.println("LEFT90");    //TURN LEFT to the way back to the zone if HARD
      backward();
      delay(1000);
      RightMotor->setSpeed(200);
      LeftMotor->setSpeed(0);
      LeftMotor->run(FORWARD);
      RightMotor->run(FORWARD);
      delay(2500);
      while(svr==LOW){
          Serial.println("INSIDEWHILELOOP");
          LeftMotor->run(BACKWARD);
          RightMotor->run(FORWARD);
          svr=digitalRead(sr);
      }
      }
  else {                        //Turn RIGHT to the way back to the zone if SOFT
      Serial.println("RIGHT90"); 
      backward();
      delay(1000);
      RightMotor->setSpeed(0);
      LeftMotor->setSpeed(200);
      LeftMotor->run(FORWARD);
      RightMotor->run(FORWARD);
      delay(2500);
      while(svl==LOW){
          Serial.println("INSIDEWHILELOOP");
          LeftMotor->run(FORWARD);
          RightMotor->run(BACKWARD);
          svl=digitalRead(sl);
      }
      }
    counter++;

}

else if (counter == 13)    //reaching junction next to the industrial zone
{ 
  Serial.println(counter);
  if (SOFT == true) {       //Turn left into industrial zone if SOFT
    Serial.println("LEFT90");
    forward();            
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
    else {                //Turn right into industrial zone if HARD
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
  counter++;
}

else if (counter == 14)
{
  Serial.println(counter);
  Serial.println("LEFT90");
  forward();            
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
    detect = false;
    while (detect == false){
      linetracking();
      distancesensordetection();
    }
    right();
    delay(1000);
    while (ultrasensor_reading() > 50){  //Change the value if needed
      forward();
    }
    ultrasensor(ultrasensor_reading()); 
    grab();
    delay(700);
    lift();
    backward();
    delay(400);
    svvl = LOW;
    svvr = LOW;
    while(svvl == LOW && svvr == LOW){
      Serial.println("BACKWARD");
      backward();    
      svvr=digitalRead(ssr);
      svvl=digitalRead(ssl);
    }
    backward();
    delay(500);
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
      counter++;
    }


else if (counter == 15)
{
  Serial.println(counter);
  Serial.println("LEFT90");
  forward();            
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

else if (counter == 16)         // return to base
{
  Serial.println(counter);
  if (SOFT == true) {       //Turn right out of industrial zone if SOFT
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
    
    else {                //Turn left out of industrial zone if HARD
      Serial.println("LEFT90");
      forward();            
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

else if(counter == 17)      //turning to the line that drops block
{ 
  Serial.println(counter);
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

else if (counter == 18)
{ 
  Serial.println(counter);  //Putting the second block and backwardlinetracking and turning into the junction
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


else if (counter == 19){
  Serial.println(counter);   //Turning back to the end zone
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



else if(counter == 20){
  Serial.println(counter);        //Go back to the starting point
  forward();
  delay(1500);
  Serial.println(counter);
}
}
