#ifndef BINARYSEARCHTREEAVL_HPP
#define BINARYSEARCHTREEAVL_HPP

#include "Node.hpp"
#include <algorithm>
#include <random>

class BinarySearchTreeAVL {
private:
    Node* root;
    int sizeRecursive(Node* node);
    int treeHeightRecursive(Node* node);
    // int iterativeHeight(Node* node);
    int balance(Node* node);
    int nodeHeight(Node* node);
    Node* insertRecursive(Node* node, int value);
    void printPreOrderRecursive(Node* node) const;
    void printInOrderRecursive(Node* node) const;
    void printPostOrderRecursive(Node* node) const;
    void bShow(Node* node, std::string heritage) const;
    bool findRecursive(Node* node, int value);
    Node* deleteRecursive(Node* node, int value);
    Node* minRecursive(Node* node);
    Node* maxRecursive(Node* node);
    Node* rightRotation(Node* node);
    Node* leftRotation(Node* node);
    Node* leftRightRotation(Node* node);
    Node* rightLeftRotation(Node* node);

public:
    explicit BinarySearchTreeAVL(): root(nullptr) {}
    explicit BinarySearchTreeAVL(int value): root(new Node(value)) {}
    void insert(int value);
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteKey(int value);
    // int getTreeHeight();
    int getTreeSize();
    // int getSizeIterative();
    void clone();
    Node* getRoot() const;
    int getMin();
    int getMax();
    bool exists(int value);
};
#endif