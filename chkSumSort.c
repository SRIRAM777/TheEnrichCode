#include <stdio.h>
#include <string.h>
int main(){
	char *input[] = {"1", "3", "11","21","12", "100", "19", "2", "5", "56", "65", "99"}, *temp;
	int i, j, n = 12, cs, ten, t;
	int checkSum[n];
	for (int i = 0; i < n; ++i)
	{
		cs = 0;
		int l = strlen(input[i]);
		ten = 1;
		for (int j = l - 1; j >= 0; j--)
		{
			cs += (input[i][j] * ten);
			ten *= 10;
		}
		checkSum[i] = cs;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if(checkSum[j] > checkSum[j + 1]){
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				t = checkSum[j];
				checkSum[j] = checkSum[j + 1];
				checkSum[j + 1] = t;
			}			
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%s ", input[i]);
	}
	return 0;
}