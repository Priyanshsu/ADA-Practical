// Implementation of making a change problem using dynamic programming

#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void mcp()
{
    int n, t;

    printf("Making Change Problem\n");

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    int d[n];

    printf("Enter coin values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &t);

    int dp[n + 1][t + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {

            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 1)
            {
                dp[i][j] = dp[i][j - d[i - 1]] + 1;
            }
            else if (j < d[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(
                    dp[i - 1][j],
                    dp[i][j - d[i - 1]] + 1);
            }
        }
    }

    printf("\nDP Table:\n");

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    printf("\nMinimum number of coins required : %d", dp[n][t]);
    printf("\nCoins required: ");
    int i = n, j = t;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            printf("%d\t", d[i - 1]);
            j = j - d[i - 1];
        }
    }
}

int main()
{
    mcp();
    return 0;
}