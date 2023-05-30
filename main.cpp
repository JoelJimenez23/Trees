#include <bit>
#include <ios>
#include<iostream>
#include "HEAP/heap.hpp"
using namespace std;

void testMaxHeap() {
    Heap<int>* heap = new Heap<int>(10, Heap<int>::MAX_HEAP);
    heap->is_empty();
    heap->size();
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    heap->buildFromArray(array, 8);
    heap->top();
    heap->push(8);
    heap->push(55);
    heap->push(18);
    heap->top();
    heap->pop();
    heap->pop();
    heap->top();
    vector<int> topk = heap->extractTheTopK(2);
    topk[1];
    heap->size();
    delete heap;
}

void testMinHeap() {
    Heap<int>* heap = new Heap<int>(10, Heap<int>::MIN_HEAP);
    heap->is_empty();
    heap->size();
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    heap->buildFromArray(array, 8);
    heap->top();
    heap->push(8);
    heap->push(55);
    heap->push(18);
    heap->top();
    heap->pop();
    heap->pop();
    heap->top();
    vector<int> topk = heap->extractTheTopK(2);
    topk[1];
    heap->size();
    delete heap;
}

void testSortAsc() {
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    Heap<int>::sortAsc(array, 8);
    // No hay verificaciones de los elementos del array después de la ordenación ascendente
}

void testSortDesc() {
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    Heap<int>::sortDesc(array, 8);
    // No hay verificaciones de los elementos del array después de la ordenación descendente
}

int main(int argc, char const *argv[]) {
    testMaxHeap();
    testMinHeap();
    testSortAsc();
    testSortDesc();
    return 0;
}       
