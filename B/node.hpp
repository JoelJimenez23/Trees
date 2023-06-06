#include <cstddef>
#include <iostream>
using namespace std;

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

    void splitChildren(int childToSplit){
        Node<T>* origin = children[childToSplit];
        Node<T>* sibling = new Node<T>(grado);
        
        int middle_index = grado /2;

        // repartir llaves
        for(int i=middle_index + 1,j=0; i <grado;i++,j++){
            sibling->keys[j] = origin->keys[i];
        }
        
        origin->count = middle_index;
        sibling->count = grado - middle_index-1;

        if(!origin->leaf){
            for(int i=middle_index + 1,j=0; i <grado+1;i++,j++){
                sibling->children[j] = origin->children[i];
            }
        }

        //insertar en el padre provicional     OJO
        int parent_index = count-1;
        while(parent_index >= 0 && origin->keys[middle_index] < keys[parent_index]){
            keys[parent_index + 1] = keys[parent_index];
            parent_index--;
        }
        keys[parent_index + 1] = origin->keys[middle_index];
        count++;
        leaf = false;

        //modificar children
        int index_children = count;
        while(index_children >= childToSplit + 1){
            children[index_children  + 1] = children[index_children];
            index_children--;
        }
        children[index_children + 1] = sibling;

        sibling->leaf = origin->leaf;

    }


    void killself();
};
