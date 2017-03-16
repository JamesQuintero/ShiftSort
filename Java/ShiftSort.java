/* James Quintero */

import java.util.*;
import java.io.*;

//Hold the latest version of Shift Sort

public class ShiftSort
{
  
  public ShiftSort()
  {
    
  }
  
  //ShiftSortV10
  public void sort(int[] array)
  {
      //gets indexes of array that indicate the start of sorted sublists
      //Old versions of Shift Sort had a list of 0s and 1s that indicate where in the array the elements were out of order. 
      //A 0 meant the value at the current index was less than the value at the previous index, and was therefore out of order. A 1 meant they were in order
      int[] zero_indices = new int[(int)(array.length/2)+2];
      zero_indices[0]=array.length;
      
      //tracks the index of the last added value in zero_indices
      int end_tracker=1;
      
      //stops at x<1 because 0 being a zero_index is a given
      for(int x = array.length-1; x >= 1; x--)
      {
          //if cur index is out of order
          if(array[x]<array[x-1])
          {
              //if lower index is also out of order, then swap
              if(x>1 && array[x-1] < array[x-2])
              {
                  //swaps array elements
                  int temp = array[x-2];
                  array[x-2] = array[x];
                  array[x] = temp;
                  
                  if( x != array.length-1)
                  {
                      if(array[x+1]<array[x])
                      {
                          zero_indices[end_tracker]=x+1;
                          end_tracker++;
                      }
                  }
              }
              else
              {
                  zero_indices[end_tracker] = x;
                  end_tracker++;
              }

              //skips
              x--;
          }
      }
      
      
      //merges sorted lists specified by zero_indices
      split(array, zero_indices, 0, end_tracker);
    
  }
  
  //splits zero_indices into sublists of indices in array
  public void split(int[] array, int[] zero_indices, int i, int j)
  {
      //if have exactly 3 indices, then merge the 2 lists
      if( (j-i)==2)
      {
          merge(array, zero_indices[j], zero_indices[j-1], zero_indices[i]);
          return;
      }
      //2 indices or less, just return, because not enough to merge
      else if( (j-i)<2)
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
  
  //merges from the back to front
  public void merge(int[] array, int first_index, int second_index, int third_index)
  {
      //if first_list>second_list, have second list be the list that gets merged into the first list
      if(second_index-first_index > third_index-second_index)
      {
          //gets 2nd list
          int[] temp_2nd = new int[third_index-second_index];
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
              if(left>=first_index && array[left]>=temp_2nd[second_counter-1])
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
      }
      else
      {
          //gets 1st list
          int[] temp_1st = new int[second_index-first_index];
          int counter=0;
          for(int y =first_index; y < second_index; y++)
          {
            temp_1st[counter]=array[y];
            counter++;
          }
          
          //starts off at length of 2nd list
          int first_counter=0;
          int temp_length = second_index-first_index;
          int right=second_index;
          while(first_counter< temp_1st.length)
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
      }
  }
  
}