#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include <termios.h>

int *square, blank, moves;

char getch();
void drawSquare(int squareSize);
int checkSolution(int elements);
void makeMove(int offset, int elements, int squareSize);
void shuffleNumbers(int squareSize, int elements);
void initializeSquare(int squareSize, int elements);

int main(int argc, char const *argv[])
{
	int squareSize, elements;
	system("clear");
	printf("Enter the size of square : \n");
	scanf("%d", &squareSize);
	elements = squareSize * squareSize;
	initializeSquare(squareSize, elements);
	char c = ' ';
	int check;
	moves = 0;
	do{
		printf("\nUse arrow keys for movement, Q -> Quit\n");
		printf("Moves so far : %d\n", moves++);
		if((c = getch()) == '\033'){
			getch();
			c = getch();
		}
		c = toupper(c);
		switch(c){
			case 'A':
				makeMove(squareSize, elements, squareSize);
				break;
			case 'D':
				makeMove(1, elements, squareSize);
				break;
			case 'B':
				makeMove(-squareSize, elements, squareSize);
				break;
			case 'C':
				makeMove(-1, elements, squareSize);
				break;
			case 'Q':
				printf("\nYou gave up!! \nYou need more practice the next time!!!\n");
				return 0;
				break;
		}
		check = checkSolution(elements);
	}while(c != 'Q' && check != 1);
	printf("Congratulations!! You win!!! B-) \nTotal moves = %d", moves);
	return 0;
}

void drawSquare(int squareSize){
	system("clear");
	int elements = squareSize * squareSize;
	int length = 5 * squareSize;
	printf("\n");
	for (int i = 0; i < elements; ++i)
	{
		if(!(i%squareSize)){
			printf("\n");
			for (int j = 0; j < length; ++j)
			{
				printf("-");
			}
			printf("\n");
			
		}
		if(square[i] != 0){
				printf(" %2d |", square[i]);	
			}
			else{
				printf(" %2c |", ' ');
			}
	}
	printf("\n");
	for (int j = 0; j < length; ++j)
	{
		printf("-");
	}
	printf("\n");
}

int checkSolution(int elements){
	for (int i = 0; i < elements-1; ++i)
	{
		if(square[i] != i+1 ){
			return 0;
		}
	}
	return 1;
}

void makeMove(int offset, int elements, int squareSize){
	int z = blank + offset;
	if (z > elements || z < 0 || (offset == 1 && z % squareSize == 0 ) ||  (offset == -1 && blank % squareSize == 0)){
		printf("Invalid Move!!! Try again!!");
		moves--;
	}else{
		square[blank] += square[z];
		square[z] = square[blank] - square[z];
		square[blank] = square[blank] - square[z];
		blank = z;	
	}
	drawSquare(squareSize);
}

void shuffleNumbers(int squareSize, int elements){
	int offsets[] = {1, squareSize, -1, -squareSize};
	for (int i = 0; i < elements; ++i)
	{
		makeMove(offsets[rand() % 4], elements, squareSize);
	}
}

void initializeSquare(int squareSize, int elements){
	int start;
	square = (int*) malloc(sizeof(int) * squareSize);
	for (int i = 0; i < elements; ++i)
	{
		square[i] = start++;
		start %= elements;
	}
	shuffleNumbers(squareSize, elements);
	drawSquare(squareSize);
}


char getch(){
	//Implementation of getch in gcc
	//Source : stackoverflow
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
 }
