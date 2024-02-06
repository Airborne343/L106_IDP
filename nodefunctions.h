#include "dijkstra.h"
#include "linetracking_timedelay.h"
//NOTE TO SELF: VOID NODES WHICH MIGHT NEED CHANGE:
//123 (pickup)
//423 (pickup)
//91011 (pickup)
//121011 (pickup)

//Node 0 -> 1
void node01(){
  initialise();
  delay(1000);
  linetrack = true;
  if (svvl==HIGH && svvr == HIGH ){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 1 -> 0 (if the previous node was 2)
void node210(){
  right90();
  linetrack = true;
  if (svvl==HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  forward();
  delay(1000);
}
//Node 1 -> 0 (if the previous node was 6)
void node610(){
  left90();
  linetrack = true;
  if (svvl==HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  forward();
  delay(1000);
}
//Node 1 -> 2 (if the previous node was 0)
void node012(){
  left90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 1 -> 2 (if the previous node was 6)  
void node612(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 1 -> 6 (if the previous node was 0)
void node016(){
  right90();
  linetrack = true;
  if (svvl==HIGH && svvr == HIGH ){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 1 -> 6 (if the previous node was 2)
void node216(){
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);  
}
//Node 2 -> 1 (if the previous node was 3)
void node321(){
  right90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 2 -> 1 (if the previous node was 4)
void node421(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 2 -> 3 (if the previous node was 1)
void node123(){
  right90();
  linetrack = true;
  if (svl == LOW && svr == LOW){
    stop();
  }
  linetrack = false;
  ultrasensor();
  //pickup
  delay(1000);
}
//Node 2 -> 3 (if the previous node was 4)
void node423(){
  left90();
  linetrack = true;
  if (svl == LOW && svr == LOW){
    stop();
  }
  linetrack = false;
  ultrasensor();
  //pickup
  delay(1000);
}
//Node 2 -> 4 (if the previous node was 3)
void node324(){
  left90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 2 -> 4 (if the previous node was 1)
void node124(){
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 3 -> 2
void node32(){
  backward();
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  delay(1000);
}
//Node 4 -> 2 (if the previous node was 5)
void node542(){
  right90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 4 -> 2 (if the previous node was 8)
void node842(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 4 -> 5 (if the previous node was 2)
void node245(){
  left90();
  linetrack = true;
  if (distance < 7){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 4 -> 5 (if the previous node was 8)
void node845(){
  linetrack = true;
  if (distance < 7){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 4 -> 8 (if the previous node was 2)
void node248(){
  right90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 4 -> 8 (if the previous node was 5)
void node548(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 5 -> 4
void node54(){
  backward();
  delay(750);
  left90();
  left90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);  

}
//Node 6 -> 1 (if the previous node was 7)
void node761(){
  left90();
  linetrack = true;
  if (svvr == LOW){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 6 -> 1 (if the previous node was 9)
void node961(){
  right90();
  linetrack = true;
  if (svvr == LOW){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 6 -> 7 (if the previous node was 1)
void node167(){
  right90();
  linetrack = true;
  if (distance < 7){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 6 -> 7 (if the previous node was 9)
void node967(){
  linetrack = true;
  if (distance < 7){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 6 -> 9 (if the previous node was 1)
void node169(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 6 -> 9 (if the previous node was 7)
void node769(){
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 7 -> 6 
void node76(){
  backward();
  delay(750);
  left90();
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 8 -> 4 (if the previous node was 12) 
void node1284(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 8 -> 4 (if the previous node was 13) 
void node1384(){
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 8 -> 12 (if the previous node was 4) 
void node4812(){
  right90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 8 -> 12 (if the previous node was 13) 
void node13812(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 8 -> 13 (if the previous node was 4) 
void node4813(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 8 -> 13 (if the previous node was 12) 
void node12813(){
  right90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 9 -> 6 (if the previous node was 10) 
void node1096(){
  right90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 9 -> 6 (if the previous node was 13) 
void node1396(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 9 -> 10 (if the previous node was 6) 
void node6910(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 9 -> 10 (if the previous node was 13) 
void node13910(){
  right90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 9 -> 13 (if the previous node was 6) 
void node6913(){
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 9 -> 13 (if the previous node was 10) 
void node10913(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 10 -> 9 (if the previous node was 11) 
void node11109(){
  right90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 10 -> 9 (if the previous node was 12) 
void node12109(){
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 10 -> 11 (if the previous node was 9) 
void node91011(){
  left90();
  linetrack = true;
  if (svl == LOW && svr == LOW){ 
    stop();
  }
  linetrack = false;
  ultrasensor();
  //pickup
  delay(1000);
}
//Node 10 -> 11 (if the previous node was 12) 
void node121011(){
  right90();
  linetrack = true;
  if (svl == LOW && svr == LOW){ 
    stop();
  }
  linetrack = false;
  ultrasensor();
  //pickup
  delay(1000);
}
//Node 10 -> 12 (if the previous node was 9) 
void node91012(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 10 -> 12 (if the previous node was 11) 
void node111012(){
  left90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 11 -> 10
void node1110(){
  backward();
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  delay(1000);
}
//Node 12 -> 8 (if the previous node was 10) 
void node10128(){
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 12 -> 8 (if the previous node was 13) 
void node13128(){
  right90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 12 -> 10 (if the previous node was 8) 
void node81210(){
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 12 -> 10 (if the previous node was 13) 
void node131210(){
  left90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 12 -> 13 (if the previous node was 8) 
void node81213(){
  left90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 12 -> 13 (if the previous node was 10) 
void node101213(){
  right90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 13 -> 8 (if the previous node was 9) 
void node9138(){
  forward();
  delay(300);
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 13 -> 8 (if the previous node was 12) 
void node12138(){
  left90();
  linetrack = true;
  if (svvl == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 13 -> 9 (if the previous node was 8) 
void node8139(){
  forward();
  delay(300);
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 13 -> 9 (if the previous node was 12) 
void node12139(){
  right90();
  linetrack = true;
  if (svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 13 -> 12 (if the previous node was 8) 
void node81312(){
  right90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}
//Node 13 -> 12 (if the previous node was 9) 
void node91312(){
  left90();
  linetrack = true;
  if (svvl == HIGH && svvr == HIGH){
    stop();
  }
  linetrack = false;
  delay(1000);
}

void pathnode(){
  int array_size = sizeof(path)/sizeof(path[0]);
  for (int i = array_size - 1; i>=0; i--) {
    if (path[i] == 0 && path[i-1] == 1){
      node01();
  }
  
  else if (path[i] == 1 && path[i-1] == 0){
    if (path[i+1] == 2){
      node210();
    }

    else if (path[i+1] == 6){
      node610();
    }
    
  }

  else if (path[i] == 1 && path[i-1] == 2){
    if (path[i+1] == 0){
      node012();
    }

    else if (path[i+1] == 6){
      node612();
    }
  }

  else if (path[i] == 1 && path[i-1] == 6){
    if (path[i+1] == 0){
      node016();
    }

    else if (path[i+1] == 2){
      node216();
    }
  }

  else if (path[i] == 2 && path[i-1] == 1){
    if (path[i+1] == 3){
      node321();
    }

    else if (path[i+1] == 4){
      node421();
    }
  }

  else if (path[i] == 2 && path[i-1] == 3){
    if (path[i+1] == 1){
      node123();
    }

    else if (path[i+1] == 4){
      node423();
    }
  }

  else if (path[i] == 2 && path[i-1] == 4){
    if (path[i+1] == 3){
      node324();
    }

    else if (path[i+1] == 1){
      node124();
    }
  }

  else if (path[i] == 3 && path[i-1] == 2){
    node32();
  }

  else if (path[i] == 4 && path[i-1] == 2){
    if (path[i+1] == 5){
      node542();
    }

    else if (path[i+1] == 8){
      node842();
    }
  }

  else if (path[i] == 4 && path[i-1] == 5){
    if (path[i+1] == 2){
      node245();
    }

    else if (path[i+1] == 8){
      node845();
    }
  }

  else if (path[i] == 4 && path[i-1] == 8){
    if (path[i+1] == 2){
      node248();
    }

    else if (path[i+1] == 5){
      node548();
    }
  }

  else if (path[i] == 5 && path[i-1] == 4){
    node54();
  }

  else if (path[i] == 6 && path[i-1] == 1){
    if (path[i+1] == 7){
      node761();
    }

    else if (path[i+1] == 9){
      node961();
    }
  }

  else if (path[i] == 6 && path[i-1] == 7){
    if (path[i+1] == 1){
      node167();
    }

    else if (path[i+1] == 9){
      node967();
    }
  }

  else if (path[i] == 6 && path[i-1] == 9){
    if (path[i+1] == 1){
      node169();
    }

    else if (path[i+1] == 7){
      node769();
    }
  }

  else if (path[i] == 7 && path[i-1] == 6){
    node76();
  }

  else if (path[i] == 8 && path[i-1] == 4){
    if (path[i+1] == 12){
      node1284();
    }

    else if (path[i+1] == 13){
      node1384();
    }
  }

  else if (path[i] == 8 && path[i-1] == 12){
    if (path[i+1] == 4){
      node4812();
    }

    else if (path[i+1] == 13){
      node13812();
    }
  }

  else if (path[i] == 8 && path[i-1] == 13){
    if (path[i+1] == 4){
      node4813();
    }

    else if (path[i+1] == 12){
      node12813();
    }
  }

  else if (path[i] == 9 && path[i-1] == 6){
    if (path[i+1] == 10){
      node1096();
    }

    else if (path[i+1] == 13){
      node1396();
    }
  }

  else if (path[i] == 9 && path[i-1] == 10){
    if (path[i+1] == 6){
      node6910();
    }

    else if (path[i+1] == 13){
      node13910();
    }
  }

  else if (path[i] == 9 && path[i-1] == 13){
    if (path[i+1] == 6){
      node6913();
    }

    else if (path[i+1] == 10){
      node10913();
    }
  }

  else if (path[i] == 10 && path[i-1] == 9){
    if (path[i+1] == 11){
      node11109();
    }

    else if (path[i+1] == 12){
      node12109();
    }
  }

  else if (path[i] == 10 && path[i-1] == 11){
    if (path[i+1] == 9){
      node91011();
    }

    else if (path[i+1] == 12){
      node121011();
    }
  }

  else if (path[i] == 10 && path[i-1] == 12){
    if (path[i+1] == 9){
      node91012();
    }

    else if (path[i+1] == 11){
      node111012();
    }
  }

  else if (path[i] == 11 && path[i-1] == 10){
    node1110();
  }

  else if (path[i] == 12 && path[i-1] == 8){
    if (path[i+1] == 10){
      node10128();
    }

    else if (path[i+1] == 13){
      node13128();
    }
  }

  else if (path[i] == 12 && path[i-1] == 10){
    if (path[i+1] == 8){
      node81210();
    }

    else if (path[i+1] == 13){
      node131210();
    }
  }

  else if (path[i] == 12 && path[i-1] == 13){
    if (path[i+1] == 8){
      node81213();
    }

    else if (path[i+1] == 10){
      node101213();
    }
  }

  else if (path[i] == 13 && path[i-1] == 8){
    if (path[i+1] == 9){
      node9138();
    }

    else if (path[i+1] == 12){
      node12138();
    }
  }

  else if (path[i] == 13 && path[i-1] == 9){
    if (path[i+1] == 8){
      node8139();
    }

    else if (path[i+1] == 12){
      node12139();
    }
  }

  else if (path[i] == 13 && path[i-1] == 12){
    if (path[i+1] == 8){
      node81312();
    }

    else if (path[i+1] == 9){
      node91312();
    }
  }
}
  }
