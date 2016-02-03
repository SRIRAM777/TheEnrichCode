#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
	int number, i, x, flag;
	scanf("%d", &number);

	if(number % 2 == 0)
	{
		x = number + 1;
	}else{
		x = number + 2;
	}	

	while(1)
	{		
		flag = 0;
		for(i = 2; i <= sqrt(x); i++)
		{
			if(x % i == 0)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			printf("%d", x);
			break;
		}
		x += 2;
	}
	return 0;
}
