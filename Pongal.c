#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	system("clear");
	char a[] = "Pongal Nalvaazhthukkal!";
	for (int i = 0; a[i]!= '\0'; ++i)
	{
		printf("%c", a[i]);
		sleep(1);
		fflush(stdout);
	}
	return 0;
}
