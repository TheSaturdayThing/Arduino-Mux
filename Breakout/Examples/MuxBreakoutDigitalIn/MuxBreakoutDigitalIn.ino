//This example shows how to use the Mux Breakout for digital inputs
#include <MuxBreakout.h>

//Initialize the Mux Breakout
MuxBreakout muxBreakout;

void setup()
{
    //Set IO1 as digital input
    //use DIGITAL_IN in place of DIGITAL_IN_PULLUP if internal pullups are not need
    muxBreakout.setMode(DIGITAL_IN_PULLUP);
    
    Serial.begin(28800);
}

//Arrays to store digital values
int IO1DigitalVals[16];

void loop()
{
  for (int i=0; i<16; i++)
  {
    //Digital read on all 16 inputs on IO1
    IO1DigitalVals[i] = muxShield.digitalReadMB(i);
  }
  
  //Print IO 1 values for inspection
  Serial.print("IO1 analog values: ");
  for (int i=0; i<16; i++)
  {
    Serial.print(IO1DigitalVals[i]);
    Serial.print('\t');
  }
  Serial.println();
}
