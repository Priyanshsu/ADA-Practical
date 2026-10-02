// Implement kruskal’s algorithm

#include <stdio.h>
struct Edge
{
    int u, v, w;
};
int parent[5];
int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}
void unionSet(int a, int b)
{
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}
int main()
{
    int V = 5;
    int E = 7;
    struct Edge edges[7] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};
    struct Edge temp;
    int i, j;
    int count = 0;
    int totalCost = 0;
    /* Initialize parent */
    for (i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    /* Sort edges by weight */
    for (i = 0; i < E - 1; i++)
    {
        for (j = i + 1; j < E; j++)
        {
            if (edges[i].w > edges[j].w)
            {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    printf("Edges in Minimum Spanning Tree:\n");
    /* Kruskal's Algorithm */
    for (i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v))
        {
            printf("%d - %d = %d\n", u, v, edges[i].w);
            totalCost = totalCost + edges[i].w;
            unionSet(u, v);
            count++;
        }
    }
    printf("\nMinimum Cost = %d\n", totalCost);
    return 0;
}