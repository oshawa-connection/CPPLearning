#pragma once
#include <stdio.h>
typedef struct Node Node;

struct Node {
	int data;
	Node* nextNode;
};


typedef struct LinkedList {
	Node* firstNode;
	/*Node* endNode;*/
} LinkedList;


void linkedList_addNode(LinkedList* linkedList, Node* newNode) {

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