#include <iostream>
#include <vector>
#include <random>

// Ordena o vetor baseado na posição atual do loop, ou seja, para cada posição j, 
// ordena todos os elementos antes dele
void insertionSort(std::vector<int>& vetor, size_t tamanho) {
    // percorre todo o vetor
    for (size_t i = 0; i < tamanho - 1; ++i)
    // percorre na posicao seguinte em relação a "i" (por isso o "j = i + 1")
    // e decrementa para comparar com os elementos anteriores
        for (size_t j = i + 1; j > 0; --j)
        // comparando se o elemento na posição "j", que tambem é "i", é menor que o 
        // elemento anterior, se sim, entao ambos trocam de valores entre si  
            if (vetor[j] < vetor[j - 1]) {
                int aux = vetor[j];
                vetor[j] = vetor [j - 1];
                vetor[j - 1] = aux;
            }
}

void printar(std::vector<int> vetor, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++) 
        std::cout << vetor[i] << " ";
}

int main() {
    std::random_device randomNumber;
    std::mt19937 seed(randomNumber());
    std::uniform_int_distribution<int> gap(-100, 100);
    std::vector<int> vetor;
    constexpr int tamanho = 15;
    for (size_t i = 0; i < tamanho; ++i)
        vetor.push_back(gap(seed));
    insertionSort(vetor, tamanho);
    printar(vetor, tamanho);
}