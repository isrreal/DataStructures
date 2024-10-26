#include "BinarySearchTree.hpp"

    int BinarySearchTree::heightRecursive(Node* node) {
        return !node ? 0 : 1 + std::max(BinarySearchTree::heightRecursive(node->left), BinarySearchTree::heightRecursive(node->right));
    }

    int BinarySearchTree::sizeRecursive(Node* node) {
        return !node ? 0 : 1 + BinarySearchTree::sizeRecursive(node->left) + BinarySearchTree::sizeRecursive(node->right);
    }

    void BinarySearchTree::insertRecursive(Node* node, int value) {
        if (value < node->value) {
            if (!node->left)
                node->left = new Node(value);
            else
                BinarySearchTree::insertRecursive(node->left, value);
        }
        else if (value > node->value) {
            if (!node->right)
                node->right = new Node(value);
            else
                BinarySearchTree::insertRecursive(node->right, value);
        }
        else 
        	return;
            // std::cout << "It doesn't allowed to insert a existent value" << std::endl;
    }

    Node* BinarySearchTree::deleteRecursive(Node* node, int value) {
		if (!node)
		    return nullptr;

		// Recurse to the left subtree if the value is smaller
		if (node->value > value) 
		    node->left = BinarySearchTree::deleteRecursive(node->left, value);
		
		// Recurse to the right subtree if the value is larger
		else if (node->value < value) 
		    node->right = BinarySearchTree::deleteRecursive(node->right, value);
		
		// Node to delete found
		else {
		    // Node has no left child
		    if (!node->left) {
		        Node* temp = node->right;
		        delete node;
		        return temp;
		    }
		    // Node has no right child
		    else if (!node->right) {
		        Node* temp = node->left;
		        delete node;
		        return temp;
		    }
		    // Node has two children
		    else {
		        Node* temp = BinarySearchTree::minRecursive(node->right);
		        node->value = temp->value;
		        node->right = BinarySearchTree::deleteRecursive(node->right, temp->value);
		    }
		}
		
		return node;
	}
    
    bool BinarySearchTree::findRecursive(Node* node, int value) {
        return !node ? false: node->value == value || BinarySearchTree::findRecursive(node->left, value) || BinarySearchTree::findRecursive(node->right, value);
    }

// public methods

    void BinarySearchTree::printPreOrderRecursive(Node* node) {
        if (node) {
            std::cout << node->value << " ";
            BinarySearchTree::printPreOrderRecursive(node->left);
            BinarySearchTree::printPreOrderRecursive(node->right);
        }
    }

    void BinarySearchTree::printInOrderRecursive(Node* node) {
        if (node) {
            BinarySearchTree::printInOrderRecursive(node->left);
            std::cout << node->value << " ";
            BinarySearchTree::printInOrderRecursive(node->right);
        }
    }

    void BinarySearchTree::printPostOrderRecursive(Node* node) {
        if (node) {
            BinarySearchTree::printPostOrderRecursive(node->left);
            BinarySearchTree::printPostOrderRecursive(node->right);
            std::cout << node->value << " ";
        }
    }
    
    Node* BinarySearchTree::minRecursive(Node* node) {
        if (!node)
            return nullptr;
        if (node->left)
            return  BinarySearchTree::minRecursive(node->left);
        else
            return node;
    }

     Node* BinarySearchTree::maxRecursive(Node* node) {
        if (!node)
            return nullptr;
        else if (node->right) 
            return BinarySearchTree::maxRecursive(node->right);
        else 
            return node;
    }
    
    void BinarySearchTree::preOrder() { 
        if (!root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            BinarySearchTree::printPreOrderRecursive(this->root);
    }

     void BinarySearchTree::inOrder() { 
        if (!root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            BinarySearchTree::printInOrderRecursive(this->root);
    }
    
     void BinarySearchTree::postOrder() { 
        if (!root) 
            std::cout << "Empty tree" << std::endl;
        else
            BinarySearchTree::printPostOrderRecursive(this->root);
    }

    void BinarySearchTree::insert(int value) {
        if (!root)
            root = new Node(value);
        else
            BinarySearchTree::insertRecursive(root, value);
    }
    
    bool BinarySearchTree::remove(int value) {
    	if (exists(value) && root) {
			root = BinarySearchTree::deleteRecursive(root, value);
			return true;
		}
		
		else 
			return false;
	}
    
    int BinarySearchTree::getMin() { return this->BinarySearchTree::minRecursive(this->root)->value; }
    int BinarySearchTree::getMax() { return this->BinarySearchTree::maxRecursive(this->root)->value; }
    int BinarySearchTree::getHeight() { return this->BinarySearchTree::sizeRecursive(root); }
    int BinarySearchTree::getSizeIterative() { return this->BinarySearchTree::sizeRecursive(root); }
    int BinarySearchTree::getSize() { return this->BinarySearchTree::sizeRecursive(root); }
    Node* BinarySearchTree::getRoot() { return this->BinarySearchTree::root; }
    bool BinarySearchTree::exists(int value) { return this->BinarySearchTree::findRecursive(root, value); }


