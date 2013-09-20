/*
PCFanMagneticStirrer - Control a PC fan-based magnetic stirrer using
an Arduino.
https://github.com/cellularmitosis/PCFanMagneticStirrer
v0.1 (Sept 15, 2013)

Copyright (c) 2013 Jason Pepas

This software is released under the terms of the MIT License:

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#include "Oversampler.h" // https://github.com/cellularmitosis/Oversampler


/*
from hardware/attiny/variants/tiny8/pins_arduino.h:

// ATMEL ATTINY45 / ARDUINO
//
//                  +-\/-+
// Ain0 (D 5) PB5  1|    |8  Vcc
// Ain3 (D 3) PB3  2|    |7  PB2 (D 2)  Ain1
// Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
//            GND  4|    |5  PB0 (D 0) pwm0
//                  +----+
*/

int8_t potPin = 1; // physical pin 2 == analog pin 1.
int8_t ledPin = 3;
int8_t mosfetPin = 4;


float freq = 3.0;
float minDutyCycle = 0.22;
float maxDutyCycle = 0.66;
uint8_t turnOffRegion = 24;


OversamplerData oversampler;


void setup() 
{
  initOversamplerData(&oversampler);

  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(mosfetPin, OUTPUT);
} 


uint16_t potVal = 0;
float period = (1.0 / freq) * 1000.0;

void loop() 
{
  potVal = analogRead16x(&oversampler, potPin);
  
  if (potVal < turnOffRegion)
  {
    digitalWrite(mosfetPin, LOW);
    digitalWrite(ledPin, LOW);
    return;
  }

  float normalized = potVal / 1023.0;
  float dutyCycle = (normalized * (maxDutyCycle - minDutyCycle)) + minDutyCycle;
  
  float onTime = dutyCycle * period;
  float offTime = period - onTime;
  
  digitalWrite(mosfetPin, HIGH);
  digitalWrite(ledPin, HIGH);

  delay(onTime);
  
  digitalWrite(mosfetPin, LOW);
  digitalWrite(ledPin, LOW);
  
  delay(offTime);
}

