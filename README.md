# arduino_serial_to_DAC_to_speaker
Play music with the Arduino received in real time on its serial port.

This project (which is entirely useless and just for fun) consists in sending a 8-bit WAV file by the emulated serial port from the computer to the Arduino, while the Arduino translates in real time each byte received to 8 bits sent to the 8 resistors, which the resistor ladder transforms into a analog level sent to a speaker.

YouTube video showing the result: https://www.youtube.com/watch?v=IvkEMvsHVPk

## Code
The "serial_to_DAC_to_speaker" directory contains the Arduino code.

The "serial_sender" directory contains a rather trivial C program (to run on the computer) that copies a file to a serial port. Change it to use your own virtual serial port connected to the Arduino via the USB cable.

The file must be in Microsoft WAV Unsigned 8-bit mono (sampled at 44.1 kHz, which is the usual sampling rate today), which basically means that the data consists of bytes from 0 to 255, each representing a point in the sound wave (this trivial encoding is called PCM). With Audacity you can transform any music file into this format by removing stereo, then exporting to "other uncompressed format" and selecting "Microsoft WAV" with "Unsigned 8-bit PCM" encoding.

If you want to connect a real serial port (see https://github.com/raphaelchampeimont/arduino_serial_to_LCD#variant-2-real-serial-port-rs232-with-custom-adapter-circuit about how to do that), you have to adapt the transfer rate because 450000 is too high (at least my computer refused to set this rate for its serial port). I successfully tested it with audio sampled at 11.025 kHz (which use to be a "regular" sampling rate in the past) and a serial port setting of 115200 bauds (one of the "standard" baud rates). If you want to do that you need to change the baud rate in both the Arduino code and the sender code and use audio sampled at 11.025 kHz.

## Circuit
The circuit uses a resistor ladder (https://en.wikipedia.org/wiki/Resistor_ladder) as a DAC (Digital to Analog Converter) with R=100ohm. The black capacitor is 100 µF, is in series with the load (the speaker), and is used to remove the DC component (it's a best practice for speaker signals). The blue capacitor is 100 nF from the output to the ground and it used as a low-pass filter, although I wonder it it makes a real difference in practice (the capactitor is maybe a little too small).

If you want to test it yourself, you can start with only the resistors and you should already hear the music.

![Overview](/images/overwith_with_annot.jpg?raw=true)
