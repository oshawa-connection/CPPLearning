/*
	Create a TCP socket
*/

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} Point;


typedef struct {
	Point vertices[4];
} Bbox;

typedef enum { false, true } bool;


typedef struct {
	Point ** points;
	int nPoints;
	Bbox * boundingBox;
	Bbox* gridRects;

} RTree;

float maxf(float one, float two) {
	if (one >= two) {
		return one;
	}
	else {
		return two;
	}
};


float minf(float one, float two) {
	if (one <= two) {
		return one;
	}
	else {
		return two;
	}
};

/**
* 
* */
float distanceBtwn(Point point1, Point point2) {
	float diffX = maxf(point1.x, point2.x) - minf(point1.x, point2.x);
	float dxpow2 = powf(diffX, 2.0);

	float diffY = maxf(point1.y, point2.y) - minf(point1.y, point2.y);
	float dypow2 = powf(diffY, 2.0);
	float sum = dypow2 + dxpow2;
	
	return sqrtf(sum);
	
};

bool pointInRTree(Point* originalPointPTR, RTree* rTreePTR) {
	Point* currentPoint = rTreePTR->points[0];
	for (int n = 0; n < rTreePTR->nPoints;n++) {
		if (currentPoint == originalPointPTR) {
			return true;
		}
		currentPoint++;
	}
	return false;

};

Point * naiveNearestNeighbour(Point * originalPointPTR, RTree * rTreePTR) {
	//First check originalPoint is in RTree
	if (!pointInRTree(originalPointPTR, rTreePTR))
	{
		return NULL;
	}
	return originalPointPTR;
};

int main(int argc, char* argv[])
{
	Point point1={-1.0,-1.0};
	Point* point1Ptr = &point1;
	
	Point point2 = { -1.0,-2.0 };
	Point * points[] = { &point1,&point2 };

	Point* pointsPTR = &points;

	RTree rTree = { pointsPTR,2,NULL,NULL };

	if (rTree.points == point1Ptr) {
		printf("ok");
	}

	

	//float distance = distanceBtwn(point1, point2);
	//printf("Distance is %f", distance);

	if (naiveNearestNeighbour(&point1, &rTree) == NULL)
	{
		printf("Original point not found");
		exit(1);
	}
	else {
		printf("Original point found!");
	}

	//printf("Sizeof Point array is  %d\n", sizeof(points));
	//printf("Sizeof Point array is  %d\n", sizeof(*pointsPTR));
};