#include <stdio.h>
#include <string.h>
int main(){
	char *input[] = {"1", "3", "11","21","12", "100", "19", "2", "5", "56", "65", "99"}, *temp;
	int i, j, n = 12, cs, ten, t;
	char *store[10][n]; 
	int len[10] = {0};
	int checkSum[n];
	for (int i = 0; i < n; ++i)
	{
		// To separate and store the nos based on the number of digits
		int l = strlen(input[i]);
		store[l][len[l]] = input[i];
		len[l]++;
		
	}
	for (int i = 0; i < 10; ++i) //digits loop
	{
		for (int j = 0; j < len[i]; ++j) //sort
		{
			for (int k = 0; k < len[i] - 1; ++k)
			{
				if(strcmp(store[i][k], store[i][k + 1]) > 0){		
					temp = store[i][k];
					store[i][k] = store[i][k + 1];
					store[i][k + 1] = temp;
				}
			}
		}
		
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < len[i]; ++j)
		{
			printf("%s\n", store[i][j] );
		}
	}
	return 0;
}