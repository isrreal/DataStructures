#include <iostream>
#include <vector>
#include <random>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// para cada elemento, ordena ele em relação ao próximo
void bubbleSort(std::vector<int>& array, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++)
        for (size_t j = 0; j < tamanho - 1; j++)
            if (array[j] >= array[j + 1]) 
                swap(&array[j], &array[j + 1]);
}

void printar(std::vector<int> vetor, size_t tamanho) {
    for(size_t i = 0; i < tamanho; i++)
        std::cout << vetor[i] << " ";
}
int main() {
    constexpr size_t tamanho = 15;
    std::random_device randomNumber;
    std::mt19937 randomSeed(randomNumber());
    std::uniform_int_distribution<int> gap(-100, 100);
    std::vector<int> vetor;
    for (size_t i = 0; i < tamanho; i++)
        vetor.push_back(gap(randomSeed));
    bubbleSort(vetor, tamanho);
    printar(vetor, tamanho);
}