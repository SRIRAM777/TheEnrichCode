#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int *a, *arr; 
	int cc = 0, n, f, j, t, i, index = 0, l, k =10, count;
	scanf("%d", &n);
	count = n;
	a = (int*) malloc(sizeof(int) * 1 << n); //temp array
	arr = (int*) malloc(sizeof(int) * n); //base array

	for( i = 0; i < n; i++){ 
		// load arrays with single digit
		arr[i] = i+1; 
		a[index++] = arr[i];
		printf("%d\n", arr[i]); //print output
		cc++;
	}

	i = 0;
	while(count--){
		while(index < ((1 << n) -1)){
			f = a[i];
			l = f % 10;	
			t = f * k;	
			for(j = l; j < n; j++){
				a[index] =  t + arr[j];
				printf("%d\n", a[index++]);
				cc++;
			}
			i++;
		}
		k*=10;
	}
	printf("No of elements : \t%d\n", cc);
	return 0;
}
