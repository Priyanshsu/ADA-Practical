// Implementation of max-heap sort algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n = 100;
    int arr[100];
    int i;

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    printf("--- Array Before sorting ---\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    clock_t start = clock();

    heapsort(arr, n);

    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("--- Array After sorting ---\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Execution time: %f s\n", duration);

    return 0;
}