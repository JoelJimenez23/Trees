#include<iostream>
#include "BST/bst.hpp"


int main(){
    BST<int>* bstree = new BST<int>();
    bstree->insert(8);
    bstree->insert(3);
    bstree->insert(1);
    bstree->insert(6);
    bstree->insert(4);
    bstree->insert(7);
    bstree->insert(10);
    bstree->insert(14);
    bstree->insert(13);
    bstree->display();
    std::cout<<std::endl;
    std::cout<<bstree->height()<<std::endl;
    std::cout<<bstree->minValue()<<std::endl;
    std::cout<<bstree->maxValue()<<std::endl;
    return 0;
}
