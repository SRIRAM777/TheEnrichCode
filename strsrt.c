#include <stdio.h>
#include <string.h>

void numStrSrt(char *input, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n - 1); j++){
			if(strlen(input[j]) > strlen(input[j + 1]) || strlen(input[j]) == strlen(input[j + 1]) && strcmp(input[j], input[j + 1]) > 0){
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}	
}

int main(){
	char *input[] = {"1", "3", "11", "7", "100","21", "12", "19", "2", "5", "56", "65", "99"}, *temp;
	int i, j, n = 13;
	numStrSrt(input, n);
	for (int k = 0; k < n; ++k){
		printf("%s ", input[k] );
	}
	return 0;
}
