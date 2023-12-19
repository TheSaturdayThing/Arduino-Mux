/*
 MuxBreakout.cpp - 1 x 16 breakout board without latches
 Based on Library for using Mayhew Labs' Mux Shield.
 Created by Mark Mayhew, December 29, 2012.
 Released into the public domain.
 */

#include "Arduino.h"
#include "MuxBreakout.h"

int _shiftReg1[16]={0};

MuxBreakout::MuxBreakout(int S0, int S1, int S2, int S3)
{
    _S0 = S0;
    _S1 = S1;
    _S2 = S2;
    _S3 = S3;
    
    pinMode(_S0,OUTPUT);
    pinMode(_S1,OUTPUT);
    pinMode(_S2,OUTPUT);
    pinMode(_S3,OUTPUT);
}

MuxBreakout::MuxBreakout()
{
    _S0 = 2;
    _S1 = 4;
    _S2 = 6;
    _S3 = 7;
    _IO1 = A0; 
        
    pinMode(_S0,OUTPUT);
    pinMode(_S1,OUTPUT);
    pinMode(_S2,OUTPUT);
    pinMode(_S3,OUTPUT);
}

void MuxBreakout::setMode(int mode) 
{
    switch (mode) {
        case DIGITAL_IN:
            pinMode(_IO1,INPUT);
            break;
        case DIGITAL_IN_PULLUP:
            pinMode(_IO1,INPUT_PULLUP);
            break;
        case DIGITAL_OUT:
            pinMode(_IO1,OUTPUT);
            break;
        case ANALOG_IN:
            break;
        default:
            break; 
    }
}

void MuxBreakout::digitalWriteMB(int chan, int val)
{
   
    digitalWrite(_S0, (chan&1));    
    digitalWrite(_S1, (chan&3)>>1); 
    digitalWrite(_S2, (chan&7)>>2); 
    digitalWrite(_S3, (chan&15)>>3); 

    digitalWrite(_IO1, val); 
}

int MuxBreakout::digitalReadMB(int chan)
{
    int val;
   
    digitalWrite(_S0, (chan&1));    
    digitalWrite(_S1, (chan&3)>>1); 
    digitalWrite(_S2, (chan&7)>>2); 
    digitalWrite(_S3, (chan&15)>>3); 

    val = digitalRead(_IO1); 
  
    return val;
}

int MuxBreakout::analogReadMB(int chan)
{
    int val;

    digitalWrite(_S0, (chan&1));    
    digitalWrite(_S1, (chan&3)>>1); 
    digitalWrite(_S2, (chan&7)>>2); 
    digitalWrite(_S3, (chan&15)>>3); 
   
    val = analogRead(_IO1); 

    return val;
}
