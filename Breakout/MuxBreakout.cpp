/*
 MuxBreakout.cpp - 1 x 16 breakout board
 Based on Library for using Mayhew Labs' Mux Shield.
 Created by Mark Mayhew, December 29, 2012.
 Released into the public domain.
 */

#include "Arduino.h"
#include "MuxBreakout.h"

int _shiftReg1[16]={0};

MuxBreakout::MuxBreakout(int S0, int S1, int S2, int S3, int OUTMD)
{
    _S0 = S0;
    _S1 = S1;
    _S2 = S2;
    _S3 = S3;
    _OUTMD = OUTMD; 
    
    pinMode(_S0,OUTPUT);
    pinMode(_S1,OUTPUT);
    pinMode(_S2,OUTPUT);
    pinMode(_S3,OUTPUT);
    pinMode(_OUTMD,OUTPUT);
    digitalWrite(_OUTMD,LOW);
}

MuxBreakout::MuxBreakout()
{
    _S0 = 2;
    _S1 = 4;
    _S2 = 6;
    _S3 = 7;
    _OUTMD = 8; 
    _IO1 = A0; 
        
    pinMode(_S0,OUTPUT);
    pinMode(_S1,OUTPUT);
    pinMode(_S2,OUTPUT);
    pinMode(_S3,OUTPUT);
    pinMode(_OUTMD,OUTPUT);
    digitalWrite(_OUTMD,LOW);
}

void MuxBreakout::setMode(int mux, int mode) 
{
    switch (mux) {
        case 1:
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
            break;
        default:
            break;
    }
}

void MuxBreakout::digitalWriteMS(int mux, int chan, int val)
{
    int i;
    
    digitalWrite(_S3,LOW);                              //S3 here is LCLK
    digitalWrite(_OUTMD,HIGH);                          //set to output mode
    switch (mux) {
        case 1:
            _shiftReg1[chan] = val;                     //store value until updated again
            
            for (i=15; i>=0; i--) {
                digitalWrite(_S0,LOW);                  //S0 here is i/o1 _sclk
                digitalWrite(_IO1,_shiftReg1[i]);       //put value
                digitalWrite(_S0,HIGH);                 //lactch in value
            }
            break;
        default:
            break;   
    }
    digitalWrite(_S3,HIGH);                     //latch in ALL values
    digitalWrite(_OUTMD,LOW);                   //Exit output mode
    
}

int MuxBreakout::digitalReadMS(int mux, int chan)
{
    digitalWrite(_OUTMD,LOW);   //Set outmode off (i.e. set as input mode)
    int val;
    switch (mux) {
        case 1:
            digitalWrite(_S0, (chan&1));    
            digitalWrite(_S1, (chan&3)>>1); 
            digitalWrite(_S2, (chan&7)>>2); 
            digitalWrite(_S3, (chan&15)>>3); 

            val = digitalRead(_IO1); 
            break;
        default:
            break;
    }
    return val;
}

int MuxBreakout::analogReadMS(int mux, int chan)
{
    digitalWrite(_OUTMD,LOW);
    int val;

    digitalWrite(_S0, (chan&1));    
    digitalWrite(_S1, (chan&3)>>1); 
    digitalWrite(_S2, (chan&7)>>2); 
    digitalWrite(_S3, (chan&15)>>3); 
    
    switch (mux) {
        case 1:
            val = analogRead(_IO1); 
            break;
        default:
            break;
    }
    return val;
}
