#include <stdio.h>

int main(void) {
	
	char packet[7] = {0x01, 0x79, 0xA0, 0x00, 0x00, 0x00, 0x00};
	char checksum;

	for(char i = 0; i < 7; i++) {
		checksum += packet[i];
	}

	checksum = 0xff - checksum;
	
	printf("Checksum of A0 is: %x\n", checksum);

	return 0;
}
