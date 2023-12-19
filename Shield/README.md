### Mux Shield
* 48 analog inputs/digital inputs/digital outputs (in combination)
* Arduino Uno and Mega compatible
* Option for stackable headers (plug directly into Arduino and add more shields on top)
* V2: Arduino connections
  * Digital output pins D2, D4, D6, D7 (mapped to mux S0, S1, S2, S3)
  * Analog pins A0, A1, A2 (mapped to shield IO_1, IO_2, IO_3)
    * Can be programmed as Analog Inputs, Digital Inputs, or Digital Outputs  
  * Optionally uses digital pins D8, D10, D11, D12 (mapped to shield OUT_MODE, IO_SEL_1, IO_SEL_2, IO_SEL_3)
  * 1 x +5V
  * 3 x GND
* V1: Arduino connections
  * Digital output pins D2, D3, D4, D5 (mapped to mux S3, S2, S1, S0)
  * Analog pins A0, A1, A2 (mapped to shield COM1, COM2, COM3)
    * Can be programmed as Analog Inputs, Digital Inputs, or Digital Outputs
  * D9 mapped to GND, D10 mapped to LED
  * 1 x +5V
  * 2 x GND
  * RESET
* V2 Source code and examples: https://github.com/mikekellyio/muxshield  
