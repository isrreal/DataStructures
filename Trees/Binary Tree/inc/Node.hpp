#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
    struct Node {
        int key;
        Node* left; 
        Node* right;
        Node(int key, Node* left = nullptr, Node* right = nullptr): key(key), left(left), right(right) {}
};
#endif 
