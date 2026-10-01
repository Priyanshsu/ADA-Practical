// Implementation and Time analysis of sorting algorithms. Selection sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selectionSort(arr, n);

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