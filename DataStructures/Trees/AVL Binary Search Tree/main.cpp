#include "BinarySearchTreeAVL.hpp"

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

// A binary tree, by definition, is a set of vertices, called nodes,
// such that it is either empty or has a root node with at most 2 children.

int main() {
    constexpr int MIN = -100;
    constexpr int MAX = 100;
    int input = 0;
    BinarySearchTreeAVL* avlTree = new BinarySearchTreeAVL();
    // Generate a random number in itself constructor

    std::random_device randomNumber;
    std::mt19937 seed(randomNumber());

    // Generates a seed based on the random number generated in the constructor of std::random_device.    std::mt19937 seed(randomNumber());
    // Uniformly distributes discrete numbers, meaning within a defined range.

    std::uniform_int_distribution<int> gap(MIN, MAX);
    for (size_t i = 0; i < 10; ++i)
        avlTree->insert(gap(seed));
    
    while (true) {

        std::cout << "AVL MENU\n\n" << std::endl;
        std::cout << "Press 1 to insert a value." << std::endl;
        std::cout << "Press 2 to see a pre order traversal." << std::endl;
        std::cout << "Press 3 to see a in order traversal" << std::endl;
        std::cout << "Press 4 to see a post order traversal." << std::endl;
        std::cout << "Press any otter button to close aplication." << std::endl;
        std::cin >> input;                    

        if (input == 1) {
            int temp = 0;
            std::cout << "Type the value to add on tree." << std::endl;
            std::cin >> temp;
            avlTree->insert(temp);    
            std::cin.ignore(1, '\n');
            std::cin.get();
        }        

        else if (input == 2) {
            avlTree->preOrder();
            std::cin.ignore(1, '\n');
            std::cin.get();
        }       

        else if (input == 3) {
            avlTree->inOrder();
            std::cin.ignore(1, '\n');
            std::cin.get();
        }

        else if (input == 4) {
            avlTree->postOrder();
            std::cin.ignore(1, '\n');
            std::cin.get();
        }

        else {
            std::cout << "Closing aplication...";
            break;
        }
        clearScreen();
    }
    return 0;
}
