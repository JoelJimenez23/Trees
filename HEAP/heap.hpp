#include <array>
#include <iostream>
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
    Heap(T* _elements,int _n,Type _type): elements(_elements),n(_n),type(_type),capacity(_n){
        buildHeap();
    }
    Heap(int _capacity,Type _type):capacity(_capacity),type(_type){
        elements = new T[capacity];
    }
    ~Heap();
    void buildFromArray(T* elements, int n);
    int size();
    bool isEmpty();
    void push(T value){
        elements[++n] = value;
        heapify_up(elements,value);
    }
    T pop();
    T top();
    vector<T> extractTheTopK(int k);
    static void sortAsc(T* arr,int n);
    static void sortDesc(T* arr,int n);
    void display(){
        for(int i=0;i<capacity;i++){
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
            if(elements[padre] < elements[i]){
                swap(elements[padre],elements[i]);
                heapify_up(elements,padre);
            }
        }
    }

};
