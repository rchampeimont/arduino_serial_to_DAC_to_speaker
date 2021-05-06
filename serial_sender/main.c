#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int readByte;
	
	system("mode com4 baud=450000 data=8 parity=n to=off");
	
	//FILE *f = fopen("../sweet_dreams_8bit_mono.wav", "rb");
	FILE *f = fopen("../take_on_me_unsigned_8bit_mono.wav", "rb");
	
	FILE *serialPort = fopen("COM4", "wb");
	
	printf("Sending data to COM port...\n");
	
	while ((readByte = getc(f)) != EOF) {
		putc(readByte, serialPort);
	}
	return 0;
}
