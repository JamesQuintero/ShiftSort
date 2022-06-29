/* 
* Copyright (C) 2017 James Quintero
*/

#include <iostream>
#include <math.h>
#include "ShiftSort.h"

using namespace std;

ShiftSort::ShiftSort()
{
  
}


void ShiftSort::sort(int *array, int size)
{

    int temp = size/2 + 2;
    //list of indices denoting the start of sorted sublists in array
    int *zero_indices = new int[temp];
    zero_indices[0]=size;

    int end_tracker=1;

    //start at end of the array because swapping for ascending order is easier
    for(int x = size-1; x>=1; x--)
    {
        //if current element is out of order in respect to the element before it
        if(array[x] < array[x-1])
        {
            //if both current element is out of order and the element before it, then we need to swap them
            if(x>1 && array[x-1] < array[x-2])
            {
                //swaps array elements
                int temp = array[x-2];
                array[x-2] = array[x];
                array[x] = temp;
                
                //not at last index
                if(x!=size-1)
                {
                    //if previously traversed index is now out of order
                    if(array[x+1]<array[x])
                    {
                        zero_indices[end_tracker]=x+1;
                        end_tracker++;
                    }
                }
              
            }
            else
            {
              zero_indices[end_tracker]=x;
              end_tracker++;
            }
            //skips an index
            x--;
        }
    }
    zero_indices[end_tracker]=0;

    //runs divide and conquer algorithm on the derivative index
    split(array, zero_indices, 0, end_tracker);

    delete[] zero_indices;
}


void ShiftSort::split(int *array, int *zero_indices, int i, int j)
{
  //if have exactly 3 indices, then merge the 2 lists
  if( (j-i)==2 )
  {
      merge(array, zero_indices[j], zero_indices[j-1], zero_indices[i]);
      return;
  }
  //too few indices to know the bounds of the sublists in array
  else if( (j-i)<2 )
      return;

  //at this point, have >3 items, so split in half again
  int new_j = i + (j-i)/2;
  int new_i = new_j+1;

  //continues splitting first half
  split(array, zero_indices, i, new_j);
  //continues splitting second half
  split(array, zero_indices, new_i, j);

  //merges first half
  merge(array, zero_indices[new_i], zero_indices[new_j], zero_indices[i]);
  //merges second half
  merge(array, zero_indices[j], zero_indices[new_i], zero_indices[i]);
}



void ShiftSort::merge(int *array, int first_index, int second_index, int third_index)
{
  //if first_list>second_list, have second list be the list that gets merged into the first list
  if(second_index-first_index > third_index-second_index)
  {
      //gets 2nd list
      int *temp_2nd = new int[third_index-second_index];
      int counter=0;
      for(int y =second_index; y < third_index; y++)
      {
          temp_2nd[counter]=array[y];
          counter++;
      }
      
      //starts off at length of 2nd list
      int second_counter=third_index-second_index;
      int left=second_index-1;
      while(second_counter>0)
      {
          //shift if left is greater than right
          if(left>=first_index && array[left]>temp_2nd[second_counter-1])
          {
              array[left+second_counter]=array[left];
              left--;
          }
          //add from 2nd if greater than left
          else
          {
              array[left+second_counter]=temp_2nd[second_counter-1];
              second_counter--;
          }
      }
      delete[] temp_2nd;

  }
  else
  {
      //gets 1st list
      int *temp_1st = new int[second_index-first_index];
      int counter=0;
      for(int y =first_index; y < second_index; y++)
      {
          temp_1st[counter]=array[y];
          counter++;
      }

      //starts off at length of 2nd list
      int first_counter=0;
      int length = second_index-first_index;
      int temp_length = second_index-first_index;
      int right=second_index;
      while(first_counter< length)
      {
          //shift if left is greater than right
          if(right<third_index && array[right]<temp_1st[first_counter])
          {
              array[right-temp_length]=array[right];
              right++;
          }
          //add from 2nd if greater than left
          else
          {
              array[right-temp_length]=temp_1st[first_counter];
              first_counter++;
              temp_length--;
          }
      }

      delete[] temp_1st;
  }
  
  
}




