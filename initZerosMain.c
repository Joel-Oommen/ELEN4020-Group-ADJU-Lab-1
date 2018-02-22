#include <stdlib.h>
#include <stdio.h>
#include "initZeros.h"
#include "setOnes.h"

int main() {
	printf("Enter the dimensions of your matrix. Eg. If 3D type 3 if 10D type 10\n");
	
	int numOfDimensions;

	scanf("%d", &numOfDimensions);
	int bounds[numOfDimensions];
	
	printf("Enter the sizes of each dimension followed by an enter.\n(Eg. If [10][2][5] type 10, then press ENTER then type 2, then press ENTER then type 5 then press ENTER.)\n");
	
	int inNum=0;
	int counter=0;
	while (counter!=numOfDimensions)
	{
		scanf("%d", &inNum);
		bounds[counter]=inNum;
		counter++;
	}

	int sizeOfArray = getArraySize((int *)bounds,numOfDimensions);//Get the size of the array
	int *arr = (int*)malloc(sizeOfArray*sizeof(int));//Allocate memory for an array of the given size
	initZeros(arr,(int *)bounds,numOfDimensions);//Initialize array to zeros
	setOnes(arr,(int *)bounds,numOfDimensions);//Set 10% of the array to one
/*
	for (int i=0;i<sizeOfArray;i++)//Create a one-dimensional array to represent the multidimensional one.
	{
		printf("%d",arr[i]);
	}
	printf("\n");
*/
	free(arr);//Free the memory allocated for the array. This is necessary in order to avoid a memory leak.
}
