#include "BinarySearchTreeAVL.hpp"

    void BinarySearchTreeAVL::bShow(Node* node, std::string heritage) const {
        if(node && (node->left || node->right))
            bShow(node->right , heritage + "r");
        for (int i = 0; i < (int) heritage.size() - 1; i++)
            std::cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
        if (heritage != "")
            std::cout << (heritage.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << node->value << std::endl;
        if (node && (node->left || node->right))
            bShow(node->left, heritage + "l");
    }

    int BinarySearchTreeAVL::treeHeightRecursive(Node* node) {
        return !node ? 0 : 1 + std::max(treeHeightRecursive(node->left), treeHeightRecursive(node->right));
    }

    int BinarySearchTreeAVL::balance(Node* node) {
        return nodeHeight(node->right) - nodeHeight(node->left);
    }

    int BinarySearchTreeAVL::nodeHeight(Node* node) {
        return !node ? 0: node->height;
    }
    // When the node is unbalanced by its left subtree.
    
    Node* BinarySearchTreeAVL::leftRotation(Node* node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + std::max(node->left->height,node->right->height);
        temp->height = 1 + std::max(temp->left->height,temp->right->height);
        return temp;
    }

    Node* BinarySearchTreeAVL::rightRotation(Node* node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;                
        node->height = 1 + std::max(node->left->height,node->right->height);
        temp->height = 1 + std::max(temp->left->height,temp->right->height);
        return temp;
    }






    int BinarySearchTreeAVL::sizeRecursive(Node* node) {
        return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }

    Node* BinarySearchTreeAVL::insertRecursive(Node* node, int value) {
        if (!node) 
            return new Node(value);
        Node* iterator = this->root;
        while (iterator) {
            if (value < iterator->value) {
                if (!iterator->left) {
                    iterator->left = new Node(value);
                    iterator->left->parent = iterator;
                    break;
                }
                iterator = iterator->left;
            } 
            else if (value > iterator->value || value == iterator->value ) {
                if (!iterator->right) {
                    iterator->right = new Node(value);
                    iterator->right->parent = iterator;
                    break;
                }
                iterator = iterator->right;
            }
        }

        node->height = 1 + std::max(nodeHeight(node->left), nodeHeight(node->right));        
        int balance = this->balance(node);
        if (balance > 1 && value < node->right->value) {
            node->right = rightRotation(node->right);
            node = leftRotation(node);
        }

        else if (balance > 1 && value > node->right->value)
            node = leftRotation(node); 
        
        else if (balance < -1 &&  value < node->left->value)
            node = rightRotation(node);

        else if (balance < -1 && value > node->left->value) {
            node->left = leftRotation(node->left);
            node = rightRotation(node);
        }
        
        return node;
    }

    bool BinarySearchTreeAVL::findRecursive(Node* node, int value) {
        return !node ? false: node->value == value || findRecursive(node->left, value) || findRecursive(node->right, value);
    }

// public methods

    void BinarySearchTreeAVL::printPreOrderRecursive(Node* node) const {
        if (node) {
            std::cout << node->value << " ";
            printPreOrderRecursive(node->left);
            printPreOrderRecursive(node->right);
        }
    }

    void BinarySearchTreeAVL::printInOrderRecursive(Node* node) const {
        if (node) {
            printInOrderRecursive(node->left);
            std::cout << node->value << " ";
            printInOrderRecursive(node->right);
        }
    }

    void BinarySearchTreeAVL::printPostOrderRecursive(Node* node) const {
        if (node) {
            printPostOrderRecursive(node->left);
            printPostOrderRecursive(node->right);
            std::cout << node->value << " ";
        }
    }
    
    Node* BinarySearchTreeAVL::minRecursive(Node* node) {
        if (!node)
            return nullptr;
        if (node->left)
            return minRecursive(node->left);
        else
            return node;
    }

     Node* BinarySearchTreeAVL::maxRecursive(Node* node) {
        if (!node)
            return nullptr;
        else if (node->right) 
            return maxRecursive(node->right);
        else 
            return node;
    }
    
    Node* BinarySearchTreeAVL::deleteRecursive(Node* node, int value) {
        if (!node)
            return nullptr;
        else if (node->value > value)
            return deleteRecursive(node->left, value);
        else if (node->value < value)
            return deleteRecursive(node->right, value);
        else {
            // It has no left subtree.
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // It has no right subtree.
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // It has both subtrees. 

            else {
                Node* temp = minRecursive(node->right);
                node->value = temp->value;
                node->right = deleteRecursive(node->right, temp->value);
            }
            return node;
        }
    }

    void BinarySearchTreeAVL::preOrder() { 
        if (!root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            printPreOrderRecursive(this->root);
    }

     void BinarySearchTreeAVL::inOrder() { 
        if (!root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            printInOrderRecursive(this->root);
    }
     void BinarySearchTreeAVL::postOrder() { 
        if (!root) 
            std::cout << "Empty tree" << std::endl;
        else
            printPostOrderRecursive(this->root);
    }

    void BinarySearchTreeAVL::insert(int value) {
        this->root = insertRecursive(this->root, value);
    }
    int BinarySearchTreeAVL::getMin() { return this->minRecursive(this->root)->value; }
    int BinarySearchTreeAVL::getMax() { return this->maxRecursive(this->root)->value; }
    // int BinarySearchTreeAVL::getTreeHeight() { return this->sizeRecursive(root); }
    // int BinarySearchTreeAVL::getSizeIterative() { return this->sizeRecursive(root); }
    int BinarySearchTreeAVL::getTreeSize() { return this->sizeRecursive(root); }
    Node* BinarySearchTreeAVL::getRoot() const { return this->root; }
    bool BinarySearchTreeAVL::exists(int value) { return this->findRecursive(root, value); }

