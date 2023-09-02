#include <iostream>
#include <vector>
#include <random>

void merge(std::vector<int>& vetor, int start, int mid, int end){
    // vetor resultante do merge
    std::vector<int> vetorAuxiliar;
    vetorAuxiliar.resize(end - start + 1);
    int start1 = start;
    int start2 = mid + 1;
    // inicio do vetor auxiliar
    int start3 = 0;
    // compara as duas metades do vetor já existente
    while (start1 <= mid && start2 <= end) {
        if(vetor[start1] <= vetor[start2])
            // vetor auxiliar recebe a posição
            vetorAuxiliar[start3++] = vetor[start1++];
        else
            vetorAuxiliar[start3++] = vetor[start2++];
    }
    // Atualiza o vetor já ordenado até a parte esquerda
    while (start1 <= mid)
        vetorAuxiliar[start3++] = vetor[start1++];
    // Atualiza o valor ordenado da metade até o fim
    while(start2 <= end)
        vetorAuxiliar[start3++] = vetor[start2++];
    // igualando o vetor original com o auxiliar
    for (int i = start, j = 0; i <= end; i++, j++)
        vetor[i] = vetorAuxiliar[j];
}

void mergeSort(std::vector<int>& vetor, int start, int end ){
    if(end > start){
        int mid = (start + end) / 2;
        mergeSort(vetor, start, mid);
        mergeSort(vetor, mid + 1, end);
        merge(vetor, start, mid, end);
    }
}
void printar(std::vector<int>& vetor) {
    for (auto i: vetor)
        std::cout << i << " ";
}
int main() {
    std::random_device random;
    std::mt19937 seed(random());
    std::uniform_int_distribution<int> range(-100, 100);
    std::vector<int> vetor(50);
    for (size_t i = 0; i < vetor.size(); ++i)
        vetor[i] = range(seed);
    mergeSort(vetor, 0, vetor.size() - 1);
    printar(vetor);
}

