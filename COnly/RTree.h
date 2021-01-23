#pragma once
#include "Point.h"
#include "Bbox.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
typedef enum { false, true } bool;

typedef struct {
	Point** points;
	int nPoints;
	Bbox* boundingBox;
	Bbox* gridRects;

} RTree;



bool pointInRTree(Point* originalPointPTR, RTree* rTreePTR) {
	Point** currentPoint = rTreePTR->points;
	for (int n = 0; n <= rTreePTR->nPoints;n++) {
		if (*currentPoint == originalPointPTR) {
			return true;
		}
		currentPoint++;
	}
	return false;

};



Point* naiveNearestNeighbour(Point* originalPointPTR, RTree* rTreePTR) {
	//First check originalPoint is in RTree
	if (!pointInRTree(originalPointPTR, rTreePTR))
	{
		return NULL;
	}

	float currentMin = INFINITY;
	Point* currentNN = NULL;

	for (int n = 0; n < rTreePTR->nPoints; n++)
	{
		Point* currentPoint = rTreePTR->points[n];
		if (originalPointPTR == currentPoint)
		{
			continue;
		}

		float currentDist= distanceBtwn(*currentPoint, *originalPointPTR);
		if (currentDist < currentMin)
		{
			currentMin = currentDist;
			currentNN = currentPoint;
		}
	}
	
	return currentNN;
};