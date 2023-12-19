//This example shows how to use the Mux Breakout for digital outputs
#include <MuxBreakout.h>

//Initialize the Mux Breakout
MuxBreakout muxBreakout;

void setup()
{
    //Set I/O as digital output
    muxBreakout.setMode(DIGITAL_OUT);  
}

int toggle = LOW;

void loop()
{
  //loop to toggle all IO 1 outputs
  for (int i=0; i<16; i++)
  {
    muxBreakout.digitalWriteMB(i,toggle);
    delay(100);
  }
  
  delay(1000);
  
  //flip the toggle
  if (toggle == LOW)
    toggle = HIGH;
  else
    toggle = LOW;

}
