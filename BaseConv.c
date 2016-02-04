#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char x[36];
char *strrev(char *str)
{
	//strrev function implementation
      char *ptr1, *ptr2;
      if (! str || ! *str)
            return str;
      for (ptr1 = str, ptr2 = str + strlen(str) - 1; ptr2 > ptr1; ++ptr1, --ptr2)
      {
            *ptr1 ^= *ptr2 ^= *ptr1 ^= *ptr2;
      }
      return str;
}
void baseConv(int number, int base, char y[]){
	
	int len = 0;
	while(number){
		int r = number % base;
		y[len++] = x[r];
		number /= base;
	}
	strrev(y);
}
int main(int argc, char const *argv[])
{
	for (char i = 48; i < 58; ++i)
	{
		x[i - 48] = i;
	}
	for (char i = 65; i < 91; ++i)
	{
		x[i - 65 + 10] = i;
	}
	char y[100];
	int number = 56;
	int base = 10;
	if(base < 2 || base > 36){
		printf("Invalid Base!!!\n");
		return 0;
	}

	if(base == 10){
		printf("%d", number);
		return 0;
	}
	
	/*printf("Enter a Number : ");
	scanf("%d", &number);
	printf("Enter the Base : ");
	scanf("%d", &base);*/

	baseConv(number, base, y);
	printf("%s\n", y);
	return 0;
}
