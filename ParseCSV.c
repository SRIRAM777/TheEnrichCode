#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student{
	int sNo;
	char name[100];
	int marks[5];
	int total;
	float cutOff;
	char grade;
};

int n = 15;
typedef struct student stud;
stud studentsList[15];
stud temp;

void rankStudents(){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(studentsList[j].cutOff < studentsList[j + 1].cutOff ||
				studentsList[j].cutOff == studentsList[j + 1].cutOff && 
				studentsList[j].total < studentsList[j + 1].total ||
				studentsList[j].total == studentsList[j + 1].total &&
				studentsList[j].marks[3] < studentsList[j + 1].marks[3]){
				temp = studentsList[j];
				studentsList[j] = studentsList[j + 1];
				studentsList[j + 1] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char line[1000];
	int i = 1;
	FILE *csv = fopen("ds.csv", "r");	
	i = 0;
	while(!feof(csv)){
		fgets(line, sizeof(line), csv );

		studentsList[i].sNo = atoi(strtok(line, ","));
		strcpy(studentsList[i].name, strtok(NULL, ","));
		studentsList[i].cutOff = 0;
		studentsList[i].total = 0;
		studentsList[i].grade = 'p';

		for(int j = 0; j < 5; j++){
			studentsList[i].marks[j] = atoi(strtok(NULL, ","));
			studentsList[i].total += studentsList[i].marks[j]; 

			if(studentsList[i].marks[j] < 70){
				studentsList[i].grade = 'f';
			}

			if(j == 0){
				studentsList[i].cutOff += (studentsList[i].marks[j]) / 2.0;
			}else if(j == 1 || j == 2){
				studentsList[i].cutOff += (studentsList[i].marks[j]) / 4.0;
			}

		}
		i++;
	}
	rankStudents();
	int r = 1;
	for(int i = 0; i < n; i++){
		if(studentsList[i].grade == 'p'){
			printf("%d \t%s \t%f\n", r++, studentsList[i].name, studentsList[i].cutOff );
		}
		
	}
	return 0;
}
