#include <ios>
#include <iostream>
#include "B/agonia.hpp"
using namespace std;




int main(){
    int M = 4;

    Btree<int>* bcito = new Btree<int>(M);


    bcito->insert(8);//
    bcito->insert(14);//
    bcito->insert(2);//
    bcito->insert(15);//
    bcito->insert(3);//
    bcito->insert(1);//
    bcito->insert(16);//
    bcito->insert(6);//
    bcito->insert(5);//
    bcito->insert(27);
    bcito->insert(37);
    bcito->insert(18);
    bcito->insert(25);
    bcito->insert(7);
    bcito->insert(13);
    bcito->insert(20);
    bcito->insert(22);
    bcito->insert(23);
    bcito->insert(24);
    bcito->insert(26);
    bcito->insert(28);
    bcito->insert(29);
    bcito->insert(30);
    bcito->insert(40);
    bcito->insert(41);
    bcito->insert(42);





    cout<<"         ";
    bcito->display();
    cout<<"     ";
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    bcito->displayChildren(2);
    bcito->displayChildren(3);

    bcito->displayChildren(4);
    cout<<endl;
    bcito->displayChildrenChildren(0,0);
    cout<<" | ";
    bcito->displayChildrenChildren(0,1);
    cout<<" | ";
    bcito->displayChildrenChildren(0,2);
    cout<<" | ";
    bcito->displayChildrenChildren(0,3);
    cout<<" | ";
    // bcito->displayChildrenChildren(0,4);
    cout<<" || ";
    bcito->displayChildrenChildren(1,0);
    cout<<" | ";
    bcito->displayChildrenChildren(1,1);
    cout<<" | ";
    bcito->displayChildrenChildren(1,2);
    cout<<" | ";
    bcito->displayChildrenChildren(1,3);
    cout<<" | ";
    bcito->displayChildrenChildren(1,4);
    cout<<" | ";

    return 0;
}
