#include <iostream>
#include <string>
using namespace std;

template<typename T,int grado>
struct Node{
    T* keys;
    Node** children;
    int count;
    bool leaf;
    Node():keys(new T[grado-1]),children(new Node*[grado]),count(0),leaf(true){}
    void splitChildren(int index){
        Node<T,grado>* origin = children[index];
        Node<T,grado>* sibling = new Node<T,grado>();

        for(int i=grado/2+1,j=0;i<grado;i++,j++){
            sibling->keys[j] = origin->keys[i];// moving keys
        }
        // origin new count
        sibling->count = grado - ((grado/2)+1);
        origin->count = grado/2;

        if(!origin->leaf){
            for(int i=grado/2 + 1,j=0; i <grado+1;i++,j++){
                sibling->children[j] = origin->children[i];
                origin->children[i] = nullptr;
            }
        }

        int insert_parent_index = count - 1;
        while(insert_parent_index >= 0 && keys[insert_parent_index] > origin->keys[grado/2]){
            keys[insert_parent_index + 1] = keys[insert_parent_index];
            insert_parent_index--;
        }
        keys[++insert_parent_index] = origin->keys[grado/2];//inserting the middle value
        count++;
        leaf = false;

        int index_children = count-1;
        while(index + 1  <= index_children){
            children[index_children + 1] = children[index_children];
            index_children--;
        }
        children[++index_children] = sibling;
        sibling->leaf = origin->leaf;
    }
    void insertNotFull(T value){
        int index = count - 1;
        if(leaf){
            while(index >= 0 && value < keys[index]){
                keys[index + 1] = keys[index];
                index--;
            }
            index++;
            keys[index] = value;
            count++;
        }
        else{
            while(index >= 0 && value < keys[index]){
                index--;
            }
            index++;
            if(children[index]->count == grado){
                splitChildren(index);
                if(value > keys[index]){
                    index++;
                }
            }
            children[index]->insertNotFull(value);
        }
    }
    void deleteFromLeaf(T key){
        int index = count -1;
        while(index >= 0 && keys[index] != key){
            index--;
        }
        if(index == -1){return;}
        else{
            while(index <= count -1){
                keys[index] = keys[index + 1];
                index++;
            }
            count--;
        }
    }
    void deleteFromNonLeaf(int index,T key){
        T value = successor(key);
        keys[index] = value;
        children[index + 1]->removeNotFull(value);
    }
    void removeNotFull(T key){
        int index = count -1;
        if(leaf){
            deleteFromLeaf(key);
            return;
        }
        else{
            while(index >= 0 && keys[index] > key){
                index--;
            }
            if(key == keys[index]){
                deleteFromNonLeaf(index,key);
                return;
            }
            children[index + 1]->removeNotFull(key);
        }

        Node* current = children[index + 1];

        if(current->count == (grado/2) && current->leaf){
            if(index != -1 && (children[index]->count >= grado/2 || children[index + 2]->count >= grado /2)){

                if(children[index + 2] == nullptr){
                    current->insertNotFull(keys[index]);
                    T newPadre = children[index]->keys[children[index]->count -1];
                    children[index]->removeNotFull(newPadre);
                    keys[index] = newPadre;

                }
                else{
                    current->insertNotFull(keys[index + 1]);
                    T newPadre = children[index + 2]->keys[0];
                    children[index + 2]->removeNotFull(newPadre);
                    keys[index + 1] = newPadre;
                }
            }
            else if(index != -1 && (children[index]->count < grado /2 || children[index + 2]->count < grado / 2)){

                if(children[index + 2] == nullptr){

                    T padre = keys[index + 1];
                    current->insertNotFull(padre);

                    for(int i=0;i<children[index + 2]->count;i++){
                        current->insertNotFull(children[index + 2]->keys[i]);
                    }
                    leaf = true;
                    deleteFromLeaf(padre);
                    leaf = false;

                    int start = index + 1;
                    for(int i = start; i< count-1;i++){
                        children[i] = children[i + 1];
                    }

                }
                else{

                    T padre = keys[index];
                    current->insertNotFull(padre);
                    for(int i=0;i<children[index]->count;i++){
                        current->insertNotFull(children[index]->keys[i]);
                    }

                    leaf = true;

                    deleteFromLeaf(padre);
                    leaf = false;
                    int start = index;
                    for(int i = start; i< count-1;i++){
                        children[i] = children[i + 1];
                    }


                }
            }
        }
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
    T minKey(){
        if(children[0] == nullptr){
            return keys[0];
        }
        return children[0]->minKey();
    }
    T maxKey(){
        if(children[count] == nullptr){
            return keys[count - 1];
        }
        return children[count]->maxKey();
    }
    int height(){
        if(children[0] == nullptr){
            return 1;
        }
        else{
            return children[0]->height() + 1;
        }
    }
    void killself();

    T successor(T key){
        Node* nodito = this->search(key);
        int index = nodito->count-1;
        while(index >= 0 && key < nodito->keys[index]){
            index--;
        }
        index++;
        nodito = nodito->children[index];
        while(nodito->children[0] != nullptr){
            nodito = nodito->children[0];
        }
        return nodito->keys[0];
    }
    T predecessor(T key){
        Node* nodito = this->search(key);
        int index = nodito->count-1;
        while(index >= 0 && key < nodito->keys[index]){
            index--;
        }
        index++;
        nodito = nodito->children[index-1];
        while(nodito->children[nodito->count-1] != nullptr){
            nodito = nodito->children[nodito->count-1];
        }
        return nodito->keys[nodito->count -1];
    }

    string toString(const std::string& sep) {
        std::string result;
        bool isLeaf = leaf;

        for (int i = 0; i < count; i++) {
            if (!isLeaf) {
                result += children[i]->toString(sep);
            }
            result += std::to_string(keys[i]) + sep;
        }

        if (!isLeaf) {
            result += children[count]->toString(sep);
        }

        return result;
    }

};
