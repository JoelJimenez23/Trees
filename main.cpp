#include <bit>
#include <ios>
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
    std::cout<<bstree->successor(3)<<std::endl;
    std::cout<<bstree->successor(4)<<std::endl;
    std::cout<<bstree->successor(7)<<std::endl;
    std::cout<<bstree->successor(13)<<std::endl;
    std::cout<<"predecessor\n";
    std::cout<<bstree->predecessor(4)<<std::endl;
    std::cout<<bstree->predecessor(8)<<std::endl;
    std::cout<<bstree->predecessor(10)<<std::endl;
    std::cout<<bstree->predecessor(13)<<std::endl;
    std::cout<<std::boolalpha<<bstree->isBalanced()<<std::endl;
    std::cout<<std::boolalpha<<bstree->isFull()<<std::endl;
    bstree->clear();
    int array[] = {1,5,7,8,9,11,12,13,15,18,20,22,25,26};
    bstree->buildFromOrderedArray(array, 14);    
    bstree->display();
    std::cout<<"\nis balanced? "<<std::boolalpha<<bstree->isBalanced()<<std::endl;
    return 0;
}
