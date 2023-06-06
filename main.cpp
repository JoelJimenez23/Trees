#include <ios>
#include <iostream>
#include "B/agonia.hpp"
using namespace std;




int main(){
    int M = 4;

    Btree<int>* bcito = new Btree<int>(M);


    bcito->insert(8);
    bcito->insert(14);
    bcito->insert(2);
    bcito->insert(15);
    bcito->insert(3);
    bcito->insert(1);
    bcito->insert(16);
    bcito->insert(6);
    bcito->insert(5);
    bcito->insert(7);
    bcito->insert(20);
    bcito->insert(22);
    bcito->insert(23);
    bcito->insert(24);
    bcito->insert(17);
    bcito->insert(26);
    bcito->insert(28);
    bcito->insert(10);


    cout<<"      ";
    bcito->display();
    bcito->displayChildren(0);
    cout<<" | ";
    bcito->displayChildren(1);
    cout<<" | ";
    bcito->displayChildren(2);
    cout<<" | ";
    bcito->displayChildren(3);
    cout<<" | ";
    bcito->displayChildren(4);
    cout<<endl;
    bcito->displayChildrenChildren(1,1);

    return 0;
}
