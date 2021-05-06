# arduino_serial_to_DAC_to_speaker
Play music with the Arduino received in real time on its serial port.

This project (which is entirely useless and just for fun) consists in sending a 8-bit WAV file by the emulated serial port from the computer to the Arduino, while the Arduino translates in real time each byte received to 8 bits sent to the 8 resistors, which the resistor ladder transforms into a analog level sent to a speaker.

## Code
The "serial_to_DAC_to_speaker" directory contains the Arduino code.

The "serial_sender" directory contains a rather trivial C program (to run on the computer) that copies a file to a serial port. Change it to use your own virtual serial port connected to the Arduino via the USB cable. It might also work with a real serial port, but I haven't tested it.

The file must be in Microsoft WAV Unsigned 8-bit mono, which basically means that the data consists of bytes from 0 to 255, each representing a point in the sound wave (this trivial encoding is called PCM). With Audacity you can transform any music file into this format by removing stereo, then exporting to "other uncompressed format" and selecting "Microsoft WAV" with "Unsigned 8-bit PCM" encoding.

## Circuit
The circuit uses a resistor ladder (https://en.wikipedia.org/wiki/Resistor_ladder) as a DAC (Digital to Analog Converter). The black capacitor is 100 µF, is in series with the load (the speaker), and is useed to remove the DC component (it's a best practice for speaker signals). The blue capacitor is 100 nF from the output to the ground and it used as a low-pass filter, although I wonder it it makes a real difference in practice (the capactitor is maybe a little to small).

![Overview](/images/overwith_with_annot.jpg?raw=true)
