// Implementation and Time analysis of factorial program using iterative and  recursive method

#include <stdio.h>
#include <time.h>

long long iterativeFactorial(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

long long recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;
    clock_t start, end;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();

    printf("\nIterative Factorial = %lld",
           iterativeFactorial(n));

    end = clock();

    printf("\nTime = %f seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();

    printf("\nRecursive Factorial = %lld",
           recursiveFactorial(n));

    end = clock();

    printf("\nTime = %f seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}