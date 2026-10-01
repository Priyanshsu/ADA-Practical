// Implementation of chain matrix multiplication using dynamic programming.

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 999999

int main()
{
    int n;
    int p[MAX];
    int m[MAX][MAX];
    int i, j, k, L, q;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions (P[0] to P[%d]):\n", n);

    for (i = 0; i <= n; i++)
    {
        printf("P[%d]: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INF;

            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("\nMatrix Chain Multiplication Cost Table:\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j < i)
            {
                printf("%-10s", "INF");
            }
            else
            {
                printf("%-10d", m[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nMinimum scalar multiplication required m[1][%d]: %d\n",
           n, m[1][n]);

    return 0;
}