#include "stdio.h"
char *wordsList[] = {"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", 
	"Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Ten", "Twenty", "Thirty", 
	"Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred", " and ", " "};
void strCat(char *s1, char *s2, int *length){
	int j = 0;
	while(s2[j] != 0){
		s1[*length] = s2[j++];
		*length += 1;
	}
	s1[*length] = '\0';
}
void convertToWords(int number, char* output){
	int i = 0, j = 0, hundreds, tens;
	if(hundreds = number / 100){
		strCat(output, wordsList[hundreds], &i);
		strCat(output, wordsList[31], &i);
		strCat(output, wordsList[29], &i);
	}
	number %= 100;
	if (number < 20){
		if(number != 0){
			if(hundreds != 0){
				strCat(output, wordsList[30], &i);	
			}
			strCat(output, wordsList[number], &i);
		}
	}else{
		if(tens = number / 10){
			if(hundreds){
				strCat(output, wordsList[30], &i);	
			}
			strCat(output, wordsList[tens + 19], &i);
		}
		number %= 10;
		if(number != 0){
			if(!tens){
				strCat(output, wordsList[30], &i);		
			}
			strCat(output, wordsList[31], &i);
			strCat(output, wordsList[number], &i);
		}
	}
}
int main(int argc, char const *argv[])
{
	char output[32];
	int number;
	int i = 0;	
	scanf("%d", &number);
	if(number == 0){
		strCat(output, wordsList[0], &i);
	}else{
		convertToWords(number, output);
	}
	printf("%s\n", output);
	return 0;
}