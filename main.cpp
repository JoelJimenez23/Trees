#include <bit>
#include <ios>
#include<iostream>
#include "AVL/avl.hpp"
using namespace std;

int main()
{
    AVL<int> *avl = new AVL<int>();

    avl->insert(35);
    avl->insert(30);
    avl->insert(27);
    avl->insert(11);
    avl->insert(16);
    avl->insert(100);
    avl->insert(50);
    avl->insert(91);
    avl->insert(73);
    avl->insert(5);
    avl->displayPreOrder();
    std::cout<<std::endl;
    std::cout<<boolalpha<<avl->isBalanced()<<std::endl;
    std::cout<<avl->height()<<std::endl;

    avl->remove(30);
    avl->remove(35);
    avl->remove(100);

    avl->displayPreOrder();
    std::cout<<std::endl;
    std::cout<<boolalpha<<avl->isBalanced()<<std::endl;
    std::cout<<avl->height()<<std::endl;


    return 0;
}