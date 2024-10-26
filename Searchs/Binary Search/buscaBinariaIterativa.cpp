#include <iostream>
#include <vector>
// obs: os elementos do vetor devem estar obrigatoriamente ordenados

/*
    * Busca iterativamente o item dentro do vetor vector. A cada iteração
    * reduz o espaço de busca pela metade sem fazer chamadas recursivas.
    * Ao encontrar o item retorna seu índice. Caso contrário retorna -1
*/
int buscaBinariaIterativa(std::vector<int>& vetor, int numeroRequerido) {
    int inicio = 0;
    int fim = vetor.size() - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == numeroRequerido)
            return meio;
        // se for maior, então o número está na metade direita
        if (vetor[meio] < numeroRequerido) 
        // limita o inicio à metade direita
            inicio = meio + 1;
        // senão, está na metade esquerda 
        else
            // limita o fim ao meio
            fim = meio - 1;
    }
    return -1;
}
int main() {    
    std::vector<int> vetor = {1, 3, 6, 8, 9, 890};
    int numeroRequerido = 0;
    std::cin >> numeroRequerido;
    int indiceElementoRequerido = buscaBinariaIterativa(vetor, numeroRequerido);
    std::cout << indiceElementoRequerido;
}