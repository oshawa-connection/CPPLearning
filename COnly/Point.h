#pragma once
#include "Usf.h"
#include <math.h>



typedef struct {
	float x;
	float y;
} Point;


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