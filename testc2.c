#include <stdlib.h>
#include <stdio.h>
#include "omp.h"

int maparray(int *bounds,int numOfDimensions)
{
	
	int numOfElements = 1;
		
	for (int i=0;i<numOfDimensions;i++)
	{
		numOfElements =numOfElements*bounds[i];
	}

	//printf("\nNumber of elements = %d \n", numOfElements);
	return numOfElements;

	
}






int main() {
//#pragma omp parallel num_threads(1)
//{

	printf("Enter the dimensions of your matrix. Eg. If 3D type 3 if 10D type 10\n");
	
	int numOfDimensions;

	scanf("%d", &numOfDimensions);
	int bounds[numOfDimensions];
	
	printf("Enter the sizes of each dimension followed by an enter.\n(Eg. If [10][2][5] type 10, then press 		ENTER then type 2, then press ENTER then type 5 then press ENTER.)\n");
	
	int inNum=0;
	int counter=0;
	while (counter!=numOfDimensions)
	{
		scanf("%d", &inNum);
		bounds[counter]=inNum;
		counter++;
	}

	
	int **arrayOne;
	int ***arrayTwo;
	int ****arryThree;
	int *****arrayFour;

	
	


	int sizeOfArray = maparray((int *)bounds,numOfDimensions);//Get the size of the array
	int *arr = (int*)malloc(sizeOfArray*sizeof(int));//Allocate memory for an array of the given size

	

	for (int i=0;i<sizeOfArray;i++)//Create a one-dimensional array to represent the multidimensional one. 						We will figure out how to interpret this later on.
	{
		arr[i]=0;
		//printf("%d",arr[i]);
	}
	//printf("\n");
	free(arr);			//Free the memory allocated for the array. This is necessary in order to 						avoid a memory leak.
//}

}





/*This Is Uyandas Code the hard coded 4D array was just an experiment and is not the actual mapping he uses. The mapping can be done i think with the returnValue function he explained it to me but im not yet fully understanding



int returnValue(int* Arr, int* dimensions, int* indices, int numOfD);

int main()
{



	int Arr[5][5][5][5]  = {0};
	Arr[1][2][3][4] = 1;
	int indices[4] = {1 , 2 , 3, 4};
	int numOfD = 4;
	int dimensions[4] = {5,5,5,5};

	int Arr2[625];
	int counter = 0;

	Arr[1][2][3][4] = 1;
	for (int l = 0; l < 5; l++)
	{
		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int i = 0; i < 5; i++)
				{
					Arr2[125*i +25*j + 5*k +l] = Arr[i][j][k][l];
					counter++;
				}
			}
		}
	}

	printf("%d\n", returnValue(Arr2, dimensions, indices, numOfD));
}


int returnValue(int* Arr, int* dimensions, int* indices, int numOfD)
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


	return *(Arr + index);

}


*/



