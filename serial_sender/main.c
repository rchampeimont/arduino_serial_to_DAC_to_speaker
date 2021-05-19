#include <stdio.h>
#include <stdlib.h>

#define PORT "COM4"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int readByte;
	
	// Replace COM4 with your own virtual serial port connected to the Arduino
	system("mode " PORT " baud=450000 data=8 parity=n to=off");
	
	// The file must be in Microsoft WAV format in Unsigned 8-bit mono.
	//FILE *f = fopen("../sweet_dreams_8bit_mono.wav", "rb");
	FILE *f = fopen("../take_on_me_unsigned_8bit_mono.wav", "rb");
	
	// Replace COM4 with your own virtual serial port connected to the Arduino
	FILE *serialPort = fopen(PORT, "wb");	
	
	while (1) {
		printf("Sending file to " PORT " port...\n");
		while ((readByte = getc(f)) != EOF) {
			putc(readByte, serialPort);
		}
		rewind(f);
	}
	
	return 0;
}
