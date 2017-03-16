#include <iostream>

class MergeSort{
	private:
		int *sortedArray;
		int *array;
		int *tempArray;
		
		void doMergeSort(int, int);
		void mergeParts(int, int, int);
		
	public:
		MergeSort();
		void sort(int*, int);
	
};
