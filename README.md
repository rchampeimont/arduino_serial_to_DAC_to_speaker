# arduino_serial_to_DAC_to_speaker
Play music with the Arduino received in real time on serial port.

This project (which is entirely useless and just for fun) consists in sending a 8-bit WAV file by the emulated serial port from the computer to the Arduino, while the Arduino translates in real time each byte received to 8 bits sent to the 8 resistors, which the resistor ladder transforms into a analog level sent to a speaker.

## Code
The "serial_to_DAC_to_speaker" directory contains the Arduino code.

The "serial_sender" directory contains a rather trivial C program that copies a file to the serial port (emulated serial with is in fact the USB connected to the Arduino). Change it with your own virtual serial port.

## Circuit
The circuit uses a resistor ladder (https://en.wikipedia.org/wiki/Resistor_ladder) as a DAC (Digital to Analog Converter). The black capacitor is 100 µF, is in series with the load (the speaker), and is useed to remove the DC component (it's a best practice for speaker signals). The blue capacitor is 100 nF from the output to the ground and it used as a low-pass filter, although I wonder it it makes a real difference in practice (the capactitor is maybe a little to small).

![Overview](/images/overwith_with_annot.jpg?raw=true)
