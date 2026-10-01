// Implementation of a knapsack problem using dynamic programming.

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int n, int weights[], int profits[], int capacity)
{
    int dp[n + 1][capacity + 1];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (weights[i - 1] <= j)
            {
                dp[i][j] = max(profits[i - 1] + dp[i - 1][j - weights[i - 1]],
                               dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("\n===== Dynamic Programming Table =====\n");
    printf("Item\t");

    for (j = 0; j <= capacity; j++)
    {
        printf("%d\t", j);
    }

    printf("\n");

    for (i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            printf("0(None)\t");
        }
        else
        {
            printf("%d(w:%d,p:%d)\t", i, weights[i - 1], profits[i - 1]);
        }

        for (j = 0; j <= capacity; j++)
        {
            printf("%d\t", dp[i][j]);
        }

        printf("\n");
    }

    printf("\n==============================\n");
    printf("Maximum Profit = %d\n", dp[n][capacity]);

    printf("\nSelected Items Summary:\n");
    printf("Item\tWeight\tProfit\n");

    i = n;
    j = capacity;

    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            printf("%d\t%d\t%d\n", i, weights[i - 1], profits[i - 1]);
            j = j - weights[i - 1];
            i--;
        }
    }
}

int main()
{
    int n, capacity, i;

    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input for number of items.\n");
        return 1;
    }

    int profits[n], weights[n];

    printf("Enter the profits of the items:\n");

    for (i = 0; i < n; i++)
    {
        printf("Profit of item %d: ", i + 1);
        scanf("%d", &profits[i]);
    }

    printf("Enter the weights of the items:\n");

    for (i = 0; i < n; i++)
    {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(n, weights, profits, capacity);

    return 0;
}