#include "node.hpp"

template<typename T>
class BST{
    NodeBT<T>* root;
public:
    BST():root(nullptr){}
    void insert();
    bool find();
    int height();
    T minValue();
    T maxValue();
    void remove();
    bool isBalanced();
    int size();
    bool isFull();
    T successor(T value);
    T predecessor(T value);
    void clear();
    void buildFromOrderedArray();
};
