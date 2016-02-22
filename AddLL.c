#include "stdio.h"
#include "stdlib.h"
typedef struct Node* NodePtr;
typedef NodePtr List;
struct Node
{
	int x;
	NodePtr next;
};
NodePtr createList(){
	NodePtr newNode  = (NodePtr) malloc(sizeof(Node));
	newNode -> x = 0;
	newNode -> next = NULL;
	return newNode;
}
NodePtr insert(List l, int e, NodePtr pos){
	NodePtr newNode = (NodePtr) malloc(sizeof(Node));
	newNode -> x = e;
	newNode -> next = NULL;
	pos -> next = newNode;
	l->x++;
	return newNode;
}
void parseNumber(List l, char *num){
	NodePtr pos = insert(l, (int) num[0] - '0', l);
	l -> next = pos;
	for(int i = 1; num[i] != '\0'; i++){
		pos = insert(l, (int) num[i] - '0', pos);
	}
}
void traverse(List l){
	NodePtr temp = l -> next ;
	while(temp){
		printf("%d", temp -> x );
		temp = temp -> next;
	}
	printf("\n");
}
void reverseList(List l){
	for(int i = 0; i < l -> x; i++){
		NodePtr pos = l -> next;
		for(int j = 0; j < ((l -> x) - i - 1); j++){
			if(pos -> next){
				NodePtr next = (pos -> next);
				int temp = pos -> x;
				pos -> x = next -> x;
				next -> x = temp;
			}
			pos = pos -> next;
		}
	}	
}

List sum(List l1, List l2){
	List L3 = createList();
	NodePtr p1 = l1 -> next;
	NodePtr p2 = l2 -> next;
	int c = 0, sum;
	NodePtr pos = L3;
	while(p1 && p2){
		sum = p1 -> x + p2 -> x + c;
		c = sum / 10;
		sum %= 10;
		pos = insert(L3, sum, pos);
		p1 = p1 -> next;
		p2 = p2 -> next;
	}
	while(p1){
		pos = insert(L3, (p1-> x + c) % 10, pos);
		c = (p1-> x + c) / 10;
		p1 = p1 -> next;
		
	}
	while(p2){
		pos = insert(L3, p2-> x + c, pos);
		p2 = p2 -> next;
		c = 0;
	}
    if((!p1 || !p2) && c){
		pos = insert(L3, c, pos);
	}
	reverseList(L3);
	traverse(L3);
}

int main(int argc, char const *argv[])
{
	List L1 = createList();
	List L2 = createList();
	char n1[100], n2[100];
	scanf("%s %s", n1, n2);
	parseNumber(L1, n1);
	parseNumber(L2, n2);
	reverseList(L1);
	reverseList(L2);
	sum(L1,L2);
	return 0;
}
	