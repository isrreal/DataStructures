#include "BinaryTree.hpp"

BinaryTree::~BinaryTree() { this->clearRecursive(root); }

void BinaryTree::preOrderRecursive(Node* node) {
    if(node) {
        std::cout << node->key << " ";
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }
}

void BinaryTree::posOrderRecursive(Node* node) {
    if(node) {
        posOrderRecursive(node->left);
        posOrderRecursive(node->right);
        std::cout << node->key << " ";
    }
}

void BinaryTree::inOrderRecursive(Node* node) {
    if(node) { 
        inOrderRecursive(node->left);
        std::cout << node->key << " ";
        inOrderRecursive(node->right);
    }
}

void BinaryTree::insertRecursive(Node* node, int value) {
    if (!node->left) 
        node->left = new Node(value);
    
    else if (!node->right) 
        node->right = new Node(value);
    
    else 
        insertRecursive(node->left, value);
}


Node* BinaryTree::clearRecursive(Node* node) {
    if(node == nullptr) { // Caso base: arvore vazia
        return nullptr;
    }
    
    else { // Caso geral
        node->left = clearRecursive(node->left);
        node->right = clearRecursive(node->right);
        delete node;
        return nullptr;
    }
}

bool BinaryTree::containRecursive(Node* node, int key) {
    return !node ? true : containRecursive(node->left, key) || containRecursive(node->right, key);
}

int BinaryTree::sizeRecursive(Node* node) {
    return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
}
void BinaryTree::serializeRecursive(Node *node, std::stringstream& ss) {
    if(!node) 
        ss << "# ";
    else {
        ss << node->key << " ";
        serializeRecursive(node->left, ss);
        serializeRecursive(node->right, ss);
    }
}

int BinaryTree::summationOfKeysRecursive(Node *node) {
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
int BinaryTree::minKeyRecursive(Node* node) {
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

int BinaryTree::oneChildRecursive(Node* node) {
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 0;
    if ((!node->left && node->right) || (!node->right && node->left))
        return 1 + oneChildRecursive(node->left) + oneChildRecursive(node->right);
    else 
        return oneChildRecursive(node->left) + oneChildRecursive(node->right);
}

bool BinaryTree::empty() {
    return root == nullptr;
}

/* Node* deserialize(std::stringstream ss) {
    std::string key;
    ss >> key;
    if (key == "#")
        return nullptr;
    else {
        Node* node = new Node(key, nullptr, nullptr);
        node->left = deserialize(ss);
        node->right = deserialize(ss);
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

bool BinaryTree::contain(int key) {
    return containRecursive(root, key);
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

void BinaryTree::insert(int value) {
	if (!root)
		root = new Node(value);
	else
		insertRecursive(root, value);
}

std::string BinaryTree::serialize() {
	std::stringstream ss;
	serializeRecursive(root, ss);
	return ss.str();
} 

