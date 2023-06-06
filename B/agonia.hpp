#include "node.hpp"
#include <iostream>
using namespace std;
template<typename T>
class Btree{
    int grado;
    int nNodos;
    Node<T>* root;
public:
    Btree(int M):grado(M),root(nullptr){}
    void insert(T value){
        if(root == nullptr){
            root = new Node<T>(grado);
            root->keys[0] = value;
            root->count = 1;
        }
        else {
            if(root->count == grado){
                auto newRoot = new Node<T>(grado);
                newRoot->children[0] = root;
                newRoot->count = 0;
                root = newRoot;
                root->splitChildren(0);
            }
            insertNoFull(root,value);
        }
    }

    void insertNoFull(Node<T>*& node,T value){
        int index = node->count-1;
        if(node->leaf == true){
            while(index >=0 && value < node->keys[index]){
                node->keys[index + 1] = node->keys[index];
                index--;
            }
            node->keys[index + 1] = value;
            node->count++;
        }
        else{
            while(index >= 0 && value < node->keys[index]){
                index--;
            }
            index++;
            if(node->children[index]->count == grado){
                node->splitChildren(index);
                if(value > node->keys[index]){
                    index++;
                }                
            }
            insertNoFull(node->children[index],value);
        }
    }
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
    }
    void displayChildrenChildren(int index1,int index2){
        if(root->children[index1]->children[index2] !=nullptr){
            for(int i=0;i<root->children[index1]->children[index2]->count;i++){
                std::cout<<root->children[index1]->children[index2]->keys[i]<<" ";
            }
        }
        else {
            std::cout<<"nullptr\n";
        }
    }
};
