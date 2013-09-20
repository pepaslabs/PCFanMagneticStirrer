PCFanMagneticStirrer
====================

An Adruino sketch to control a PC Fan which has been modified to act as a DIY magnetic stirrer.


Circuit Schematic
-----------------


![power supply](http://i.imgur.com/gUMD7M1.png "")

The power supply is the typical 7805 linear regulator setup.  Surprisingly, 0.1uf on the output results in stable operation.  The 220 Ohm resistor and LED ensure the minimum 5mA load is satisfied.


![stirrer](http://i.imgur.com/Sf7x89c.png "")

The main circuit uses an NPN transistor in common-emitter configuration to cycle the fan on and off.

Nearly any TO-92 NPN transistor or N-channel MOSFET should work as Q1.  I tested a 2N3904 and a 2N7000, both of which worked.

D1 is a flyback diode which protects Q1.  I'm not sure it is strictly necessary, but it is good practice.  I used a 1N4148, but nearly any diode should work.

LED2 and it's 1k resistor could also hang off the same pin which drives Q1, if you need to free up another pin.

The R2 potentiometer controls the duty cycle.  Nearly any potentiometer should work.
