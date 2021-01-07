#include <stdio.h>

void doubleAllElements(int * passedArray) {
	int numElements = sizeof(*passedArray) / sizeof(int);
	for (int i = 0; i < numElements; i++) {
		passedArray[i] = passedArray[i] * 2;
		
	};
};

typedef struct Node Node;

struct Node {
	int data;
	Node* nextNode;
};


typedef struct LinkedList {
	Node* firstNode;
	/*Node* endNode;*/
} LinkedList;


void linkedList_addNode(LinkedList * linkedList,Node * newNode) {
	
	Node* currentNode = linkedList->firstNode;
	
	while (currentNode->nextNode != NULL)
	{
		currentNode = currentNode->nextNode;
	}

	currentNode->nextNode = newNode;
};


int linkedList_Length(LinkedList* linkedList) {
	Node* currentNode = linkedList->firstNode;
	int length = 1;
	while (currentNode->nextNode != NULL)
	{
		printf("Current data value is %d", currentNode->data);
		currentNode = currentNode->nextNode;
		length++;
	}
	return length;
};

int main() {
	Node firstNode = { 2, NULL };
	LinkedList myList = { &firstNode };
	LinkedList* listPtr = &myList;
	//printf("Current length of linked list: %d\n", linkedList_Length(&myList));
	Node newNode = { 4, NULL };
	Node newTwo = { 5, NULL };


	linkedList_addNode(listPtr, &newNode);

	//linkedList_addNode(listPtr, 5);
	//linkedList_addNode(listPtr, 6);
	//linkedList_addNode(&myList, 7);
	int length = linkedList_Length(listPtr);
	printf("Current length of linked list: %d\n", length);
};