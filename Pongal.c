#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	system("clear");
	char a[] = "Happy Pongal!";
	for (int i = 0; i < 13; ++i)
	{
		printf("%c", a[i]);
		sleep(1);
		fflush(stdout);
	}
	return 0;
}
