/*
r => row, c => column
  0  1  2  3
0 0  1  2  3
1 4  5  6  7 
2 8  9  10 11
3 12 13 14 15
r,c = 4
Modified Indices : 0  1   2   3   7   11   15   14   13   12   8   4   5   6   10   9   
Actual Indices :   0  1   2   3   4   5    6    7    8    9    10  11  12  13  14  15 
Inc/Dec Sequence :        +1  +1  +1  +c  +c   +c   -1   -1   -1   -c  -c  +1  +1   +c  -1 
Print Toggle sequence : c times, r-1 times, c-1 times, r-2 times, c-2 times, r-3 times, c-3 times

  0  1  2
0 0  1  2
1 3  4  5
2 6  7  8
r,c = 3
Modified Indices : 0  1   2   5   8   7   6   3   4
Actual Indices :   0  1   2   3   4   5   6   7   8
Inc/Dec Sequence :        +1  +1  +c  +c  -1   -1  -c  +1 
Print Toggle sequence : c times, r-1 times, c-1 times, r-2 times, c-2 times

  0  1  2  3  4
0 0  1  2  3  4
1 5  6  7  8  9
2 10 11 12 13 14

r = 3, c = 5
Modified Indices : 0  1   2   3   4   9   14   13   12   11   10   5   6   7   8  
Actual Indices :   0  1   2   3   4   5   6    7    8    9    10   11  12  13  14
Inc/Dec Sequence :        +1  +1  +1  +1  +c  +c  -1   -1   -1   -1   -c   +1  +1  +1 
Print Toggle sequence : c times, r-1 times, c-1 times, r-2 times, c-2 times

The toggle sequence and increment/decrement sequence form a pattern.
Using that the code prints the spiral form of the matrix.
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n = 4, m = 5; //rows & columns
	int mat[] = {1,2,3,4,5,6,7,8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};// 21, 22, 23, 24};
	int km, kn, k, i = 1, j = -1, c = 0, t = 0, z, count = 0;
	km = m, kn = n-1, k = km;
	while(count < (n*m)){ // Loop untill all elements are printed
		z = 0;
		while( z < k){ // Toggle Sequence
			j += i;
			printf("%d ",mat[j] );
			z++;
			count++;
		}
		i = (abs(i) == m) ? 1 : m; // Toggle between 1 & c in the inc/dec sequence
		k = (k == km) ? kn : km; // Toggle between r & c in toggle sequence
		if(c++%2 == 0){
			km--; 
		}
		else{
			kn--;
			t = !t;
		}
		if(t){
			i = -i;	 // Toggle between inc and dec in inc/dec sequence
		}
	}
	return 0;
}
