#include <ios>
#include <iostream>
#include "B/B.hpp"
using namespace std;




int main(){
    BTree<int>* b = new BTree<int>(2);
    b->insert(1);
    b->insert(2);
    b->insert(3);
    b->display();

    return 0;
}
