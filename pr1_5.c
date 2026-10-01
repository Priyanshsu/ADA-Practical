// Implementation and Time analysis of sorting algorithms. Quick sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    clock_t end = clock();

    printf("\n\nSorted Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nExecution Time: %f seconds\n", time_taken);

    return 0;
}