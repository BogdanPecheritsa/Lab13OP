#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <vector>

void shellSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; i++) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(nullptr)));

    int sizes[] = { 1000, 10000, 100000 };

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int size = sizes[i];
        std::vector<int> array(size);

        for (int j = 0; j < size; j++) {
            array[j] = rand() % 1000;
        }

        clock_t start, finish;

        start = clock();
        shellSort(array);
        finish = clock();
        printf("Shell Sort for size %d: %lf seconds\n", size, (double)(finish - start) / CLOCKS_PER_SEC);

        array.clear();
    }

    return 0;
}