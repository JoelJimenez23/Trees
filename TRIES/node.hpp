#include <iostream>
using namespace std;

template<typename T>
struct Node{
    Node* children[256];
    bool endWord;
};
