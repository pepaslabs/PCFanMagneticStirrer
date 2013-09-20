PCFanMagneticStirrer
====================

An Adruino sketch to control a PC Fan which has been modified to act as a DIY magnetic stirrer.


Circuit Schematic
-----------------


![power supply](http://i.imgur.com/gUMD7M1.png "")

The power supply is the typical [7805](https://www.sparkfun.com/products/107) linear regulator setup.  I used a 9V DC power supply for VCC, but 12V will also work.  Surprisingly, 1uf on the input and [0.1uf](https://www.sparkfun.com/products/8375) on the output is all that is necessary for stable operation.  The 220 Ohm resistor and LED ensure the minimum 5mA load is satisfied.


![stirrer](http://i.imgur.com/Sf7x89c.png "")

The main circuit uses an NPN transistor in [common-emitter](http://en.wikipedia.org/wiki/Common_emitter) configuration to cycle the fan on and off.  During breadboarding I used a [Boarduino](http://learn.adafruit.com/boarduino-kits), and for the final circuit I used an [ATtiny85](https://www.sparkfun.com/products/9378).  The sketch size is small enough (~2.3kB) that an ATtiny45 would also work.

Nearly any [TO-92](http://en.wikipedia.org/wiki/TO-92) NPN transistor or N-channel MOSFET rated for 100mA should work for Q1.  I tested a [2N3904](https://www.sparkfun.com/products/521) and a [2N7000](http://en.wikipedia.org/wiki/2N7000), both of which worked.

D1 is a flyback diode which protects Q1.  I'm not sure it is strictly necessary, but it is good practice.  I used a [1N4148](https://www.sparkfun.com/products/8588), but nearly any diode should work.

LED2 is a status indicator which shows when Q1 is switched on.  LED2 and it's 1k resistor could also hang off the same pin which drives Q1, if you need to free up another pin.

The R2 potentiometer controls the duty cycle.  I used a 100K linear potentiometer, but 1k, 10k, etc will work just as well.
