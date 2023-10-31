#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
        bubbleSort(array);
        finish = clock();
        printf("Bubble Sort for size %d: %lf seconds\n", size, (double)(finish - start) / CLOCKS_PER_SEC);

        array.clear();
    }

    return 0;
}