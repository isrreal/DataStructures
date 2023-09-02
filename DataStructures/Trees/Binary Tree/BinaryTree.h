#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <sstream>

// uma árvore binária é um conjunto de vértices, chamados nós, tal que, ou ela é vazia,
// ou possui um nó chamado raíz, que possui no máximo 2 filhos


class BinaryTree {
private:
    Node* root; // ponteiro para a raiz da arvore
public:
    BinaryTree() = default; 
    BinaryTree(int key, BinaryTree& leftSubTree, BinaryTree& rightSubTree) {
        root = new Node(key, leftSubTree.root, rightSubTree.root);
        leftSubTree.root = nullptr; 
        rightSubTree.root = nullptr; 
    }
    void preOrder();
    void inOrder();
    void posOrder();
    bool contain(int key);
    void clear();
    // o tamanho de uma árvore é dita pela quantidade de nós que ela possui.
    int size();  
    // Serializar uma árvore, significa, basicamente, representar sua estrutura através de uma sequência de bytes.
    // antes de tudo, é necessário definir sua travessia(pré ordem, ordem simétrica ou pós ordem).
    std::string serialize();
};

#endif 
