// Implementation and Time analysis of binary search algorithms.

#include <stdio.h>
#include <time.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    int low = 0, high = n - 1;
    int mid, found = -1;

    printf("Array Elements:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            found = mid;
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    clock_t end = clock();

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    if (found != -1)
        printf("Element found at position %d\n",
               found + 1);
    else
        printf("Element not found\n");

    printf("Execution Time: %f seconds\n",
           time_taken);

    return 0;
}