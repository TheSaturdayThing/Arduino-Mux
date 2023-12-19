/*
 MuxBreakout.h - 1 x 16 breakout board without latches
 Library for using Mayhew Labs' Mux Shield.
 Created by Mark Mayhew, December 20, 2012.
 Released into the public domain.
 */
#ifndef MuxBreakout_h
#define MuxBreakout_h

#include "Arduino.h"

#define DIGITAL_IN   0
#define DIGITAL_OUT  1
#define ANALOG_IN    2
#define DIGITAL_IN_PULLUP    3


class MuxBreakout
{
public:
    MuxBreakout();
    MuxBreakout(int S0, int S1, int S2, int S3);
    void setMode(int mode);
    void digitalWriteMB(int chan, int val);
    int digitalReadMB(int chan);
    int analogReadMB(int chan);
    
private:
    int _S0,_S1,_S2,_S3,_IO1;  
};

#endif
