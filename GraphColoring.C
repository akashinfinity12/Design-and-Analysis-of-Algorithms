#include<stdio.h>
#define MAX 10
int color[MAX],G[MAX][MAX],x[MAX],n,m=0,flag=0,count=1;
int colorsused[MAX],y=0;
void mColoring(int k);
int nextValue(int k);
void printSolution();
int main()
{
    int i,j;
    printf("\n------ GRAPH COLORING ------\n");
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            scanf("%d", &G[i][j]);
        }
    }
    printf("\nSolution:\n");
    for (m=0;m<n;++m)
    {
        if (y == 1)
        {
            break;
        }
        mColoring(0);
    }
    printf("\nChromatic number : %d", m-1);
    if (!flag)
    {
        printf("Solution does not exists");
    }
    return 0;
}

void mColoring(int k)
{
    do
    {
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n-1)
        {
            y=1;
            printSolution();
        }
        else
        {
            mColoring(k+1);
        }
    }while(true);
}

int nextValue(int k)
{
    int j;
    do
    {
        x[k] = (x[k] + 1) % (m+1);
        if (x[k] == 0)
        {
            return 0;
        }
        for (j=0;j<n;++j)
        {
            if (G[k][j] != 0 && x[j] == x[k])
            {
                break;
            }
        }
        if (j==n)
        {
            return 1;
        }
    }while(true);
}

void printSolution()
{
    flag=1;
    int i;
    printf("Solution %d : [ ", count++);
    for (i=0;i<n;++i)
    {
        printf("%d ", x[i]);
    }
    printf("]\n");
}
