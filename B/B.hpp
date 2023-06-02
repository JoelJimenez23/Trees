#include "node.hpp"
#include <string>
#include <iostream>

template <typename T>
class BTree {
private:
  Node<T>* root;
  int M;  // grado u orden del arbol
  int n; // total de elementos en el arbol 

public:
  BTree(int _M) : root(nullptr), M(_M) {
  }
  bool search(T key){
    return static_cast<bool>(root->search(key) != nullptr);
  }
  void insert(T key){
    if(root == nullptr){
      root = new Node<T>(M);
      root->keys[0] = key;
      root->count = 1;
    }
    else{
      if(root->count == M){
        std::cout<<"Paradise city\n";
        Node<T>* newRoot = new Node<T>(M);
        newRoot->children[0] = root;
        root = newRoot;
        

      }
      insertNotFull(root,key);
    }
  }

  void remove(T key);//elimina un elemento
  int height();//altura del arbol. Considerar altura 0 para arbol vacio
  std::string toString(const std::string& sep);  // recorrido inorder
  T minKey();  // minimo valor de la llave en el arbol
  T maxKey();  // maximo valor de la llave en el arbol
  void clear(); // eliminar todos lo elementos del arbol
  int size(); // retorna el total de elementos insertados  
  ~BTree();     // liberar memoria
  void display(){
    for(int i=0;i<M;i++){
      std::cout<<root->keys[i]<<" ";
    }
    std::cout<<"\n";
  }
  void hijos(int index){
    for(int i=0;i<M;i++){
      std::cout<<root->children[index]->keys[i]<<" ";
    }
    std::cout<<"\n";
  }
private:
  void insertNotFull(Node<T>*& node, T value){
    int i = node->count -1;

    if(node->leaf){
      while(i >= 0 && node->keys[i] > value){
        node->keys[i + 1] = node->keys[i];
        i--;
      }
      i++;
      node->keys[i] = value;
      node->count++; 
    }
    else{
      while(i >= 0 && value < node->keys[i]){
          i--;
      }
      i++;
      if(node->count == M){
      }
      insertNotFull(node->children[i],value);
    }

  }


};
