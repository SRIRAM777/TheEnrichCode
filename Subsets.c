#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int *a, *arr; 
	int cc = 0, n, f, j, i, index = 0, l, k =10, count;
	scanf("%d", &n);
	count = n;
	a = (int*) malloc(sizeof(int) * 1 << n);
	arr = (int*) malloc(sizeof(int) * n);
	for( i = 0; i < n; i++){ 
		arr[i] = i+1;
		a[index++] = arr[i];
		printf("%d\n", arr[i]);
		cc++;
	}
	i = 0;
	while(count--){
		while(index < ((1 << n) -1)){
			f = a[i];
			l = a[i]%10;		
			for(j = l; j < n; j++){
				a[index++] =  (f*k) + arr[j];
				printf("%d\n", (f*k) + arr[j]);
				cc++;
			}
			i++;
		}
		k*=10;
	}
	printf("\t%d\n", cc);
	return 0;
}
