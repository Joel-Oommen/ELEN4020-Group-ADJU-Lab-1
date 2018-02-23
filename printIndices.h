#ifndef PRINTINDICES_H
#define PRINTINDICES_H

#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
#include <time.h>
#include <math.h>
#include "initZeros.h"

void setValue(int* Arr, int* dimensions, int* indices, int numOfD, int value);
void iterateArray(int* Arr, int* dimensions, int* indices, int numOfD);

void printIndices(int* Arr, int* dimensions, int numOfD)
{
	time_t time1;
	srand((unsigned) time(&time1));
	int size = getArraySize(dimensions,numOfD);
	int endIndex = size;
	endIndex *= 0.05;
	int indices[numOfD];
	for(int i=0;i<endIndex;i++)
	{
		int coordinate1D = rand()%size ;
		printf("Value: ");
		printf("%d \t", Arr[coordinate1D]);

		int Arr2[numOfD];

	    	for(int i = 0; i < numOfD; i++)
	    	{
			Arr2[i] = 1;
	   	}

	    	for(int i = numOfD - 1; i >= 1; i--)
	    	{
			Arr2[i - 1] = Arr2[i]*dimensions[i];
	    	}

		for (int i = 0; i < numOfD;i++)
		{
			indices[i] = (int)floor(coordinate1D/Arr2[i]);
			coordinate1D = coordinate1D - indices[i]*Arr2[i];
		}

		printf("Coordinates: ");
		for (int i = 0; i < numOfD ; i++)
		{
			printf("%d %s " , indices[i], ",");
		}
		printf("\n");
	}
	printf("\n");
	
}

void setValue(int* Arr, int* dimensions, int* indices, int numOfD, int value)
{
	int Arr2[numOfD];

    for(int i = 0; i < numOfD; i++)
    {
        Arr2[i] = 1;
    }

    for(int i = numOfD - 1; i >= 1; i--)
    {
        Arr2[i - 1] = Arr2[i]*dimensions[i];
    }

    int index = 0;

    for(int i = 0; i < numOfD; i++)
    {
        index += indices[i]*Arr2[i];
    }

    Arr[index] = value;

}

void iterateArray(int* Arr, int* dimensions, int* indices, int numOfD)
{

    int indexLimit = 0;

    for(int i = 0; i < numOfD; i++)
    {
        if(indices[i] < dimensions[i] - 1)
        {
            indices[i] += 1;
            indexLimit++;
            break;
        }
	indexLimit++ ;
    }
	
    if(indexLimit > 0 && indexLimit < numOfD )
    {
        for (int j = 0; j < indexLimit - 1; j++)
        {
            indices[j] = 0;
        }
    }
}
#endif
