#include<stdio.h>
#include<stdlib.h>

void printMat(int **mat, int r, int c){
	int i,j;
	for(i = 0; i < c ; ++i){
		for (int j = 0; j < r; ++j){
			printf("%d\t", mat[i][j] );
		}
		printf("\n");
	}	
}

int main(){
	int **mat, r, c, i, m, n, j, k;
	r = 3, c = 7; // row & col values
	
	m = r > c ? r : c; //max of r & c
	n = r < c ? r : c; //min of r&c

	mat = (int **) malloc(sizeof(int*) * m); //allocate rows

	for (i = 0; i < m; i++){
	    mat[i] = (int *)malloc(m * sizeof(int)); //allocate columns
	}

	k = 1;
	
	for(i = 0; i < r ; ++i){
		for (int j = 0; j < c; ++j){
			//fill the matrix with values
			mat[i][j] = k++;
		}
	}

	for(i = 0; i < n ; ++i){
		for (int j = i; j < m; ++j){
			//swap
			mat[i][j] += mat[j][i] - (mat[j][i] = mat[i][j]);
		}
	}
	printMat(mat,r,c);
}
