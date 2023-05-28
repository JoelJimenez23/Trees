#include "node.hpp"
#include <cstddef>
#include <stdexcept>

template <typename T>
class AVL{
    NodeBT<T>* root;
public:
    AVL():root(nullptr){}
    void insert(T value){
        if(!root){root = new NodeBT<T>(value);}
        else{
            insert(root,value);
        }
    }
    bool find(T value){
        if(!root){
            NodeBT<T>* nodo = find(root,value);
            if(nodo != nullptr){return true;}
        }
        else{
            return false;
        }
    }
    int heigh(){
        return heigh(root);
    }
    T minValue(){
        if(root){
            return minValue(root)->data;
        }
        throw std::invalid_argument("root not initialized\n");
    }
    T maxValue(){
        if(root){return maxValue(root)->data;}
        throw std::invalid_argument("root not initialized\n");
    }
    bool isBalanced();
    int size();
    void remove();
    void display();
    void clear(){
        if(root){
            root->killself();
            root = nullptr;
        }
    }
    ~AVL(){clear();}
private:
    void insert(NodeBT<T>*& node,T value);
    NodeBT<T>* find(NodeBT<T>* node, T value){
        if(node == nullptr){
            return nullptr;
        }
        else if(node->data < value){
            return find(node->right,value);
        }
        else if(node->data > value){
            return find(node->left,value);
        }
        else{
            return node;
        }
    }
    int height(NodeBT<T>* node){
        if(node == nullptr){
            return -1;
        }
        return std::max(heigh(node->left),heigh(node->right)) + 1;
    }
    void updateheight(NodeBT<T>*& node){
        node->height = std::max(height(node->left),height(node->right)) + 1;
    }
    NodeBT<T>* minValue(NodeBT<T>* node){
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
    NodeBT<T>* maxValue(NodeBT<T>* node){
        while(node->right != nullptr){
            node = node->right;
        }
        return node;
    }
    void display(NodeBT<T>* node){
        if(node == nullptr){return;}
        display(node->left);
        std::cout<<node->data;
        display(node->right);
    }

    void lrota(NodeBT<T>*& node){
        NodeBT<T>* hijo_derecho = node->right;//hijo derecho de node
        node->right = hijo_derecho->left;// hijo derecho de node es ahora el hijp izquierdo del hijo derecho
        hijo_derecho->left = node;
        node = hijo_derecho;//con esto se converva los enlaces con el padre de node
    }
    void rrota(NodeBT<T>*& node){
        NodeBT<T>* hijo_izquierdo = node->left;
        node->left = hijo_izquierdo->right;
        hijo_izquierdo->right = node;
        node = hijo_izquierdo;
    }
    void lr_rota(NodeBT<T>*& node){
        lrota(node->left);
        rrota(node);
    }
    void rr_rota(NodeBT<T>*& node){
        rr_rota(node->right);
        lrota(node);
    }
    void balancear(NodeBT<T>*& node){
        if(factorBalanceo(node)>=2){
            if(factorBalanceo(node->left)<= -1){
                lrota(node);
            }
            rr_rota(node);
        }
        if(factorBalanceo(node)<= -2){
            if(factorBalanceo(node->right)>=1){
                rr_rota(node);
            }
            lr_rota(node);
        }
    }
    int factorBalanceo(NodeBT<T>* node){
        return node->left->height - node->right->height; 
    }
};
