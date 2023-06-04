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

        // for(int i=middle_index,j=0; i <grado-1;i++,j++){
        //     sibling->keys[j] = origin->keys[i];
        // }
        //asignar count a los hijos divididos
        origin->count = middle_index;
        sibling->count = grado - middle_index-1;

        //insertar en el padre provicional     OJO
        int paren_index = count-1;
        while(paren_index >= 0 && origin->keys[middle_index] < keys[paren_index]){
            keys[paren_index + 1] = keys[paren_index];
            paren_index--;
        }
        paren_index++;
        keys[paren_index] = origin->keys[middle_index];
        count++;
        leaf = false;

        //modificar children
        int index_children = count;
        while(index_children >= childToSplit + 1){
            children[index_children  + 1] = children[index_children];
            index_children--;
        }
        index_children++;
        children[index_children] = sibling;


    }


    void killself();
};
