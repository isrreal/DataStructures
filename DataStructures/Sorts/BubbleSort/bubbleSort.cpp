#include <iostream>
#include <vector>
#include <random>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Time complexity O(n²) in the worst case
void bubbleSort(std::vector<int>& vector, size_t size) {
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size - 1; j++)
            if (vector[j] >= vector[j + 1]) 
                swap(&vector[j], &vector[j + 1]);
}

void print(std::vector<int> vector, size_t size) {
    for (size_t i = 0; i < size; ++i)
        std::cout << vector[i] << " ";
}

int main() {
    constexpr size_t size = 15;
    std::random_device randomNumber;
    std::mt19937 randomSeed(randomNumber());
    std::uniform_int_distribution<int> gap(-100, 100);
    std::vector<int> vector;
    for (size_t i = 0; i < size; ++i)
        vector.push_back(gap(randomSeed));
    bubbleSort(vector, size);
    print(vector, size);
}