#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <sstream>

// uma árvore binária é um conjunto de vértices, chamados nós, tal que, ou ela é vazia,
// ou possui um nó chamado raíz, que possui no máximo 2 filhos


class BinaryTree {
private:
    Node* root;
    void insertRecursive(Node* node, int value);
    Node* clearRecursive(Node* node);
    
    void preOrderRecursive(Node* node);
	void posOrderRecursive(Node* node);
	void inOrderRecursive(Node* node);

	bool containRecursive(Node* node, int key);

	int sizeRecursive(Node* node);
	void serializeRecursive(Node* node, std::stringstream& ss);
	int summationOfKeysRecursive(Node* node);
	int minKeyRecursive(Node* node);

	int oneChildRecursive(Node* node);
    
public:
    BinaryTree() = default; 
    
    BinaryTree(int key) {
    	this->root = new Node(key);	
    }
     
    BinaryTree(int key, BinaryTree& leftSubTree, BinaryTree& rightSubTree) {
        root = new Node(key, leftSubTree.root, rightSubTree.root);
        leftSubTree.root = nullptr; 
        rightSubTree.root = nullptr; 
    }
    
    ~BinaryTree();
    
    void preOrder();
    void inOrder();
    void posOrder();
    bool contain(int key);
    void clear();
    
    void insert(int value);
    // o tamanho de uma árvore é dita pela quantidade de nós que ela possui.
    int size();  
    int oneChild();
	int summationOfKeys();
	int minKey();
	bool empty();

    // Serializar uma árvore, significa, basicamente, representar sua estrutura através de uma sequência de bytes.
    // antes de tudo, é necessário definir sua travessia(pré ordem, ordem simétrica ou pós ordem).
    std::string serialize();
};

#endif 
