#include <array>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
using namespace std;

template<typename T>
class Heap{
public:
    enum Type{MAX_HEAP,MIN_HEAP};
private:
    T* elements;
    int capacity;
    int n;
    Type type;
public:
    Heap(T*& _elements,int _n,Type _type): elements(_elements),n(_n),type(_type),capacity(_n){
        buildHeap();
    }
    Heap(int _capacity,Type _type):capacity(_capacity),n(0), type(_type){
        elements = new T[capacity];
    }
    ~Heap(){delete [] elements;}
    void buildFromArray(T* arr, int n){
        elements = new T[n];
        for (int i = 0; i < n; i++) {
            elements[i] = arr[i];
        }
        this->n = n;
        buildHeap();
    }
    int size(){return n;}
    bool is_empty(){
        return n == 0;
    }
    void push(T value){
        if(n == capacity){
            capacity *= 2;
            T* new_array = new T[capacity];
            for(int i=0;i<n;i++){
                new_array[i] = elements[i];
            }
            delete [] elements;
            this->elements = new_array;
        }
        elements[n++] = value;
        heapify_up(elements,n-1);
    }
    T pop(){
        if(n == 0){
            throw out_of_range("heap empty\n");
        }
        T root = elements[0];
        elements[0] = elements[--n];
        heapify_down(elements,0);
        return root;
    }
    T top(){
        return elements[0];
    }
    vector<T> extractTheTopK(int k){
        if(k < 0 || k > n){
            throw out_of_range("index out of range\n");
        }
        vector<T> result;
        Heap<T> heap(*this);
        for(int i=0;i<k;i++){
            result.push_back(heap.pop());
        }
        return result;
    }

    static void sortAsc(T*& arr,int n){
        Heap heap(arr,n,MAX_HEAP);
        T* new_array = new T[n];
        for(int i=0;i<n;i++){
            new_array[i] = heap.pop(); 
        }
        arr = new_array;
    }
    static void sortDesc(T*& arr,int n){
        Heap heap(arr,n,MIN_HEAP);
        T* new_array = new T[n];
        for(int i=0;i<n;i++){
            new_array[i] = heap.pop(); 
        }
        arr = new_array;
    }
    void display(){
        for(int i=0;i<n;i++){
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    }
private:
    int Parent(int i){return (i - 1)/2;}
    int Left(int i){return 2 * i + 1;}
    int Right(int i){return 2 * i + 2;}
    void buildHeap(){
        int index = (n/2) -1;
        while(index > -1){
            heapify_down(elements,index);
            index--;
        }
    }
    void heapify_down(T*& elements ,int i){//cambiar siempre con el mayor
        int left = Left(i);
        int right = Right(i);
        int mas_grande = i;

        if(type == MAX_HEAP){
            if(left < n && elements[left] > elements[mas_grande]){
                mas_grande = left;
            }
            if(right < n && elements[right] > elements[mas_grande]){
                mas_grande = right;
            }
        }
        else if(type == MIN_HEAP){
            if(left < n && elements[left] < elements[mas_grande]){
                mas_grande = left;
            }
            if(right < n && elements[right] < elements[mas_grande]){
                mas_grande = right;
            }
        }
        if(mas_grande != i){
            swap(elements[i],elements[mas_grande]);
            heapify_down(elements,mas_grande);
        }
    }
    void heapify_up(T*& elements,int i){
        int padre = Parent(i);
        if(type == MAX_HEAP){
            if(elements[padre] < elements[i]){
                swap(elements[padre],elements[i]);
                heapify_up(elements,padre);
            }
        }
        else if(type == MIN_HEAP){
            if(elements[padre] > elements[i]){
                swap(elements[padre],elements[i]);
                heapify_up(elements,padre);
            }
        }
    }
};
