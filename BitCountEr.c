#include<stdio.h>
int main(int argc, char const *argv[]){
	int n,ans = 1;
	scanf("%d",&n);
	while((n = n >> 1) > 0 && ans++);
	printf("%d", ans);
	return 0;
}
