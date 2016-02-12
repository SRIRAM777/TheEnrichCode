#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student{
	int sNo;
	char name[100];
	int marks[5];
};

typedef struct student stud;
stud studentsList[10];
int main(int argc, char const *argv[])
{

	char headers[7][100];
	char line[1000];
	int i = 1;
	FILE *csv = fopen("dataset.csv", "r");	
	int total[5] = {0}, max[5] = {0};
	fgets(line, sizeof(line), csv);
	strcpy(headers[0], strtok(line, ","));
	while(i < 7){
		  strcpy(headers[i++], strtok(NULL, ","));
	}
	i = 0;
	while(!feof(csv)){
		fgets(line, sizeof(line), csv );
		studentsList[i].sNo = atoi(strtok(line, ","));
		strcpy(studentsList[i].name, strtok(NULL, ","));
		for(int j = 0; j < 5; j++){
			studentsList[i].marks[j] = atoi(strtok(NULL, ","));
			total[j] += studentsList[i].marks[j];
			max[j] = max[j] > studentsList[i].marks[j] ? max[j] : studentsList[i].marks[j];
		}
		i++;
	}
		printf("Subject\t\t\tAverage \tMaxMark\n");
		for(int j = 0; j < 5; j++){
			printf("%-11s\t\t%0.2f\t\t %d\n", headers[2+j], total[j] / 9.0, max[j] );
		}
	return 0;
}
