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
	Tree t = (Tree) malloc(sizeof(struct Node));
	t -> x = element;
	t -> left = NULL;
	t -> right = NULL;
	return t;
}

void traverse(Tree t){
	if(t){
		traverse(t -> left);
		printf("%d\t", t -> x );
		traverse(t -> right);
	}
}

int isLeaf(nodePtr N){
	return (!(N -> left) && !(N -> right));
}

int checkSumTree(Tree t){
	if(t){
		if(!isLeaf(t)){ //Leaf nodes are already SumTrees nah!
			int currentNodeVal = t -> x;
			int leftNodeVal = (t -> left) ? t -> left -> x : 0;
			int rightNodeVal = (t -> right) ? t -> right -> x : 0;
			if((leftNodeVal + rightNodeVal) != (currentNodeVal >> 1)){
				//Rule to be a SumTree : currentNodeVal = 2 *(leftNodeVal + rightNodeVal), if node is neither a leaf nor a parent of leaves
				if(!(isLeaf(t -> left)) && !(isLeaf(t -> right))){
					return 0;
				}else if(leftNodeVal + rightNodeVal != t -> x){
					//if parent of leaf currentNodeVal must equal (leftNodeVal + rightNodeVal)
					return 0; 
				}
			}else{
				//Go & Recurse!
				return checkSumTree(t -> left) && checkSumTree(t -> right);
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int root = 148;
	Tree t = createNode(root);
	
	/*
		Direct Construction of tree for our function ;) 
	      148
	   28 	   46
	 5   9   13  10
	2 3 4 5  6 7 9 1 

	*/

	//level 2
	t -> left = createNode(28);
	t -> right = createNode(46);

	//level 3
	t -> left -> left = createNode(5);
	t -> left -> right = createNode(9);
	t -> right -> left = createNode(13);
	t -> right -> right = createNode(10);

	//level 5
	t -> left -> left -> left = createNode(2);
	t -> left -> left -> right = createNode(3);
	t -> left -> right -> left = createNode(4);
	t -> left -> right -> right= createNode(5);
	
	t -> right -> left -> left = createNode(6);
	t -> right -> left -> right = createNode(7);
	t -> right -> right -> left = createNode(9);
	t -> right -> right -> right= createNode(1);

	//traverse(t);  For checking purpose 

	//Time for Results!
	printf("%s", checkSumTree(t) ? "True" : "False");
	return 0;
}
