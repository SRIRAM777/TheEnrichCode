#include<stdio.h>
#include<stdlib.h>
unsigned char setBit(unsigned char c, int n){
	return c | (1 << n);
}

unsigned char unSetBit(unsigned char c, int n){
	return c & ~(1 << n);
}
unsigned char toggleBit(unsigned char c, int n){
	return c ^ (1 << n);
}
unsigned char toggleXBit(unsigned char c, int n){
	return ~(c ^ (1 << (n) )) ^ (1 << (n)) ;
}
unsigned char rightRotate(unsigned char c){
	int x = c >> 1;
	c >>= 1;
	return c | x << 7;
}
unsigned char leftRotate(unsigned char c){
	int x = (c & (1 >> 7));
	c <<= 1;
	return c | x;
}
unsigned char swapNibbles(unsigned char c){
	return (c & 0x0F)<<4 | (c & 0xF0)>>4;
}
int main(int argc, char const *argv[])
{
	unsigned char number = 11;
	int bitIndex = 2;
	/*printf("Enter a Number : ");
	scanf("%d", &number);
	printf("Enter the Bit Index : ");
	scanf("%d", &bitIndex);*/
	printf("Bit %d set to 1        	: %u\n", bitIndex, setBit(number, bitIndex));
	printf("Bit %d set to 0        	: %u\n", bitIndex, unSetBit(number, bitIndex));
	printf("Toggling bit %d        	: %u\n", bitIndex, toggleBit(number, bitIndex));
	printf("Toggling except bit %d 	: %u\n", bitIndex, toggleXBit(number, bitIndex));
	printf("Right Rotate 			: %u\n", rightRotate(number));
	printf("Left Rotate 			: %u\n", leftRotate(number));
	printf("Swap Nibbles 			: %u\n", swapNibbles(number));
	return 0;
}
