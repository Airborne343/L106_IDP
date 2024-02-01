void node01(){
  initialise();
  linetrack = true;
  if (svvl==HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);}

void node12(){
  left90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);}

void node23(){
  right90();
  linetrack = true;
  if (svl == LOW && svr == LOW){
    stop();
  }
  linetrack = false;
  delay(1000);}
