/*
 MuxBreakout.h - 1 x 16 breadkout board 
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
    MuxBreakout(int S0, int S1, int S2, int S3, int OUTMD, int IO1);
    void setMode(int mux, int mode);
    void digitalWriteMS(int mux, int val);
    int digitalReadMS(int mux);
    int analogReadMS(int mux);
    
private:
    int _S0,_S1,_S2,_S3,_OUTMD,_IO1;
    int _LE1,_LE2,_LE3,_M1,_M2,_M3;    
    
    
};

#endif
