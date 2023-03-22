#include <stdio.h>
#include <limits.h>

#define V 7

struct dijkstra
{
    int visited;
    int p;
    int dist;
} graph[V];

void init()
{
    for (int i = 0; i < V; i++)
    {
        graph[i].dist = INT_MAX;
        graph[i].p = -1;
        graph[i].visited = 0;
    }
    graph[0].dist = 0;
}
int findMin()
{
    int min = INT_MAX;
    int i = 0, k;
    for (i = 0; i < V; i++)
    {
        if (graph[i].visited == 0)
        {
            if (min > graph[i].dist)
            {
                min = graph[i].dist;
                k = i;
            }
        }
    }
    return k;
}
void relax(int u, int v, int w)
{
    if (graph[v].dist > (graph[u].dist + w))
    {
        graph[v].dist = graph[u].dist + w;
        graph[v].p = u;
    }
}
void findpath(int d)
{
    int k = d;
    printf("\nThe path in reverse order:");
    while (graph[k].p != -1)
    {
        printf("-> %d", graph[k].p);
        k = graph[k].p;
    }
}
void dijkstraFun(int G[V][V], int s, int n)
{
    init();
    int i = 0;
    while (i <= V)
    {
        int k = findMin();
        graph[k].visited = 1;
        for (int j = 0; j < V; j++)
        {
            if (G[k][j] != 0)
            {
                relax(k, j, G[k][j]);
            }
        }
        i++;
    }
}
int main()
{
    // Initialize graph
    int G[V][V] = {
        {0, 4, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 12, 5, 0},
        {3, 0, 0, 7, 10, 0, 0},
        {0, 0, 7, 0, 2, 0, 0},
        {0, 12, 10, 2, 0, 0},
        {0, 5, 0, 0, 0, 0, 16},
        {0, 0, 0, 0, 5, 16, 0}};
    dijkstraFun(G, 0, V);
    printf("The values of distance and parent are:\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d->%d\n", graph[i].dist, graph[i].p);
    }
}