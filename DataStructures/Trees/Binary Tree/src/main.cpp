#include "BinaryTree.hpp"
#include <random>

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
    
    int16_t option = 0;
    int input = 0;
    
    BinaryTree* tree = new BinaryTree(rootValue);
    
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
        std::cout << "\nMenu:\n";
        std::cout << "1. Check if tree is empty\n";
        std::cout << "2. Serialize tree\n";
        std::cout << "3. Pre-order traversal\n";
        std::cout << "4. In-order traversal\n";
        std::cout << "5. Post-order traversal\n";
        std::cout << "6. Check if tree contains a key\n";
        std::cout << "7. Get size of tree\n";
        std::cout << "8. Count nodes with one child\n";
        std::cout << "9. Sum of all keys\n";
        std::cout << "10. Get minimum key\n";
        std::cout << "Any other key - Exit" << std::endl;
        std::cout << "Select an option: ";
        
        std::cin >> option;        
	    clearScreen();
	    
        if (option == 1) {
            std::cout << (tree->empty() ? "The tree is empty." : "The tree is not empty.") << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        
        else if (option == 2) {
            std::cout << "Serialized Tree: " << tree->serialize() << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 3) {
            std::cout << "Pre-order Traversal: " << std::endl;
            tree->preOrder();
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 4) {
            std::cout << "In-order Traversal: " << std::endl;
            tree->inOrder();
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 5) {
            std::cout << "Post-order Traversal: " << std::endl;
            tree->posOrder();
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 6) {
            std::cout << "Enter the key to search: ";
            std::cin >> input;
            std::cout << (tree->contain(input) ? "Key found." : "Key not found.") << std::endl;
            
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 7) {
            std::cout << "Size of tree: " << tree->size() << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 8) {
            std::cout << "Number of nodes with one child: " << tree->oneChild() << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        else if (option == 9) {
            std::cout << "Sum of all keys: " << tree->summationOfKeys() << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        } 
        
        else if (option == 10) {
            std::cout << "Minimum key: " << tree->minKey() << std::endl;
            std::cin.ignore(1, '\n');
			std::cin.get();
        }
        
        else {
        	std::cout << "Closing the aplication." << std::endl;
            break;
        }
        
        clearScreen();
     }

    delete tree;
    return 0;
}
