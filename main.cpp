#include <ios>
#include <iostream>
#include "B/agonia.hpp"
using namespace std;




int main(){
    int M = 4;
    B<int>* b = new B<int>(M);
    b->insert(8);
    b->insert(14);
    b->insert(2);
    b->insert(15);

    b->display();
    return 0;
}
