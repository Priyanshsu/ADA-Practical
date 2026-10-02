// Implementation of a knapsack problem using greedy algorithm

#include <stdio.h>

struct Item
{
    int id;
    int weight;
    int value;
    float ratio;
};

void main()
{
    int n, capacity;
    float totalValue = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter weight and value of each item:\n");

    for (int i = 0; i < n; i++)
    {
        item[i].id = i + 1;

        printf("Item %d weight: ", i + 1);
        scanf("%d", &item[i].weight);

        printf("Item %d value: ", i + 1);
        scanf("%d", &item[i].value);

        item[i].ratio = (float)item[i].value / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    printf("\nKC\t\tI\t\tW\t\tV\t\tF\n");
    printf("%d\t\t0\t\t0\t\t0\t\t0\n", capacity);

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (item[i].weight <= capacity)
        {
            capacity = capacity - item[i].weight;
            totalValue = totalValue + item[i].value;

            printf("%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n",
                   capacity,
                   item[i].id,
                   item[i].weight,
                   item[i].value,
                   1.0);
        }
        else
        {
            float fraction = (float)capacity / item[i].weight;
            float fractionValue = item[i].value * fraction;

            totalValue = totalValue + fractionValue;

            capacity = 0;

            printf("%d\t\t%d\t\t%d\t\t%.2f\t%.2f\n",
                   capacity,
                   item[i].id,
                   item[i].weight,
                   fractionValue,
                   fraction);
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalValue);
}