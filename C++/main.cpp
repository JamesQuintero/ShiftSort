/* 
* Copyright (C) 2017 James Quintero
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include "MergeSort.h"
#include "ShiftSort.h"



using namespace std;

int *array;
int num_items;

void createList();
void printArray();
int testMergeSort(int, int);
int testShiftSort(int, int);
void reverseArray(int*, int);




int main(int argc, char* argv[])
{
	
	
	num_items = 1000000;
	
	int num_runs=10;

	string to_text[]={"Best Case", "Average Case", "Worst Case"};
	
	//tests complexities with x=0 being best, x=1 being average, and x=2 being worst
	for(int x =0; x < 3; x++)
	{
		cout<<"ShiftSort "<<to_text[x]<<" Complexity test:"<<endl;
		cout<<"Running "<<num_runs<<" tests on "<<num_items<<" item array"<<endl;
		int shift_result = testShiftSort(x, num_runs);
		cout<<"ShiftSort result: "<<shift_result<<"ms"<<endl;
		cout<<"ShiftSort average: "<<shift_result/num_runs<<"ms"<<endl;
		cout<<endl;
	}

	cout<<endl<<endl;

	//tests complexities with x=0 being best, x=1 being average, and x=2 being worst
	for(int x =0; x < 3; x++)
	{
		cout<<"MergeSort "<<to_text[x]<<" Complexity test:"<<endl;
		cout<<"Running "<<num_runs<<" tests on "<<num_items<<" item array"<<endl;
		int merge_result = testMergeSort(x, num_runs);
		cout<<"MergeSort result: "<<merge_result<<"ms"<<endl;
		cout<<"MergeSort average: "<<merge_result/num_runs<<"ms"<<endl;
		cout<<endl;
	}
	
	

	// //tests the best case scenario (sorted array) for MergeSort and ShiftSort
	// MergeSort mergesort;
	// ShiftSort shiftsort;
	// num_items = 1000000;
	// createList();
	// mergesort.sort(array, num_items);

	// //test MergeSort
	// start_s=clock();
	// mergesort.sort(array, num_items);
	// stop_s=clock();
	// cout << "time: " << (stop_s-start_s) << endl;

	// //test ShiftSort
	// start_s=clock();
	// shiftsort.sort(array, num_items);
	// stop_s=clock();
	// cout << "time: " << (stop_s-start_s) << endl;

	return 0;
}

//tests ShiftSort in different complexity cases
//complexity = 0, best complexity (sorted list)
//complexity = 1, average complexity (unsorted list)
//complexity = 2, worst complexity (reverse sorted list)
int testShiftSort(int complexity, int num_tests)
{
	ShiftSort shiftsort;
	int total_time=0; 

	//best complexity
	if(complexity==0)
	{
		//sorts list first
		createList();
		shiftsort.sort(array, num_items);

		for(int x =0; x < num_tests; x++)
		{
			//test ShiftSort
			int start_s=clock();
			shiftsort.sort(array, num_items);
			int stop_s=clock();

			total_time += (stop_s-start_s);
		}
	}
	//average complexity
	else if(complexity==1)
	{
		for(int x =0; x < num_tests; x++)
		{
			//new unsorted list
			createList();

			//test ShiftSort
			int start_s=clock();
			shiftsort.sort(array, num_items);
			int stop_s=clock();

			total_time += (stop_s-start_s);
		}
	}
	//worst complexity
	else if(complexity==2)
	{

		for(int x =0; x < num_tests; x++)
		{
			createList();
			//sort the new list
			shiftsort.sort(array, num_items);
			//reverse the newly sorted list
			reverseArray(array, num_items);

			//test ShiftSort
			int start_s=clock();
			shiftsort.sort(array, num_items);
			int stop_s=clock();

			total_time += (stop_s-start_s);
		}
	}
	return total_time;
}

//tests MergeSort in different complexity cases
//complexity = 0, best complexity (sorted list)
//complexity = 1, average complexity (unsorted list)
//complexity = 2, worst complexity (reverse sorted list)
int testMergeSort(int complexity, int num_tests)
{
	MergeSort mergesort;
	
	int total_time=0; 

	//best complexity
	if(complexity==0)
	{
		//sorts list first
		createList();
		mergesort.sort(array, num_items);

		for(int x =0; x < num_tests; x++)
		{
			//test MergeSort
			int start_s=clock();
			mergesort.sort(array, num_items);
			int stop_s=clock();

			total_time += (stop_s-start_s);
		}
	}
	//average complexity
	else if(complexity==1)
	{
		for(int x =0; x < num_tests; x++)
		{
			//create a new unsorted list
			createList();

			//test MergeSort
			int start_s=clock();
			mergesort.sort(array, num_items);
			int stop_s=clock();

			total_time += (stop_s-start_s);
		}
	}
	//worst complexity
	else if(complexity==2)
	{

		for(int x =0; x < num_tests; x++)
		{
			createList();
			//sort the new list
			mergesort.sort(array, num_items);
			//reverse the newly sorted list
			reverseArray(array, num_items);

			//test MergeSort on the sorted descending list
			int start_s=clock();
			mergesort.sort(array, num_items);
			int stop_s=clock();

			total_time += (stop_s-start_s);
		}
	}

	return total_time;
}



//reverses the passed in array
void reverseArray(int *array, int size)
{
	//reverses array
	for(int i = 0; i < size/2; i++)
	{
		int temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}
}

//prints out array
void printArray()
{
	cout<<"Array: ";
	for(int x =0; x < num_items; x++)
	{
		cout<<"["<<array[x]<<"] ";
	}
	cout<<endl;
}

//creates an unsorted int array
void createList()
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(0, num_items);

	array = new int[num_items];
	for(int x =0; x < num_items; x++)
	{
		array[x] = distr(generator);
	}
}