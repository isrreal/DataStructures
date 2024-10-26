#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

bool ternarySearch(std::vector<int> vetor, int valor, int inicio, int fim) {
    if (inicio <= fim) {
        int meio1 = inicio + (fim - inicio) / 3;
        int meio2 = fim - (fim - inicio) / 3;
        if (vetor[meio1] == valor)
            return true;
        if (vetor[meio2] == valor)
            return true;
        if (vetor[meio1] > valor)
            return ternarySearch(vetor, valor, inicio, meio1 - 1);
        else if (vetor[meio2] < valor)
            return ternarySearch(vetor, valor, meio2 + 1, fim);
        else 
            return ternarySearch(vetor, valor, meio1 + 1, meio2 - 1);
    }
    else
        return false;
}
void printar(std::vector<int> vetor) {
    for (auto it: vetor)
        std::cout << it << " ";
    std::cout << std::endl;
}
int main(int argc, char* argv[]) {
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> range(-101, 101);
    int valor = 0;
    std::vector<int> vetor(50);
    for (int i = 0; i < 50; ++i)
        vetor[i] = range(seed);
    std::sort(vetor.begin(), vetor.end());
    printar(vetor);
    std::cin >> valor;
    std::cout << (ternarySearch(vetor, valor, 0, 50) == true ? " true" : "false");
    return 0;
}