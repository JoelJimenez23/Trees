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
        
      }
      root->inner_insert(key);
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


private:

};
