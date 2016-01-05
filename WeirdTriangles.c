#include<stdio.h>
#include<stdlib.h>
void floydTri(int n){
	int k = 1, i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("%d ", k++);
		}
		printf("\n");
	}
}

void pascalTri(int n){
	int k, t, i, j;
	printf("1\n");
	for (i = 1; i < n; ++i)
	{
		k = 1;
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", k);
			//Compute Binomial Coeff
			t = k * (i-j)/(j+1); 
			k = t > 0 ? t : 1; // since 0! = 1
		}
		printf("\n");
	}

}
void switcherTri(int n){
	int x[] = {1,2}, i, j, k;
	for (i = 0; i < n; ++i)
	{
		k = i % 2;
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", x[k]);
			x[k] += 2;
		}
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("\n1) Floyd's Triangle : \n\n");
	floydTri(n);
	printf("\n2) Pascals's Triangle : \n\n");
	pascalTri(n);
	printf("\n3) Switcher Triangle : \n\n");
	switcherTri(n);


	return 0;
}
