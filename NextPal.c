#include "stdio.h"
int main(int argc, char const *argv[])
{
	char number[100] = "1234";
	int len = 0;
	//scanf("%s", number);
	while(number[len++] != 0);
	int l = len / 2;
	printf("%d\n", l);
	for(int i = 0; i <= l; i++){
		while(number[len - i - 2] != number[i]){
			number[len - i - 2]++ ;
		}
	}
	printf("%s\n", number );
	return 0;
}