#include <iostream>
#include <vector>
#include <random>

void swap(int& maior, int& menor) {
    int aux = maior;
    maior = menor;
    menor = aux; 
}
// Selection sort seleciona uma posição específica do vetor e compara se os elementos 
// seguintes sao menores, caso forem, ambos trocam de posição.
void selectionSort(std::vector<int>& array, size_t tamanhoDoVetor) {
    int posicaoDoMenorElemento;
    // percorrendo o vetor
    for (size_t i = 0; i < tamanhoDoVetor; ++i) {
        // fazendo com que a posição do menor elemento seja o da posição i
        posicaoDoMenorElemento = i;
        // analisando se o próximo valor em relação a i seja menor
        for (size_t j = i + 1; j < tamanhoDoVetor; ++j)
        // se for, o próximo elemento for menor, troca
            if (array[j] < array[posicaoDoMenorElemento])
                posicaoDoMenorElemento = j;
        // colocando na posicao correta  
        swap(array[i], array[posicaoDoMenorElemento]);
    }
}

void printar(const std::vector<int>& array, int size)  {
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::random_device randomNumber;
    std::mt19937 seed(randomNumber());
    std::uniform_int_distribution<int> gap(-100, 100);
    std::vector<int> vetor;
    size_t tamanhoDoVetor;
    std::cin >> tamanhoDoVetor;
    for (size_t i = 0; i < tamanhoDoVetor; ++i)
        vetor.push_back(gap(seed));
        std::cout << "vetor antes de ser ordenado: ";
    printar(vetor, tamanhoDoVetor); 
    selectionSort(vetor, tamanhoDoVetor);
    std::cout << "vetor depois de ser ordenado: ";
    printar(vetor, tamanhoDoVetor); 
}