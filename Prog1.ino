 // RGB On-Beating Fading On-Off Changing color
void Prog_1(){
           // if beat above 220 then lid led up by program counter
  Prog1 = random(1, 6);

  switch(Prog1){
    case 1: if (spectrumValue[0] > 230) {    
    for (byte rn = rb; rn < 255; rn++){
    analogWrite(ledred, rn); 
    rb = rn;
    delayMicroseconds(250);
  }}
    else 
    for (byte rn = rb; rn > 0; rn--){
    analogWrite(ledred, rn);
    rb = rn;
    delayMicroseconds(750);
  }
  break;
  
    case 2: if (spectrumValue[0] > 230) {    
    for (byte rn = rb; rn < 255; rn++){
    analogWrite(ledgreen, rn); 
    rb = rn;
    delayMicroseconds(250);
  }}
    else 
    for (byte rn = rb; rn > 0; rn--){
    analogWrite(ledgreen, rn); 
    rb = rn;
    delayMicroseconds(750);
  }
  break;
  
    case 3: if (spectrumValue[0] > 230) {    
    for (byte rn = rb; rn < 255; rn++){
    analogWrite(ledblue, rn); 
    rb = rn;
    delayMicroseconds(250);
  }}
    else 
    for (byte rn = rb; rn > 0; rn--){
    analogWrite(ledblue, rn); 
    rb = rn;
    delayMicroseconds(750);
  }
  break;

 case 4: if (spectrumValue[0] > 230) {    
    for (byte rn = rb; rn < 255; rn++){
    analogWrite(ledred, rn); 
    analogWrite(ledgreen, rn); 
    rb = rn;
    delayMicroseconds(250);
  }}
    else 
    for (byte rn = rb; rn > 0; rn--){
    analogWrite(ledred, rn); 
    analogWrite(ledgreen, rn); 
    rb = rn;
    delayMicroseconds(750);
  }
  break;

   case 5: if (spectrumValue[0] > 230) {    
    for (byte rn = rb; rn < 255; rn++){
    analogWrite(ledgreen, rn); 
    analogWrite(ledblue, rn); 
    rb = rn;
    delayMicroseconds(250);
  }}
    else 
    for (byte rn = rb; rn > 0; rn--){
    analogWrite(ledgreen, rn); 
    analogWrite(ledblue, rn); 
    rb = rn;
    delayMicroseconds(750);
  }
  break;

   case 6: if (spectrumValue[0] > 230) {    
    for (byte rn = rb; rn < 255; rn++){
    analogWrite(ledred, rn); 
    analogWrite(ledblue, rn); 
    rb = rn;
    delayMicroseconds(250);
  }}
    else 
    for (byte rn = rb; rn > 0; rn--){
    analogWrite(ledred, rn); 
    analogWrite(ledblue, rn); 
    rb = rn;
    delayMicroseconds(750);
  }
  break;
  
  }
  
}
