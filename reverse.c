#include <stdio.h>
int main()
{
	  long int n,r=0,s;
  	scanf("%ld",&n);
  	while(n!=0)
  	{
     	s=n%10;
     	r=r*10+s;
     	n/=10;
  	}
  	printf("%ld",r);
  	return 0;
}
