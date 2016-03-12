#include "stdio.h"
#include "stdlib.h"

unsigned char hex_to_int(char c){
	switch(c){
		case 'a':
		case 'A':	
			return 10;
		case 'b':
		case 'B':	
			return 11;
		case 'c':
		case 'C':	
			return 12;
		case 'd':
		case 'D':	
			return 13;
		case 'e':
		case 'E':	
			return 14;
		case 'f':
		case 'F':	
			return 15;
		default:
			return (c - '0');

	}
}

void hex_to_bytearray (const char* hex_in, unsigned char* int_out){ 
	 int k = 0;
	for (int i = 0; hex_in[i] != 0; i += 2)
	{
		int_out[k] = hex_to_int(hex_in[i]);
		int_out[k] <<= 4;
		int_out[k++] |= hex_to_int(hex_in[i + 1]);
	}

} 
int main(int argc, char const *argv[])
{
	char s[65] = "123456789ABCDEF0";
	
	int l = 0;
	while(s[l++] != 0);
	int k = l / 2 ;
	unsigned char* output;
	hex_to_bytearray(s, output);
	 for(int i = 0; i < k; i++ ){
	 	printf("%d \t", output[i]);
	}
	return 0;
}