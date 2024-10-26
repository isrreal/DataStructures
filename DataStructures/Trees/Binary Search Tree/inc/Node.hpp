#ifndef NODE_H
#define NODE_H
    #include <iostream>
    #include <algorithm>
    #include <random>
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int value, Node* left = nullptr, Node* right = nullptr): value(value), left(left), right(right) {}
    };
#endif
