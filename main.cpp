#include <bit>
#include <ios>
#include<iostream>
#include "HEAP/heap.hpp"
using namespace std;

int main()
{
    int* array = new int[10];
    // array = {4,1,3,2,16,9,10,14,8,7};  
    array[0]  = 4;
    array[1]  = 1;
    array[2]  = 3;
    array[3]  = 2;
    array[4]  = 16;
    array[5]  = 9;
    array[6]  = 10;
    array[7]  = 14;
    array[8]  = 8;
    array[9]  = 7;
    
    Heap<int>* heap = new Heap<int>(array,10, Heap<int>::MAX_HEAP);
    heap->display();
    return 0;
}
