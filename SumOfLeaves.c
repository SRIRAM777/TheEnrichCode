#include "stdio.h"
#include "stdlib.h"
typedef struct Node* nodePtr; 
struct Node{
	int x;
	nodePtr left;
	nodePtr right;
};
typedef nodePtr Tree; 
int sum = 0;
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

void sumOfLeaves(Tree t, int type = 0){
		
	if(!(t -> left) && !(t -> right)){
		if(type == 0){
			sum += t -> x;	
		}
		
	}else{
		if(t -> left){
			sumOfLeaves(t -> left, 0);
		}
		if(t -> right){
			sumOfLeaves(t -> right, 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int root = 50;
	Tree t = NULL;
	/* 
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
     */
	t = insert(t, root);
	
	insert(t, 30);
	insert(t, 20);
	insert(t, 40);
	insert(t, 70);
	insert(t, 60);
	insert(t, 80);

	traverse(t);
	sumOfLeaves(t);
	printf("\n\t%d", sum);
	return 0;
}

