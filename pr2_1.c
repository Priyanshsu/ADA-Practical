// Implementation and Time analysis of linear search algorithms.

#include <stdio.h>
#include <time.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, found = -1;

    printf("Array Elements:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = i;
            break;
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