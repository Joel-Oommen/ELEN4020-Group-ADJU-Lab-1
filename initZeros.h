#ifndef INITZEROS_H
#define INITZEROS_H

struct flatArray{//A structure to help represent an array.
	int numOfElements;
	int *pointer;
};

struct flatArray initZeros(int *bounds,int numOfDimensions){//Creates a one dimensional array to represent a k-dimensional array, and sets all the values to zero.
	
	int numOfElements = 1;
		
	for (int i=0;i<numOfDimensions;i++)
	{
		numOfElements =numOfElements*bounds[i];//Calculate the total number of elements in the array
	}
	struct flatArray arr;
	arr.numOfElements = numOfElements;
	arr.pointer = (int*)malloc(numOfElements*sizeof(int));//Allocate memory for an array of the given size
	for (int i=0;i<numOfElements;i++)//Create a one-dimensional array to represent the multidimensional one.
	{
		arr.pointer[i]=0;
	}
	return arr;
}
#endif
