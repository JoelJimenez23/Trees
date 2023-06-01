#include <iostream>

template<typename T>
struct Node{
    T* keys;//array de keys
    Node** children;//array de punteros a hijos
    int count;//cantidad de keys
    bool leaf;//indicador de nodo hoja
    int grado;
    Node():keys(nullptr),children(nullptr),count(0){}
    explicit Node(int M):grado(M){
        keys = new T[M - 1];
        children = new Node<T>*[M];
        count = 0;
        leaf = true;
    }
    Node* search(T k){
        int i=0;
        while(i<count && k > keys[i]){
            i++;
        }
        if(keys[i] == k){return this;}
        if(leaf == true){return nullptr;}
        return children[i]->search(k);
    }
    void display(){
        for(int i=0;i<grado;i++){
            std::cout<<keys[i]<<" ";
        }
        std::cout<<std::endl;
    }


    void killself();
};
