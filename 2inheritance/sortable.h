#ifndef SORTABLE_H
#define SORTABLE_H
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>

// abstract class Sortable
template <typename T>
class Sortable{
public:
    virtual T& operator [](std::size_t pos) = 0; //pure virtual functions

protected:

int partition(int start, int end)
{
 
    T pivot = (*this)[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if ((*this)[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap((*this)[pivotIndex], (*this)[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while ((*this)[i] <= pivot) {
            i++;
        }
 
        while ((*this)[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap((*this)[i++], (*this)[j--]);
        }
    }
 
    return pivotIndex;
}
void swap(T & a, T & b){
    T temp = a;
    a=b;
    b=temp;
}
 
void quickSort(int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(start, end);
 
    // Sorting the left part
    quickSort(start, p - 1);
 
    // Sorting the right part
    quickSort(p + 1, end);
}
 
};

#endif 
