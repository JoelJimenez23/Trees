#include "node.hpp"

template <typename T,int grado>
class Btree{
    int n;
    Node<T,grado> *root;

public:
    Btree(){
        root = new Node<T,grado>();
    }
    bool search(T key){
        return static_cast<bool>(root->search(key) != nullptr);
    }
    void insert(T key){
        if(root == nullptr){
            root = new Node<T,grado>();
            root->keys[0] = key;
            root->count++;
        }
        else{
            if(root->count == grado){
                cout<<"key "<<key<<endl;
                Node<T,grado>* newRoot = new Node<T,grado>();
                newRoot->children[0] = root;
                root = newRoot;
                root->splitChildren(0);
            }
            root->insertNotFull(key);
        }
        n++;
    }
    void remove(T key){
        root->removeNotFull(key);
        n--;
    }
    int height(){return root->height();}
    std::string toString(const  string& sep);
    T minKey(){return root->minKey();}
    T maxKey(){return root->maxKey();}
    void clear();
    int size(){return n;}
    ~Btree();

    void display(){
        for(int i=0;i<root->count;i++){
            std::cout<<root->keys[i]<<" ";
        }
        std::cout<<"\n";
    }
    void displayChildren(int index){
        if(root->children[index] != nullptr){
            for(int i=0;i<root->children[index]->count;i++){
                std::cout<<root->children[index]->keys[i]<<"    ";
            }
            std::cout<<"|";
        }
        else{
            cout<<"nullptr\n";
        }
    }
    void displayChildrenChildren(int index1,int index2){
        if(root->children[index1]->children[index2] !=nullptr){
            for(int i=0;i<root->children[index1]->children[index2]->count;i++){
                std::cout<<root->children[index1]->children[index2]->keys[i]<<" ";
            }
            std::cout<<"|";
        }
        else {
            std::cout<<"nullptr\n";
        }
    }
    T succesor(T key){
        return root->successor(key);
    }
    T predecessor(T key){
        return root->predecessor(key);
    }
};
