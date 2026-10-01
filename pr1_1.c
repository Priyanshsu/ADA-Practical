// Implementation and Time analysis of sorting algorithms. Bubble sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(arr, n);

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