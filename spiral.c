/*
  0  1  2  3
0 0  1  2  3
1 4  5  6  7 
2 8  9  10 11
3 12 13 14 15

Modified Indices : 0  1   2   3   7   11   15   14   13   12   8   4   5   6   10   9   
Actual Indices :   0  1   2   3   4   5    6    7    8    9    10  11  12  13  14  15 
Observation :        +1  +1  +1  +n  +n   +n   -1   -1   -1   -n  -n  +1  +1   +4  -1 
	 

  0  1  2
0 0  1  2
1 3  4  5
2 6  7  8

Modified Indices : 0  1   2   5   8   7   6   3   4
Actual Indices :   0  1   2   3   4   5   6   7   8
Observation :        +1  +1  +n  +n  -1   -1  -n  +1 
  0  1  2  3  4
0 0  1  2  3  4
1 5  6  7  8  9
2 10 11 12 13 14

0  1  2  3  4  9  14  13  12  11  10  5  6  7  8  
0  1  2  3  4  5  6   7   8   9   10  11 12 13 14

  0 1 2 
0 0 1 2
1 3 4 5

0 1 2 5 4 3
0 1 2 3 4 5

  0 1
0 0 1
1 2 3 
2 4 5

0 1 3 5 4 2
0 1 2 3 4 5

*/
#include "stdio.h"
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n = 5;
	int mat[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	int k,	i = 1, j = -1, c = 0, t = 0, m;
	k = n;
	while(c < n*n){
		m = 0;
		while( m < k){
			j += i;
			m++;
			printf("%d ", mat[j]);
			
		}
		i = (abs(i) == n) ? 1 : n;
		if(c++%2 == 0){
			k--;
		}
		else{
			t = !t;
		}
		if(t){
			i = -i;	
		}
	}
	return 0;
}
