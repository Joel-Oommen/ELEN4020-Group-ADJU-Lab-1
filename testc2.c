#include <stdlib.h>
#include <stdio.h>
#include "omp.h"

int maparray(int *bounds,int numOfDimensions){
	
	int numOfElements = 1;
		
	for (int i=0;i<numOfDimensions;i++)
	{
		numOfElements =numOfElements*bounds[i];
	}

	//printf("\nNumber of elements = %d \n", numOfElements);
	return numOfElements;

	
}


int main() {
#pragma omp parallel num_threads(1)
{

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

	int sizeOfArray = maparray((int *)bounds,numOfDimensions);//Get the size of the array
	int *arr = (int*)malloc(sizeOfArray*sizeof(int));//Allocate memory for an array of the given size

	for (int i=0;i<sizeOfArray;i++)//Create a one-dimensional array to represent the multidimensional one. We will figure out how to interpret this later on.
	{
		arr[i]=0;
		//printf("%d",arr[i]);
	}
	//printf("\n");
	free(arr);//Free the memory allocated for the array. This is necessary in order to avoid a memory leak.
}

}
