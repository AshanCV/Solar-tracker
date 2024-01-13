void setup() {
  //A3  green-azimuth_right
  //A2  blue-altitude_west
  //A1  yellow-azimuth_left
  //A0  red-altitude_east
  pinMode(5,OUTPUT);  //A0  red-altitude_east
  pinMode(6,OUTPUT);  //A2  blue-altitude_west
  pinMode(9,OUTPUT);  //A1  yellow-azimuth_left
  pinMode(10,OUTPUT); //A3  green-azimuth_right
  
  Serial.begin(9600);

}

void loop() {
  int alE;
  int alW;
  int azR;
  int azL;
  
 int tot_alE = 0;
 int tot_alW = 0;
 int tot_azR = 0;
 int tot_azL = 0;
 
for(int i=1; i<10; i++){
  alE = analogRead(A0);
  alW = analogRead(A2);
  azR = analogRead(A3);
  azL = analogRead(A1);
 
 

 tot_alE = tot_alE + alE;
 tot_alW = tot_alW + alW;
 tot_azR = tot_azR + azR;
 tot_azL = tot_azL + azL;

 
}

  alE = tot_alE/10;
  alW = tot_alW/10;
  azR = tot_azR/10;
  azL = tot_azL/10;

/*Serial.print("alE "); Serial.print(alE);
Serial.print("  alW "); Serial.print(alW);
Serial.print("  azR "); Serial.print(azR);
Serial.print("  azL "); Serial.println(azL);*/

if(alE+2<alW-2){
  analogWrite(10,80);
  digitalWrite(9,LOW);
}
else if(alW+2<alE-2){
  analogWrite(9,80);
  digitalWrite(10,LOW);
}
else{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

//**************************************************//

if(azR+2<azL-2){
  analogWrite(5,60);
  digitalWrite(6,LOW);
}
else if(azL+2<azR-2){
  analogWrite(6,60);
  digitalWrite(5,LOW);
}
else{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
}



 

}
