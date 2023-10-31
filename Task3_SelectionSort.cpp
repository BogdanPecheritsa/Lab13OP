#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
        selectionSort(array);
        finish = clock();
        printf("Selection Sort for size %d: %lf seconds\n", size, (double)(finish - start) / CLOCKS_PER_SEC);

        array.clear();
    }

    return 0;
}