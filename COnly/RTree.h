#pragma once
#include "Point.h"
#include "Bbox.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


//enum { false =0, true=1 } bool;

typedef struct {
	Point** points;
	int* numberOfPoints;
	Bbox * bbox;
	Node* nextNode;
} Node;


typedef struct {
	Point** points;
	int depth;
	Node* rootNode;
	
	Bbox* boundingBox; // the overall bounding box for the whole R Tree.
	Bbox* gridRects;

} RTree;


/**
* 1 if Point is in Rtree, 0 if not
* TODO: change to traverse tree rather than looping points
* */
short pointInRTree(Point* originalPointPTR, RTree* rTreePTR) {
	Point** currentPoint = rTreePTR->points;
	for (int n = 0; n <= rTreePTR->nPoints;n++) {
		if (*currentPoint == originalPointPTR) {
			return 1;
		}
		currentPoint++;
	}
	return 0;

};


/*
* Searches for a point in an RTree that is the nearest neighbour of the passed point.
* */
Point* naiveNearestNeighbour(Point* originalPointPTR, RTree* rTreePTR) {
	//First check originalPoint is in RTree
	if (!pointInRTree(originalPointPTR, rTreePTR))
	{
		return NULL;
	}

	float currentMin = INFINITY;
	Point* currentNN = NULL;

	for (int n = 0; n < rTreePTR->nPoints; n++) {
		Point* currentPoint = rTreePTR->points[n];
		if (originalPointPTR == currentPoint) {
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

RTree* buildRtree(Point* point, int nPoints, int maxPointsPerNode) {

	if (nPoints < 2) {
		printf("Cannot build RTree from %d points", nPoints);
		return NULL;
	}

	float* allXs = (float*)malloc(sizeof(float) * nPoints);
	float* allYs = (float*)malloc(sizeof(float) * nPoints);

	if (allXs == NULL || allYs == NULL) {
		printf("Unable to allocate memory");
		exit(1);
	}

	for (int i = 0; i < nPoints; i++) {
		allXs[i] = point[i].x;
		allYs[i] = point[i].y;
	}

	float maxX = arrayMaxf(allXs, nPoints);
	float maxY = arrayMaxf(allYs, nPoints);

	float minX = arrayMinf(allXs, nPoints);
	float minY = arrayMinf(allYs, nPoints);

	if (minX == maxX) {
		printf("Cannot build R tree where points are all overlapping");
		return NULL;
	}

	//Bbox boundingBox = {};
};


//RTree* buildRTreeIndex(RTree *rtree, int depth, int nPointsPerRect) {
//
//}

/*
* To make sure that the passed arguments are valid, we have to calculate the 
* minimum sensible number of nodes needed to construct an R Tree.
* */
int _determineTotalMinNumberOfNodesNeeded(int depth) {
	int nNodes = 1;
	int nLeaves = 0;
	for (int d = 0; d < depth; d++) {
		nLeaves = depth
		nNodes = nNodes + (d * 2);
	}
	return nNodes;
};

//bool _IsALeafNode(Node* node) {
//	
//}