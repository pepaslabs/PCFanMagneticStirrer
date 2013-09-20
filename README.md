PCFanMagneticStirrer
====================

An Adruino sketch to control a PC Fan which has been modified to act as a DIY [magnetic stirrer](http://en.wikipedia.org/wiki/Magnetic_stirrer).


![stirrer](http://i.imgur.com/y3wdtbe.jpg "")


Arduino Sketch
--------------


![sketch](http://i.imgur.com/x4oJcz8.png "")

This sketch controls the speed of the PC fan using extremely low frequency (3 Hz) [PWM](http://en.wikipedia.org/wiki/Pulse-width_modulation).  A potentiometer is used to control the duty cycle of the PWM.

I experimented with lots of different combinations of frequency and duty cycle, and 3 Hz with a duty cycle ranging from 22% to 66% seemed to work best.  I had initially spent a bunch of time trying to implement feedback control using the tachometer pin of the PC fan, but open loop control ended up being adequate and more reliable.

Note: this sketch uses the [Oversampler library](https://github.com/cellularmitosis/Oversampler).


Circuit Schematic
-----------------


![power supply](http://i.imgur.com/gUMD7M1.png "")

The power supply is the typical [7805](https://www.sparkfun.com/products/107) linear regulator setup.  I used a 9V DC power supply for VCC, but 12V will also work.  Surprisingly, 1uf on the input and [0.1uf](https://www.sparkfun.com/products/8375) on the output is all that is necessary for stable operation.  The 220 Ohm resistor and LED ensure the 7805's minimum load is always satisfied, and also serve as a "power on" indicator.


![stirrer](http://i.imgur.com/Sf7x89c.png "")

The main circuit uses an NPN transistor in [common-emitter](http://en.wikipedia.org/wiki/Common_emitter) configuration to cycle the fan on and off.  During breadboarding I used a [Boarduino](http://learn.adafruit.com/boarduino-kits), and for the final circuit I used an [ATtiny85](https://www.sparkfun.com/products/9378) using the 'tiny core from [high-low tech](http://hlt.media.mit.edu/?p=1695).  The sketch size is small enough (~2.3kB) that an ATtiny45 would also work.

Nearly any [TO-92](http://en.wikipedia.org/wiki/TO-92) NPN transistor or N-channel MOSFET rated for 100mA should work for Q1.  I tested a [2N3904](https://www.sparkfun.com/products/521) and a [2N7000](http://en.wikipedia.org/wiki/2N7000), both of which worked.

D1 is a flyback diode which protects Q1.  I'm not sure it is strictly necessary, but it is good practice.  I used a [1N4148](https://www.sparkfun.com/products/8588), but nearly any diode should work.

LED2 is a status indicator which shows when Q1 is switched on.  LED2 and it's 1k resistor could also hang off the same pin which drives Q1, if you need to free up another pin.

The R2 potentiometer controls the duty cycle.  I used a 100K linear potentiometer, but 1k, 10k, etc will work just as well.


![stirrer](http://i.imgur.com/CapEhXM.jpg "")


Construction
------------


You'll need the following items to assemble as stirrer:

* a PC fan
* a neodymium magnet, salvaged from a dead hard drive
* cyanoacrylate glue ("Super Glue")
* a CDROM
* hot glue
* a [magnetic stirbar](http://search.ebay.com/magnetic-stirbar)

1. Use a pair of [flush cutters](http://www.adafruit.com/products/152) to remove all the blades from the fan.
2. Glue the magnet to the fan hub.  Try to keep the magnet's center of mass centered on the hub (this is a bit tricky, as it is curved).
3. Cut a CDROM in half and hot glue the halves to the fan's frame.

![stirrer](http://i.imgur.com/MdIMcJc.jpg "")

![stirrer](http://i.imgur.com/K7bxyD6.jpg "")
