#include "BinarySearchTree.hpp"

// A binary tree, by definition, is a set of vertices, called nodes,
// such that it is either empty or has a root with at most two children.

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main() {
    constexpr int MIN = -100;
    constexpr int MAX = 100;
    constexpr int rootValue = 1;
    
    char option = 0;
    int input = 0;
    
    BinarySearchTree* tree = new BinarySearchTree(rootValue);
    
    // Generates a random number in the constructor
    std::random_device randomNumber;
    // Seeds the random number generator based on the random value from std::random_device
    std::mt19937 seed(randomNumber());
    
    // Distributes this range of discrete numbers uniformly, i.e., within a defined interval
    std::uniform_int_distribution<int> gap(MIN, MAX);
    
    for (size_t i = 0; i < 100; ++i)
        // Inserts a value into the tree according to the above distribution with the specified seed
        tree->insert(gap(seed));
        
     while (true) {
     	    // Display menu options
		std::cout << "Select an option:" << std::endl;
		std::cout << "1 - Display Pre-Order Traversal" << std::endl;
		std::cout << "2 - Display In-Order Traversal" << std::endl;
		std::cout << "3 - Display Post-Order Traversal" << std::endl;
		std::cout << "4 - Get Tree Height" << std::endl;
		std::cout << "5 - Get Tree Size" << std::endl;
		std::cout << "6 - Get Root Value" << std::endl;
		std::cout << "7 - Search for a Value" << std::endl;
		std::cout << "8 - Insert a New Value" << std::endl;
		std::cout << "9 - Remove a Value" << std::endl;
		std::cout << "Any other key - Exit" << std::endl;
		std::cout << "Enter your choice: ";
     	
        std::cin >> option;
	    clearScreen();
	    
        if (option == '1') {
           	tree->preOrder();
        	std::cin.ignore(1, '\n');
			std::cin.get();
        }
        
        else if (option == '2') {
        	tree->inOrder();
		    std::cin.ignore(1, '\n');
			std::cin.get();
       	}
       	
        else if (option == '3') {
        	tree->postOrder();
            std::cin.ignore(1, '\n');
			std::cin.get();
        }
        
        else if (option == '4') {
        	tree->getHeight();
        	std::cin.ignore(1, '\n');
			std::cin.get();  
        }
        
        else if (option == '5') {
        	tree->getSize();
        	std::cin.ignore(1, '\n');
			std::cin.get();    
        }
        
        else if (option == '6') {
        	tree->getRoot();
            std::cin.ignore(1, '\n');
			std::cin.get();
        }
        
        else if (option == '7') {
        	std::cout << "Insert an integer for search" << std::endl;     
			std::cin >> input;
        	std::cout << (tree->exists(input) ? "Exists" : "Do not exists") << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        }
        
        else if (option == '8') {
        	std::cout << "Insert an integer to insert" << std::endl;     
		    
			std::cin >> input;
			
            tree->insert(input);
            
        	std::cout << input << " was inserted!" << std::endl;     
            std::cin.ignore(1, '\n');
			std::cin.get();
        }
        
       else if (option == '9') {
       
			std::cout << "Insert an integer to remove: ";
			std::cin >> input;

			if (tree->remove(input)) 
				std::cout << input << " was removed!" << std::endl;
			else 
				std::cout << "This value does not exist." << std::endl;
			
			std::cin.ignore(1, '\n');
			std::cin.get();
		}
        
        else {
        	std::cout << "Closing the aplication." << std::endl;
            break;
        }
        
        clearScreen();
     }
     
     return 0;
}
