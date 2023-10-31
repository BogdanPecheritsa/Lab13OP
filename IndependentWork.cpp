#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 10, 15, 19, 11, 3, 12, 2, 91, 20, 34, 7, 4, 5, 8, 16, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Початковий массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int t = arr[i];
            arr[i] = arr[largest];
            arr[largest] = t;
            i = n;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        int largest;
        int j = 0;

        do {
            largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < i && arr[left] > arr[largest])
                largest = left;

            if (right < i && arr[right] > arr[largest])
                largest = right;

            if (largest != j) {
                t = arr[j];
                arr[j] = arr[largest];
                arr[largest] = t;
                j = largest;
            }
            else {
                break;
            }
        } while (1);
    }

    printf("\nВідсортований массив: \n");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}