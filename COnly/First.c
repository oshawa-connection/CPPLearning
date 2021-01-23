/*
	Create a TCP socket
*/

#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "Point.h"
#include "RTree.h"


int main(int argc, char* argv[])
{
	Point point1={-1.0,-1.0};
	Point* point1Ptr = &point1;
	
	Point point2 = { -1.0,-2.0 };
	Point * points[] = { &point1,&point2 };

	Point* pointsPTR = &points;

	RTree rTree = { points,2,NULL,NULL };

	
	Point * nearestPoint = naiveNearestNeighbour(&point2,&rTree);
	printf("X is: %f",nearestPoint->x);
	printf("Y is: %f", nearestPoint->y);
	
};