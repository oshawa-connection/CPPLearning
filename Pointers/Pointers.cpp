// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include <vector>


// This will be a sub-class of geometry
class Point {

};


class BoundRect {
private:
	std::vector<BoundRect> boundingRectChildren;
	std::vector<Point> vertices;
	bool pointInRect() {};
public:
	
	void search() {};
};

class RTree {
private:
	void buildBoundingRects() {};
	void determineDomain() {};
	

	

public:
	std::vector<Point> currentGeometries;

	void deletePoint() {
	//delete then rebuild tree
		//currentGeometries.delte
	};
	void deletePoint() {};
	




};



//std::vector<Point> nearestNeighbour(Point originalPoint, RTree rtree)
//{
//
//};

int main()
{
	James::LinkedList link = James::LinkedList();
	link.addNode(2);
	std::cout << "Length of linked list is" << link.length() << std::endl;

	link.addNode(2);
	std::cout << "Length of linked list is " << link.length() << std::endl;

	std::cout << "Data on Node 1 is " << link.getDataOnNode(1) << std::endl;
	
	
	//LinkedList linkedList{};
	//linkedList.addNode();
}

