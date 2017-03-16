/* 
* Copyright (C) 2017 James Quintero
*/

#include <iostream>

class ShiftSort{
    private:
        void split(int*, int*, int, int);
        void merge(int*, int, int, int);
    public:
        ShiftSort();
        void sort(int*, int);
  
};
