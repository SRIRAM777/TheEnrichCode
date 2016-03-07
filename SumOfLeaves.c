#include "stdio.h"
#include "stdlib.h"
typedef struct Node* nodePtr; 
struct Node{
	int x;
	nodePtr left;
	nodePtr right;
};
typedef nodePtr Tree; 

nodePtr createNode(int element){
	Tree t = (Tree) malloc(sizeof(Node));
	t -> x = element;
	t -> left = NULL;
	t -> right = NULL;
	return t;
}

nodePtr insert(Tree t, int element){
	if(!t){
		return createNode(element);
	}else if(element < t -> x){
		t -> left = insert(t -> left, element);
	}else if(element > t -> x){
		t -> right = insert(t -> right, element);
	}
	return t;
}

void traverse(Tree t){
	if(t){
		traverse(t -> left);
		printf("%d\t", t -> x );
		traverse(t -> right);
	}
}

int sumOfLeaves(Tree t, int sum){
	if(!(t -> left) && !(t -> right)){
		sum += t -> x;
		return sum;
	}else{
		if(t -> left){
			sum = sumOfLeaves(t -> left, sum);	
		}
		if(t -> right){
			sum = sumOfLeaves(t -> right, sum);	
		}	
	}
}

int main(int argc, char const *argv[])
{
	int root = 10;
	Tree t = NULL;
	t = insert(t, root);
	insert(t, 2);
	insert(t, 3);
	insert(t, 12);
	insert(t, 11);
	insert(t, 13);
	traverse(t);
	int sum = 0;
	printf("\n%d", sumOfLeaves(t, sum));
	return 0;
}
