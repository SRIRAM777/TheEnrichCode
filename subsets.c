#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int n;
	int *a;
	printf("Enter n...");
	scanf("%d", &n);
	printf("Enter the values : \n");
	a = (int*) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	int k = 1 << n;
	printf("Subset List : \n");
	printf("[");
	for (int i = 1; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i & (int) pow(2,j)){
				printf("%d,", a[j] );
				usleep(90000);
			}
		}
		printf("\b]\n[");
	}
	return 0;
}
