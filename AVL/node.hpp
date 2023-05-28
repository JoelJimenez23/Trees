#include <iostream>
template <typename T>
struct NodeBT{
    T data;
    int height;
    NodeBT<T>* left;
    NodeBT<T>* right;
    NodeBT():left(nullptr),right(nullptr),height(0){}
    explicit NodeBT(T value):left(nullptr),right(nullptr),height(0),data(value){}
    void killself(){
        if(left != nullptr){left->killself();}
        if(right != nullptr){right->killself();}
        delete this;
    }
};
