#include <ios>
#include <iostream>
#include "B/B.hpp"
using namespace std;




int main(){
    Btree<int,3>* bcito = new Btree<int,3>();
    bcito->insert(45);
    bcito->insert(75);
    bcito->insert(100);
    bcito->insert(36);
    bcito->insert(120);
    bcito->insert(70);
    bcito->insert(11);
    bcito->insert(111);
    bcito->insert(47);
    bcito->insert(114);

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    bcito->displayChildren(2);
    bcito->displayChildren(3);

    cout<<endl<<endl;

    bcito->remove(100);




    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    bcito->displayChildren(2);
    bcito->displayChildren(3);

    cout<<endl<<endl;

    bcito->remove(111);

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    bcito->displayChildren(2);
    bcito->displayChildren(3);


    bcito->remove(45);
    cout<<endl<<endl;

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    bcito->displayChildren(2);
    bcito->displayChildren(3);

    bcito->remove(114);
    cout<<endl<<endl;

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    bcito->displayChildren(2);
    bcito->displayChildren(3);

    bcito->insert(40);
    cout<<endl<<endl;

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    cout<<endl<<endl;
    bcito->displayChildrenChildren(0,0);
    bcito->displayChildrenChildren(0,1);
    bcito->displayChildrenChildren(1,0);
    bcito->displayChildrenChildren(1,1);

    bcito->insert(125);
    bcito->insert(115);
    cout<<endl<<endl;

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    cout<<endl;
    bcito->displayChildrenChildren(0,0);
    bcito->displayChildrenChildren(0,1);
    bcito->displayChildrenChildren(1,0);
    bcito->displayChildrenChildren(1,1);

    bcito->remove(11);

    cout<<endl<<endl;

    bcito->display();
    bcito->displayChildren(0);
    bcito->displayChildren(1);
    cout<<endl;
    bcito->displayChildrenChildren(0,0);
    bcito->displayChildrenChildren(0,1);
    bcito->displayChildrenChildren(1,0);
    bcito->displayChildrenChildren(1,1);


    return 0;
}
