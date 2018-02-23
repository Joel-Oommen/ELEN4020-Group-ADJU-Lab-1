#ifndef SETZEROS_H
#define SETZEROS_H
#include "initZeros.h"

void setOnes(int *Arr, int *bounds, int numOfDimensions)
{
	int endIndex = getArraySize(bounds,numOfDimensions);
	endIndex *= 0.1;
	for (int i=0;i<endIndex;i++)//Create a one-dimensional array to represent the multidimensional one.
	{
		Arr[i]=1;
	}
}
#endif
