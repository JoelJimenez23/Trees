#include <iostream>
using namespace std;


template <typename T>
struct Node{
    T* keys;
    Node** children;
    bool leaf;
    int count;
    Node():keys(nullptr),children(nullptr),count(0){}
    explicit Node(int M) : keys(new T[M -1]), children(new Node*[M]), leaf(true), count(0){}

    void nodeInsert(T value,int M){
        int index = count - 1;
        if(leaf){// una hoja, sabemos que no esta lleno por el else de abajo y la condicinal del root
            while(index >= 0 && keys[index] > value){
                keys[index + 1] = keys[index];
                --index;
            }
            index++;
            keys[index] = value;
            count++;
        }
        else{//condicion 1, baja por el arbol en busca del lugar de insercion
            while(index >= 0 && keys[index] > value){
                index--;
            }
            if(children[index]->count == M-1){//si el lugar de insercion esta lleno , split
                //split
            }
            children[index]->nodeInsert(value,M);//sino se llama de nuevo a la funcion
        }
    }

    void insertCase3(T value,int M){
        Node<T>* hijo = children[0];
        Node<T>* hijo_next = new Node<T>(M);

        


        
    }
};

template<typename T>
class B{
    Node<T>* root;
    int M;
public:
    B(int M):root(nullptr),M(M){}

    void insert(T value){
        if(root == nullptr){//condicion 1 espacio en el array
            root = new Node<T>(M);
            root->keys[0] = value;
            root->count = 1;
        }
        else{
        
        if(root->count == M){//condicion 3 root lleno
            Node<T>* newRoot = new Node<T>(M);
            newRoot->children[0] = root;
            root = newRoot;
            
        }
        root->nodeInsert(value,M);//condicion 1 y 2
        
        
        }

    }
    void display(){
        for(int i=0;i<M;i++){
            std::cout<<root->keys[i]<<" ";
        }
        std::cout<<"\n";
    }
};
