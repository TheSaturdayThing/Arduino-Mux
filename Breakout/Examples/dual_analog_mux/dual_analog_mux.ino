/* 
Based on code by Mehran Maleki
https://electropeak.com/learn/
interfacing-cd74hc4067-16-channel-analog-digital-multiplexer-with-arduino

2024-04-20

Code to scan two 16 to 1 mux breakout boards into Arduino analog input

*/

//Mux select pins
int s0 =  2; // LSB
int s1 =  4;
int s2 =  6;
int s3 =  7; // MSB

//Arduino analog inputs to read Mux "SIG" pin
int SIG_0_pin = 0;
int SIG_1_pin = 1;

// Setup
void setup(){
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  Serial.begin(9600);
}
// End Setup

// Loop
void loop(){
  //Loop through and read all 16 values from MUX0
  Serial.println("Value at Mux0 channel C0 thru C15");
  
   for(int i = 0; i < 16; i ++){
      Serial.print(readMux(i,0));  
      Serial.print('\t');
    }

  Serial.println();

  //Loop through and read all 16 values from MUX1
  Serial.println("Value at Mux1 channel C0 thru C15 ");
  
  for(int i = 0; i < 16; i ++){
    Serial.print(readMux(i,1));
    Serial.print('\t');
    }
  
  Serial.println();
  
  delay(15000); // delay so we can read the screen
}
// End Loop

// Function
float readMux(int channel, int mux){
  
  // array for select pins
  int controlPin[] = {s3, s2, s1, s0};

  // map of pin values to select a channel
  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {0,0,0,1}, //channel 1
    {0,0,1,0}, //channel 2
    {0,0,1,1}, //channel 3
    {0,1,0,0}, //channel 4
    {0,1,0,1}, //channel 5
    {0,1,1,0}, //channel 6
    {0,1,1,1}, //channel 7
    {1,0,0,0}, //channel 8
    {1,0,0,1}, //channel 9
    {1,0,1,0}, //channel 10
    {1,0,1,1}, //channel 11
    {1,1,0,0}, //channel 12
    {1,1,0,1}, //channel 13
    {1,1,1,0}, //channel 14
    {1,1,1,1}  //channel 15
  };

  // write the arduino pins to select the channel specified
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the arduino analog pin for mux SIG pin specified
  int val;

  switch (mux){
    case 0:
      val = analogRead(SIG_0_pin);
      break;
    case 1:
      val = analogRead(SIG_1_pin);
      break;
    default:
      break; 
  }

  // return reading from 0 to 1023
  return val;
}
// End Function

// End Sketch
