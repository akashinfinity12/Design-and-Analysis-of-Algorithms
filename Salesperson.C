#include<stdio.h>
#include<conio.h>
#define MAX 30
#define INFINITY 9999
int G[MAX][MAX], cost=0, n, visited[MAX];
void shortestpath(int source);
int findnearest(int current);
int main()
{
    int i,j;
    printf("\nEnter number of cities : ");
    scanf("%d", &n);
    printf("\nEnter the distances in graph matrix\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            scanf("%d", &G[i][j]);
        }
        visited[i]=0;
    }
    printf("\nShortest path for salesperson : ");
    shortestpath(0);
    printf("\nMinimum cost : %d", cost);
    return 0;
}

void shortestpath(int source)
{
    int nearest_city;
    visited[source]=1;
    printf("%d -> ", source+1);
    nearest_city = findnearest(source);
    if (nearest_city == INFINITY)
    {
        nearest_city = 0;
        printf("%d", nearest_city+1);
        cost += G[source][nearest_city];
        return;
    }
    shortestpath(nearest_city);
}

int findnearest(int current)
{
    int i, temp, minimum=INFINITY, nearest=INFINITY;
    for (i=0;i<n;++i)
    {
        if (visited[i] == 0 && G[current][i] != 0)
        {
            if (G[current][i] < minimum)
            {
                minimum = G[0][current] + G[current][i];
                temp = G[current][i];
                nearest = i;
            }
        }
    }
    if (minimum != INFINITY)
    {
        cost += temp;
    }
    return nearest;
}
