#include <bit>
#include <ios>
#include<iostream>
#include "HEAP/heap.hpp"
#include <cassert> // Agregar esta línea
#include <vector>
using namespace std;


int main() {
    // int* array = new int[10];
    // array[0] = 4;
    // array[1] = 1;
    // array[2] = 3;
    // array[3] = 2;
    // array[4] = 16;
    // array[5] = 9;
    // array[6] = 10;
    // array[7] = 14;
    // array[8] = 8;
    // array[9] = 7;

    // Heap<int>* max_heap = new Heap<int>(array,10,Heap<int>::MAX_HEAP);
    // max_heap->display();

    // Heap<int>* min_heap = new Heap<int>(array,10,Heap<int>::MIN_HEAP);
    // min_heap->display();

    // Heap<int>* heap = new Heap<int>(10,Heap<int>::MAX_HEAP);
    // heap->push(4);
    // heap->push(1);
    // heap->push(3);
    // heap->push(2);
    // heap->push(16);
    // heap->push(9);
    // heap->push(10);
    // heap->push(14);
    // heap->push(8);
    // heap->push(7);

    // heap->display();
    // heap->pop();
    // heap->pop();
    // heap->pop();
    // heap->pop();
    // heap->pop();
    // heap->pop();
    // heap->pop();
    // heap->display();
    // cout<<heap->top()<<endl;
    // vector<int> vec = heap->extractTheTopK(3);
    // cout<<vec[0]<<endl;
    // cout<<vec[1]<<endl;
    // cout<<vec[2]<<endl;

    // int* b_array = new int[9];
    // b_array[0] = 36;
    // b_array[1] = 3;
    // b_array[2] = 25;
    // b_array[3] = 2;
    // b_array[4] = 19;
    // b_array[5] = 100;
    // b_array[6] = 1;
    // b_array[7] = 17;
    // b_array[8] = 7;

    int* array = new int[8];
    array[0] = 23;
    array[1] = 10;
    array[2] = 49;
    array[3] = 50;
    array[4] = 13;
    array[5] = 12;
    array[6] = 9;
    array[7] = 45;

    Heap<int>::sortAsc(array, 8);

    for(int i=0;i<8;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
