//This example shows how to use the Mux Breakout for analog inputs

#include <MuxBreakout.h>

//Initialize the Mux breakout
MuxBreakout muxBreakout;

void setup()
{
    //Set I/O 1 as analog input
    muxBreakout.setMode(ANALOG_IN);

    Serial.begin(28800);
}

//Array to store analog values after receiving them
int IO1AnalogVals[16];

void loop()
{
  for (int i=0; i<16; i++)
  {
    //Analog read on all 16 inputs on IO1
    IO1AnalogVals[i] = muxBreakout.analogReadMB(i);
  }
  
  //Print IO1 values for inspection
  Serial.print("IO1 analog values: ");
  for (int i=0; i<16; i++)
  {
    Serial.print(IO1AnalogVals[i]);
    Serial.print('\t');
  }
  Serial.println();
}
