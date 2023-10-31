#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
        insertionSort(array);
        finish = clock();
        printf("Insertion Sort for size %d: %lf seconds\n", size, (double)(finish - start) / CLOCKS_PER_SEC);

        array.clear();
    }

    return 0;
}