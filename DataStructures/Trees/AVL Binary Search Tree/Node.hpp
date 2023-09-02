#ifndef NODE_HPP
#define NODE_HPP

    #include <iostream>

    // The nodes of a so-called AVL tree store the height of each node to perform balancing.
    struct Node {
        int value;
        int height;        
        Node* left;
        Node* right;
        Node* parent;
        Node(int value, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr, int height = 1): value(value), left(left), right(right), parent(parent), height(height) {}
    };
#endif