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

    // void insert_root(T value){
    //     keys[0] = value;
    //     count++;
    // }    
    // void insertCaso1(T value){
    //     int i = count - 1;
    //     if(leaf){
    //         while(i >= 0 && value < keys[i]){
    //             keys[i + 1] = keys[i];
    //             i--;
    //         }
    //         i++;
    //         keys[i] = value;
    //         count++;
    //     }
    //     else{
    //         while(i >= 0 && value < keys[i]){
    //             i--;
    //         }
    //         i++;
    //         if(count == grado){

    //         }
    //         children[i]->insertCaso1(value);
    //     }

    // }
    // void insert(T value){
    //     if(grado == count){
    //         Node<T>* newRoot = new Node<T>(grado);
    //         newRoot->children[0] = this;

    //         keys[0] = value;
    //     }
    //     else{
    //         insertCaso1(value);
    //     }
    // }


    void killself();
};
