#pragma once
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


float arrayMinf(float* arrayf, int nElements)
{
	float currentMin = INT_MAX;
	for (int n = 0; n < nElements; n++)
	{
		
		if (*arrayf < currentMin)
		{
			currentMin = *arrayf;
		}
		arrayf++;
	}

	return currentMin;
}


int indexOfF(float * arrayf, float valueToFind, int nElements)
{
	for (int n = 0; n < nElements; n++)
	{
		if (valueToFind == *arrayf) {
			return n;
		}
		
		arrayf++;
	}
	return -1;
}