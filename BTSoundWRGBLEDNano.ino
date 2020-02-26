
// (Arduino) Bluetooth Sound WRGB Led with ir-remote control V1.1
// 2020/02/25 by KiritoTech
// http://kiritotechh.simplesite.com
// Circuit: Nano
// Voltage +12V RAW input for controllers, +12v for Led strip.
// Getting any IR-remote code see Example IRrecvDemo.ino

/*Part list:
 * 
Arduino Nano
XY-BT-Mini  ->  https://nl.aliexpress.com/item/33024751119.html?spm=a2g0o.productlist.0.0.3ae824eaZ95bPh&algo_pvid=e7d9f331-36b9-46ac-8c4d-c60769df32dc&algo_expid=e7d9f331-36b9-46ac-8c4d-c60769df32dc-10&btsid=0b0a187915827311256655917e2999&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_
IR 3 pin receiver
U1 = MSGEQ7
R1 = 200k
R2 = 20k
R3 = 20k
R4 = 10K
R5 = 10k
R6 = 10k
R7 = 10k
C1 = 47uF 16v
C2 = 47uF 16v
C3 = 10nF
C4 = 100nF
C5 = 33pF
Q1 = IRFZ44NPBF
Q2 = IRFZ44NPBF
Q3 = IRFZ44NPBF
Q4 = IRFZ44NPBF
P1 = 2 pin screw terminal  ->  https://nl.aliexpress.com/item/32867118953.html?spm=a2g0o.productlist.0.0.67a963c8SJlClL&algo_pvid=c4a89c95-7510-4cd3-848b-b2bd37064f5e&algo_expid=c4a89c95-7510-4cd3-848b-b2bd37064f5e-20&btsid=0b0a187915827311934506756e2999&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_
P2 = 2 pin screw terminal
P3 = 3 pin screw terminal
 */

#include <IRremote.h>

#define analogPin A1     //connects to A1 the Output of the MSGEQ7, Measures the voltage value for each frequency band (0V-5V) 
#define strobePin 11     //connects to 11 the Strobe Pin of the MSGEQ7, controls the Multiplexer and thus switches between the frequency bands
#define resetPin 12      //connects to 12 the Reset Pin of the MSGEQ7, controls the Multiplexer and let's it restart with the lowest frequency band
#define ledred 5         //connects to  5 the Gate of the BUZ11 MOSFET of the RED LED (Bass) and creates a PWM signal with variable duty cycle which depends of the peak value of the low frequencies to control the brightness of the RED LED 
#define ledgreen 6       //connects to  6 the Gate of the BUZ11 MOSFET of the GREEN LED (Middle) and creates a PWM signal with variable duty cycle which depends of the peak value of the middle frequencies to control the brightness of the GREEN LED
#define ledblue 9        //connects to  9 the Gate of the BUZ11 MOSFET of the BLUE LED (High) and creates a PWM signal with variable duty cycle which depends of the peak value of the high frequencies to control the brightness of the BLUE LED
#define ledwhite 3       //connects to  3 the Gate of the BUZ11 MOSFET of the WHITE LED (High) and creates a PWM signal with variable duty cycle which depends of the peak value of the high frequencies to control the brightness of the WHITE LED
int spectrumValue[7];    //Integer variable to store the 10bit values of the frequency bands
int filter=180;          //There will always be some noises which the analogpin will receive. With this filter value we can ignore the very low peaks of the output of the MSGEQ7. Fell free to adjust this value to your liking
#define RECV_PIN 10      //data out of IR receiver connects to pin 10


byte rn = 0;
byte rb = 0;
byte gn = 0;
byte gb = 0;
byte bn = 0;
byte bb = 0;
byte wn = 255;
byte wb = 0;
byte wo = 1;
byte p = 1;
byte prog = 1;

byte Prog1   = 1; // 1
byte Prog2   = 10; // 2
byte Prog3   = 20; // 3

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {

  pinMode(analogPin, INPUT);  //defines analog pin A0 as an Input
  pinMode(strobePin, OUTPUT); //defines strobe pin 13 as Output
  pinMode(resetPin, OUTPUT);  //defines reset pin 12 as Output
  pinMode(ledred, OUTPUT);    //defines ledred pin 9 as Output
  pinMode(ledblue, OUTPUT);   //defines ledblue pin 5 as Output
  pinMode(ledgreen, OUTPUT);  //defines ledgreen pin 10 as Output
  pinMode(ledwhite, OUTPUT);  //defines ledgreen pin 6 as Output
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);
 irrecv.enableIRIn();         //Start the receiver
 analogWrite(ledwhite, wn);   //turn white led on when wallswitch turned on
 
}

#define fade(x,y) if (x>y) x--; else if (x<y) x++;

void loop() {
  //Serial.begin(9600);
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);              //change from high to low starts the output of the mutliplexer from the beginning 
  for (int i=0;i<7;i++){                    //for loop goes through this cycle 7 times to get the values for each frequency band
    digitalWrite(strobePin, LOW);           //puts strobe pin low to output the frequency band
    delayMicroseconds(30);                  //wait until output value of MSGEQ7 can be measured (see timing diagram in the datasheet)
    spectrumValue[i]=analogRead(analogPin); //put analog DC value in the spectrumValue variable
    if (spectrumValue[i]<filter){ 
      spectrumValue[i]=0;}                  //if the received value is below the filter value it will get set to 0
    spectrumValue[i]=map(spectrumValue[i], 0,1023,0,255); //transform the 10bit analog input value to a suitable 8bit PWM value
  //  Serial.print(spectrumValue[i]);         //outputs the PWM value on the serial monitor 
   // Serial.print(" ");
    digitalWrite(strobePin, HIGH);          //puts the strobe pin high to get ready for the next cycle


  }
{
switch (prog) {
      case 1:   
        IR_Remote();
        Prog_1();
        //Serial.println("Prog1");
        break;
}
}
}

   
