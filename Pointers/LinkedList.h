#pragma once

namespace James
{
	class LinkedList
	{
	private:
		struct Node
		{
			int data;
			Node* nextNode;
			Node() : data{ 0 }, nextNode{ nullptr } {};
			Node(int x) : data{ x }, nextNode{ nullptr } {};
			Node(int x, Node* nNode) : data{ x }, nextNode{ nNode } {};
		};


		Node* firstNode;
		Node* lastNode;


	public:

		LinkedList() : firstNode{ nullptr }, lastNode{ nullptr } {

		};


		int length() {

			if (this->firstNode == nullptr) {
				return 0;
			}

			Node* currentNode = this->firstNode;
			int len = 1;
			while (currentNode->nextNode != nullptr) {
				currentNode = currentNode->nextNode;
				len++;
			};
			return len;
		};



		void addNode(int data) {

			std::cout << "Adding Node" << std::endl;

			Node* newNode = new Node(data);

			if (this->firstNode == nullptr) {
				this->firstNode = newNode;
			}

			if (this->lastNode != nullptr) {
				this->lastNode->nextNode = newNode;
			}

			this->lastNode = newNode;
		};


		void popNode() {
			std::cout << "Removing Node" << std::endl;
		};


		int getDataOnNode(int index) {

			//Check we don't exceed length
			if (index > this->length()) {
				throw std::length_error("Index was longer than length of list");
			}

			Node* currentNode = this->firstNode;
			for (size_t i = 0; i < index; i++)
			{
				currentNode = currentNode->nextNode;
			}

			return currentNode->data;
		};
	};
}


