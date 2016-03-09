#include "stdio.h"
#include <string.h>
#include <stdlib.h>
int N = 0;
struct stud{
	int ids[100];
	char name[100];
	int count;
	int i;
};
struct stud * studs;
char* parse(char *s){
	char op[100];
	int j = 0, l = 1, i = -1, k = -1;

	while(s[l] != 0){
		if(s[l] == '.'){
			i = l;
		}
		if(s[l++] == ' '){
			k = l;
		}
	}
	if(k == -1){
		k = l;
	}
	if(i == -1){
		i = 1;
	}else{
		i++;	
	}
	
	while(i < k){
		op[j++] = s[i++];
	}
	if(op[j-1] == ' '){
		op[j - 1] = 0;
	}else{
		op[j] = 0;	
	}
	return op;
}
int find(char *s){
	for(int i = 0; i < N; i++){
		if(strcmp(s, studs[i].name) == 0){
			return i;
		}
	}
	return -1;
}
void hash(int id, char *s){
	char tmp[100];
	int i;
	strcpy(tmp, parse(s));
	if( (i = find(tmp)) == -1 ){
		strcpy(studs[N].name, tmp);
		studs[N].i = 1;
		studs[N].ids[0] = id;
		studs[N++].count = 1;
	}else{
		studs[i].count++;
		studs[i].ids[studs[i].i++] = id;
	}
}

int main(int argc, char const *argv[])
{
	int count = 5, tempId;
	char tempName[100];
	scanf("%d", &count);
	studs = (struct stud *) malloc(sizeof(struct stud) * count);	

	for(int i = 0; i < count; i++){
		scanf("%d", &tempId);
		gets(tempName);	
		hash(tempId, tempName);
	}

	for(int i = 0; i < N; i++){
		printf("%s, %d, [", studs[i].name, studs[i].count);
		int tmpI = studs[i].i -1;
		while(tmpI >= 0){
			printf("%d, ", studs[i].ids[tmpI--]);
		}
		printf("]\n");
	}
	return 0;
}
