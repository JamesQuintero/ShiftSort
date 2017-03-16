#include <iostream>
#include "MergeSort.h"

using namespace std;

MergeSort::MergeSort()
{
	
}


void MergeSort::sort(int *array, int size)
{
	tempArray = new int[size];
	
	MergeSort::array = array;
	
	doMergeSort(0, size-1);
	
	delete[] tempArray;
	
}

void MergeSort::doMergeSort(int lowerIndex, int higherIndex)
{
	if(lowerIndex<higherIndex)
	{
		int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
            
        // Below step sorts the left side of the array
        doMergeSort(lowerIndex, middle);
        
        // Below step sorts the right side of the array
        doMergeSort(middle + 1, higherIndex);
        
        // Now merge both sides
        mergeParts(lowerIndex, middle, higherIndex);
	}
}

void MergeSort::mergeParts(int lowerIndex, int middle, int higherIndex)
{
    for (int i = lowerIndex; i <= higherIndex; i++)
    {
        tempArray[i] = array[i];
    }
    
    int i = lowerIndex;
    int j = middle + 1;
    int k = lowerIndex;
    while (i <= middle && j <= higherIndex)
    {
        if (tempArray[i] <= tempArray[j])
        {
            array[k] = tempArray[i];
            i++;
        }
        else
        {
            array[k] = tempArray[j];
            j++;
        }
        k++;
    }
    
    while (i <= middle)
    {
        array[k] = tempArray[i];
        k++;
        i++;
    }
}
