// Implement the LCS problem.

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void lcs(char str1[], char str2[])
{
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];

    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("\n--- DP Table ---\n");
    printf("    ");

    for (j = 0; j < n; j++)
    {
        printf("%4c", str2[j]);
    }

    printf("\n");

    for (i = 0; i <= m; i++)
    {
        if (i == 0)
            printf("  ");
        else
            printf("%c ", str1[i - 1]);

        for (j = 0; j <= n; j++)
        {
            printf("%4d", dp[i][j]);
        }

        printf("\n");
    }

    int length = dp[m][n];
    char lcsString[length + 1];

    lcsString[length] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcsString[length - 1] = str1[i - 1];
            i--;
            j--;
            length--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("\nLength of LCS: %d\n", dp[m][n]);
    printf("LCS String: %s\n", lcsString);
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    lcs(str1, str2);

    return 0;
}