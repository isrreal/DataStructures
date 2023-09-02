#include "BinaryTree.h"

void preOrderRecursive(Node* node) {
    if(node) {
        std::cout << node->key << " ";
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }
}

void posOrderRecursive(Node* node) {
    if(node) {
        posOrderRecursive(node->left);
        posOrderRecursive(node->right);
        std::cout << node->key << " ";
    }
}

void inOrderRecursive(Node* node) {
    if(node) { 
        inOrderRecursive(node->left);
        std::cout << node->key << " ";
        inOrderRecursive(node->right);
    }
}

bool containRecursive(Node* node, int key) {
    return !node ? true : containRecursive(node->left, key) || containRecursive(node->right, key);
}

int sizeRecursive(Node* node) {
    return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
}
void serializeRecursive(Node *node, std::stringstream& ss) {
    if(!node) {
        ss << "# ";
    }
    else {
        ss << node->key << " ";
        serializeRecursive(node->left, ss);
        serializeRecursive(node->right, ss);
    }
}
int summationOfKeysRecursive(Node *node) {
    if (!node)
        return 0;
    else {
        int sum = node->key;
        if (node->left)
            sum += summationOfKeysRecursive(node->left);
        if (node->right)
            sum += summationOfKeysRecursive(node->right);
        return sum;
    }
}
int minKeyRecursive(Node* node) {
    if (!node->left && !node->right)
        return node->key;
    else if (!node->left)
        return std::min(node->key, minKeyRecursive(node->right));
    else if (!node->right)
        return std::min(node->key, minKeyRecursive(node->left));
    else { 
        int valorAtual = node->key;
        int valorDaEsquerda = minKeyRecursive(node->left);
        int valorDaDireita = minKeyRecursive(node->right);
        return std::min(valorAtual, std::min(valorDaEsquerda, valorDaDireita));
    }
}

int oneChildRecursive(Node* node) {
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 0;
    if ((!node->left && node->right) || (!node->right && node->left))
        return 1 + oneChildRecursive(node->left) + oneChildRecursive(node->right);
    else 
        return oneChildRecursive(node->left) + oneChildRecursive(node->right);
}

/* Node* deserializa(std::stringstream ss) {
    std::string key;
    ss >> key;
    if (key == "#")
        return nullptr;
    else {
        Node* node = new Node(key, nullptr, nullptr);
        node->left = deserializa(ss);
        node->right = deserializa(ss);
        return node;
    }
} */

void BinaryTree::preOrder() {
    preOrderRecursive(root);
}

void BinaryTree::inOrder() {
    inOrderRecursive(root);
}

void BinaryTree::posOrder() {
    posOrderRecursive(root);
}

void BinaryTree::clear() {}

int BinaryTree::size() {
    return sizeRecursive(root);
}

int BinaryTree::oneChild() {
    return oneChildRecursive(root);
}

int BinaryTree::summationOfKeys() {
    return summationOfKeysRecursive(root);
}

int BinaryTree::minKey() {
    return minKeyRecursive(root);
}

bool BinaryTree::contain(int key) {
    return containRecursive(root, key);
}

/* std::string BinaryTree::serializar() {
    serializeRecursivo(root, " ");
} */

