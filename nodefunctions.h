#include "dijkstra.h"
#include "linetracking_timedelay.h"
//NOTE TO SELF: VOID NODES WHICH MIGHT NEED CHANGE -> 23, 32, 45, 67...
int array_size = 0;
int i = 0;

void node01(){
  initialise();
  delay(1000);
  Serial.println("linetrack");
  linetrack = true;
  if (svvl==HIGH && svvr == HIGH ){
    stop();
  }
  linetrack = false;
  delay(1000);
}
void node10(){
  if (path[i+1] == 2){
    right90();
    linetrack = true;
    if (svvl==HIGH && svvr == HIGH){
      stop();
    }
    linetrack = false;
    forward();
    delay(1000);
  }

  else if (path[i+1] == 6){
    left90();
    linetrack = true;
    if (svvl==HIGH && svvr == HIGH){
      stop();
    }
    linetrack = false;
    forward();
    delay(1000);
  } 
}
void node12(){
  if (path[i+1] == 0){
    left90();
    linetrack = true;
    if (svvr == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);
  }
  
  else if (path[i+1] == 6){
    linetrack = true;
    if (svvr == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);
  }
}
void node16(){
  if (path[i+1] == 0){
    right90();
    linetrack = true;
    if (svvl==HIGH && svvr == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);
  }

  if (path[i+1] == 2){
    linetrack = true;
    if (svvl==HIGH && svvr == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);
  }
}
void node21(){
  if (path[i+1] == 3){
    right90();
    linetrack = true;
    if(svvr == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);
  }

  else if (path[i+1] == 4){
    linetrack = true;
    if(svvr == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);
  }
}
void node23(){
  if (path[i+1] == 1){
    right90();
    linetrack = true;
    if (svl == LOW && svr == LOW){
      stop();
    }
    linetrack = false;
    delay(1000);}
  
  else if (path[i+1] == 4){
    left90();
    linetrack = true;
    if (svl == LOW && svr == LOW){
      stop();
    }
    linetrack = false;
    delay(1000);}

    //ADD BLOCKDETECTION
}
void node24(){
  if (path[i+1] == 1){
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);}

  else if (path[i+1] == 3){
  left90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);}
}
void node32(){
  //backlinetrack?
  // backwards();
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  delay(1000);
}
void node42(){
  if (path[i+1] == 5){
    right90();
    linetrack = true;
    if (svvl == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);}

  else if (path[i+1] == 8){
    left90();
    linetrack = true;
    if (svvl == HIGH){
      stop();
    }
    linetrack = false;
    delay(1000);}
}
// void node45(){
//   if (path[i+1] == 2){
//     left90();
//     linetrack
//   }
// }
// void node48(){}
// void node54(){}
// void node61(){}
// void node67(){}
// void node69(){}
// void node76(){}
// void node84(){}
// void node812(){}
// void node813(){}
// void node96(){}
// void node910(){}
// void node913(){}
// void node109(){}
// void node1011(){}
// void node1012(){}
// void node1110(){}
// void node128(){}
// void node1210(){}
// void node1213(){}
// void node138(){}
// void node139(){}
// void node1312(){}

void pathnode(){
  int array_size = sizeof(path)/sizeof(path[0]);
  for (int i = array_size - 1; i>=0; i--) {
    if (path[i] == 0 && path[i-1] == 1){
    node01();
  }
  
  else if (path[i] == 1 && path[i-1] == 0){
    node10();
  }

  else if (path[i] == 1 && path[i-1] == 2){
    node12();
  }

  else if (path[i] == 1 && path[i-1] == 6){
    node16();
  }

  else if (path[i] == 2 && path[i-1] == 1){
    node21();
  }

  else if (path[i] == 2 && path[i-1] == 3){
    node23();
  }

  else if (path[i] == 2 && path[i-1] == 4){
    node24();
  }

  else if (path[i] == 3 && path[i-1] == 2){
    node32();
  }

  else if (path[i] == 4 && path[i-1] == 2){
    node42();
  }

  // else if (path[i] == 4 && path[i-1] == 5){
  //   node45();
  // }

  // else if (path[i] == 4 && path[i-1] == 8){
  //   node48();
  // }

  // else if (path[i] == 5 && path[i-1] == 4){
  //   node54();
  // }

  // else if (path[i] == 6 && path[i-1] == 1){
  //   node61();
  // }

  // else if (path[i] == 6 && path[i-1] == 7){
  //   node67();
  // }

  // else if (path[i] == 6 && path[i-1] == 9){
  //   node69();
  // }

  // else if (path[i] == 7 && path[i-1] == 6){
  //   node76();
  // }

  // else if (path[i] == 8 && path[i-1] == 4){
  //   node84();
  // }

  // else if (path[i] == 8 && path[i-1] == 12){
  //   node812();
  // }

  // else if (path[i] == 8 && path[i-1] == 13){
  //   node813();
  // }

  // else if (path[i] == 9 && path[i-1] == 6){
  //   node96();
  // }

  // else if (path[i] == 9 && path[i-1] == 10){
  //   node910();
  // }

  // else if (path[i] == 9 && path[i-1] == 13){
  //   node913();
  // }

  // else if (path[i] == 10 && path[i-1] == 9){
  //   node109();
  // }

  // else if (path[i] == 10 && path[i-1] == 11){
  //   node1011();
  // }

  // else if (path[i] == 10 && path[i-1] == 12){
  //   node1012();
  // }

  // else if (path[i] == 11 && path[i-1] == 10){
  //   node1110();
  // }

  // else if (path[i] == 12 && path[i-1] == 8){
  //   node128();
  // }

  // else if (path[i] == 12 && path[i-1] == 10){
  //   node1210();
  // }

  // else if (path[i] == 12 && path[i-1] == 13){
  //   node1213();
  // }

  // else if (path[i] == 13 && path[i-1] == 8){
  //   node138();
  // }

  // else if (path[i] == 13 && path[i-1] == 9){
  //   node139();
  // }

  // else if (path[i] == 13 && path[i-1] == 12){
  //   node1312();
  // }
}
  }
