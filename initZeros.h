#ifndef INITZEROS_H
#define INITZEROS_H

int getArraySize(int *bounds,int numOfDimensions)
{
	int numOfElements = 1;	
	for (int i=0;i<numOfDimensions;i++)
	{
		numOfElements =numOfElements*bounds[i];
	}
	return numOfElements;	
}

void initZeros(int *Arr, int *bounds, int numOfDimensions)
{
	int sizeOfArray = getArraySize(bounds,numOfDimensions);
	for (int i=0;i<sizeOfArray;i++)//Create a one-dimensional array to represent the multidimensional one.
	{
		Arr[i]=0;
	}
}
#endif
