#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int binarySearch(std::vector<int>& vetor, int inicio, int fim, int elemento) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == elemento)
            return meio;
        else if (elemento < vetor[meio])
            return binarySearch(vetor, inicio, meio - 1, elemento);
        else 
            return binarySearch(vetor, meio + 1, fim, elemento);
    }
    else 
        return -1;
}

int exponentialSearch(std::vector<int>& vetor, unsigned int tamanho, int elemento) {
    if (tamanho == 0)
        return -1;
    int limite = 1;
    while (limite < tamanho && vetor[limite] < elemento)
        limite *= 2;
    return binarySearch(vetor, limite / 2, tamanho, elemento);
}

int main() {
    constexpr int sizeof_vector = 1000;
    std::vector<int> vetor(sizeof_vector);
    std::random_device randomNumber;
    std::mt19937 seed(randomNumber());
    std::uniform_int_distribution<int> gap(0, 2000);
    for (int i = 0; i < sizeof_vector; ++i)
        vetor[i] = i;
    std::cout << std::endl;
    int random_value = gap(seed);
    std::cout << random_value << std::endl;
    std::cout << exponentialSearch(vetor, sizeof_vector, random_value);
}