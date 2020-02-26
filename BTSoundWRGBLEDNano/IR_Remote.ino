//

void IR_Remote(){
  if (irrecv.decode(&results)) {

//Power button
     if (results.value==0xFF02FD){ //Code to turn the LED ON/OFF
    if(wn==0){ // if the LED was turned off, then we turn it on 
      wn=255; //LED is now turned on
      wo = 1;
      analogWrite(ledwhite, wn);

    }
    else{
      wn=0;
      wo = 0;
      analogWrite(ledwhite, wn); //if the LED was turned on, then we turn it off
    }}

//Brightness lower button
 if (results.value==0xFFBA45 && wo==1){ //Code to decrease the brightness
    if(wn-255/5<0){ 
      analogWrite(ledwhite,wn);
    }
    else{
    wn=wn-255/5;
      analogWrite(ledwhite,wn);
  }}
//Brightness higher button
  if (results.value==0xFF3AC5 && wo==1){ //Code to increase the brightness
    if(wn+255/5>255){
      analogWrite(ledwhite,wn);
    }
    else{    
    wn=wn+255/5;
      analogWrite(ledwhite,wn);
  }}

 if (results.value==0xFF30CF){
   prog = 1;
  int p = 1;
delay(10);

  }

   if (results.value==0xFFB04F){
   prog = 1;
  int p = 1;
  delay(10);

  }

   if (results.value==0xFF708F){
   prog = 1;
  int p = 1;
  delay(10);

  }
  
  delay(50);
//Serial.println(results.value, HEX);
           irrecv.resume();

   }
}
