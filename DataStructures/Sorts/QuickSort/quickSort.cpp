#include <iostream>
#include <vector>
#include <random>

void swap(int& elemento, int& elemento2) {
    int temp = elemento;
    elemento = elemento2;
    elemento2 = temp;
}

int partition(std::vector<int>& vetor, int inicio, int fim) {
    // selecionando o elemento pivô
    int pivo = vetor[fim];
    // índice do menor elemento
    int menorElemento = inicio;
    for (int i = inicio; i < fim; ++i)
    // compara se o elemento é menor ou igual ao pivô 
        if (vetor[i] <= pivo)
            // se o elemento for menor ou igual, a posição do menor elemento incrementa 
            // e troca o índice de comparação pela posição atual 
            swap(vetor[menorElemento++], vetor[i]);
    // troca o pivô pelo elemento da posição do menor índice,
    // assim tendo a parte esquerda, que é menor que o pivô, já ordenada em relação a ele 
    swap(vetor[menorElemento], vetor[fim]);
    // retornando a posição do pivô, já ordenada
    return menorElemento;
}
void quickSort(std::vector<int>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivot = partition(vetor, inicio, fim);
        // faz o quicksort da parte esquerda em relação ao pivô,
        // do início do array, até uma posição antes do pivô.
        quickSort(vetor, inicio, pivot - 1);
        // faz o quicksort da parte direita em relação ao pivô,
        // de uma posição depois do pivô, até o último elemento do array
        quickSort(vetor, pivot + 1, fim);
    }
}

void printar(std::vector<int> vetor) {
    for (int it: vetor)
        std::cout << it << " ";
}

int main() {
    std::random_device randomNumber;
    std::mt19937 seed(randomNumber());
    std::uniform_int_distribution<int> gap(-100, 100);
    constexpr size_t tamanho = 100;
    std::vector<int> vetor(100);
    for (size_t i = 0; i < tamanho; ++i)
        vetor[i] = gap(seed);
    std::cout << "Vetor nao ordenado: ";
    printar(vetor);
    quickSort(vetor, 0, 20);
    std::cout << "\nVetor ordenado: ";
    printar(vetor);
}