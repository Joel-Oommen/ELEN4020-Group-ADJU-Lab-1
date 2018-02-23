#include <stdlib.h>
#include <stdio.h>
#include "initZeros.h"
#include "setOnes.h"
#include "printIndices.h"

int main() {
	int numOfDimensions1=2;
	int bounds1[2]={100,100};
	int sizeOfArray1 = getArraySize((int *)bounds1,numOfDimensions1);//Get the size of the array
	int *A1 = (int*)malloc(sizeOfArray1*sizeof(int));//Allocate memory for an array of the given size

	int numOfDimensions2=3;
	int bounds2[3]={100,100,100};
	int sizeOfArray2 = getArraySize((int *)bounds2,numOfDimensions2);
	int *A2 = (int*)malloc(sizeOfArray2*sizeof(int));

	int numOfDimensions3=4;
	int bounds3[4]={50,50,50,50};
	int sizeOfArray3 = getArraySize((int *)bounds3,numOfDimensions3);
	int *A3 = (int*)malloc(sizeOfArray3*sizeof(int));

	int numOfDimensions4=5;
	int bounds4[5]={20,20,20,20,20};
	int sizeOfArray4 = getArraySize((int *)bounds4,numOfDimensions4);
	int *A4 = (int*)malloc(sizeOfArray4*sizeof(int));

	initZeros(A1,(int *)bounds1,numOfDimensions1);//Initialize array to zeros
	setOnes(A1,(int *)bounds1,numOfDimensions1);//Set 10% of the array to one
	printIndices(A1,(int *)bounds1,numOfDimensions1);//Print the indices and values of 5% of the array
	free(A1);//Free the memory allocated for the array. This is necessary in order to avoid a memory leak.

	initZeros(A2,(int *)bounds2,numOfDimensions2);
	setOnes(A2,(int *)bounds2,numOfDimensions2);
	printIndices(A2,(int *)bounds2,numOfDimensions2);
	free(A2);
	
	initZeros(A3,(int *)bounds3,numOfDimensions3);
	setOnes(A3,(int *)bounds3,numOfDimensions3);
	printIndices(A3,(int *)bounds3,numOfDimensions3);
	free(A3);

	initZeros(A4,(int *)bounds4,numOfDimensions4);
	setOnes(A4,(int *)bounds4,numOfDimensions4);
	printIndices(A4,(int *)bounds4,numOfDimensions4);
	free(A4);
}
