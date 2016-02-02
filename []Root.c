#include<stdio.h>
float sqrt(float number,float error = 0.000001, float temp = 1){
	float result = number;
	while(result - temp > error){
		result = (result + temp) / 2;
		temp = number / result;
	}
	return result;
}
int main(int argc, char const *argv[])
{
	float number;
	scanf("%f", &number);
	printf("%f\n", sqrt(number) );
	return 0;
}
