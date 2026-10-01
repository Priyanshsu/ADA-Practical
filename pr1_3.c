// Implementation and Time analysis of sorting algorithms. Insertion sort.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n = 50;
    int arr[50];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Original Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    clock_t start = clock();

    insertionSort(arr, n);

    clock_t end = clock();

    printf("\n\nSorted Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nExecution Time: %f seconds\n", time);

    return 0;
}