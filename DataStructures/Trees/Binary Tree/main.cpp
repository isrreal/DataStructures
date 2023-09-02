#include "BinaryTree.h"

int main() {
    /* Cria a arvore:
    
              3
            /   \ 
           4     5
               /   \ 
              6     7
    */

    BinaryTree empty;
    BinaryTree t4 (4, empty, empty);
    BinaryTree t6 (6, empty, empty);
    BinaryTree t7 (7, empty, empty);
    BinaryTree t5 (5, t6, t7);
    BinaryTree t3 (3, t4, t5);
    t3.preOrder();
}
