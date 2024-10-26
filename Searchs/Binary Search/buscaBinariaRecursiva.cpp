#include <iostream>
#include <vector>
// obs: os elementos do vetor devem estar obrigatoriamente ordenados

/*
    * Busca recursivamente o item dentro do vetor vector. 
    * A cada chamada recursiva reduz o espaço de busca pela metade sem fazer chamadas recursivas.
    * Ao encontrar o item retorna true. Caso contrário retorna false.
*/
bool buscaBinariaRecursiva(std::vector<int>& vetor, int inicio, int fim, int numeroRequerido) {
    int meio = (inicio + fim) / 2;
    // verifica se o vetor tem tamanho mínimo
    if (inicio > fim)
        return false;
    // se for igual, entao retorna a posição do elemento buscado
    if (vetor[meio] == numeroRequerido)
        return true;
    // se for maior, pesquisa na parte esquerda do vetor
    if (vetor[meio] > numeroRequerido) 
        // meio - 1 significa a parte esquerda
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, numeroRequerido); 
        // senao, busca na parte direita
    else 
        // meio + 1 significa a parte direita
        return buscaBinariaRecursiva(vetor, meio + 1, fim, numeroRequerido); 
}

int main() {
    std::vector<int> vetor = {1, 2, 3, 4, 5, 6, 999};
    int valor;
    std::cin >> valor;
    int posicaoDovalorBuscado = buscaBinariaRecursiva(vetor, 0, vetor.size(), valor);
    std::cout << posicaoDovalorBuscado;
}
