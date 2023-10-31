#include <windows.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice, a, step;
    float dd;
    printf("Задайте розмір масиву: ");
    scanf_s("%d", &a);
    int* array = new int[a];
    printf("Масив:\n");
    for (int i = 0; i < a; i++) {
        array[i] = rand() % 101;
        printf("%d ", array[i]);
    }
    printf("\n\nВиберіть метод сортування\n1 - Сортування обміном\n2 - Сортування методом вибору\n3 - Сортування методом вставками\n4 - Сортування методом Шелла\n-->");
    scanf_s("%d", &choice);
    printf("\nВідсортований масив: \n");
    clock_t start, finish;
    start = clock();
    switch (choice) {
    case 1:
        int temp, fl;
        do {
            fl = 0;
            for (int i = 1; i < a; i++) {
                if (array[i - 1] > array[i]) {
                    temp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = temp;
                    fl = 1;
                }
            }
        } while (fl);
        for (int i = 0; i < a; i++) {
            printf("%d ", array[i]);
        }
        break;
    case 2:
        int min, temp1;
        for (int i = 0; i < a; i++) {
            min = i;
            for (int j = i + 1; j < a; j++) {
                if (array[j] < array[min]) {
                    min = j;
                }
            }
            temp1 = array[i];
            array[i] = array[min];
            array[min] = temp1;
        }
        for (int i = 0; i < a; i++) {
            printf("%d ", array[i]);
        }
        break;
    case 3:
        int temp2;
        for (int i = 1; i < a; i++)
        {
            temp2 = array[i];
            for (int j = i - 1; j >= 0 && array[j] > temp2; j--)
            {
                array[j + 1] = array[j];
                array[j] = temp2;
            }
        }
        for (int i = 0; i < a; i++) {
            printf("%d ", array[i]);
        }
        break;
    case 4:
        step = a / 2;
        while (step > 0)
        {
            for (int i = 0; i < (a - step); i++)
            {
                int j = i;
                while (j >= 0 && array[j] > array[j + step])
                {
                    int c = array[j];
                    array[j] = array[j + step];
                    array[j + step] = c;
                    j--;
                }
            }
            step = step / 2;
        }
        for (int i = 0; i < a; i++) {
            printf("%d ", array[i]);
        }
        break;
    default:
        printf("\nHевірний вибір завдання\n");
    }
    finish = clock();
    dd = (float)(finish - start);
    printf("\nЧас опрацювання коду: %lf", dd);

    delete[] array;
    return 0;
}