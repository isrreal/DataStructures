#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "Node.hpp"

class BinarySearchTree {
private:
    Node* root;
    int sizeRecursive(Node* node);
    int heightRecursive(Node* node);
    int iterativeHeight(Node* node);
    void insertRecursive(Node* node, int value);
    void printPreOrderRecursive(Node* node);
    void printInOrderRecursive(Node* node);
    void printPostOrderRecursive(Node* node);
    bool findRecursive(Node* node, int value);
    Node* deleteRecursive(Node* node, int value);
    Node* minRecursive(Node* node);
    Node* maxRecursive(Node* node);
public:
    explicit BinarySearchTree(): root(nullptr) {}
    explicit BinarySearchTree(int value): root(new Node(value)) {}
    void insert(int value);
    void preOrder();
    void inOrder();
    void postOrder();
    bool remove(int value);
    int getHeight();
    int getSize();
    int getSizeIterative();
    void clone();
    Node* getRoot();
    int getMin();
    int getMax();
    bool exists(int value);
};
#endif
