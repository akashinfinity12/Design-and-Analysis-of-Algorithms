#include<stdio.h>
#include<conio.h>
#define MAX 30
#define INFINITY 9999
int G[MAX][MAX];
void floydwarshall(int n, int G[MAX][MAX]);
int minimum(int a, int b);
int main()
{
    int i,j,n;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the graph matrix\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            scanf("%d",&G[i][j]);
            if (i!=j && G[i][j]==0)
            {        
                G[i][j]=INFINITY;                
            }
            
        }
    }
    floydwarshall(n,G);
    return 0;
}

void floydwarshall(int n, int G[MAX][MAX])
{
    int i,j,k;
    for (k=0;k<n;++k)
    {
        for (i=0;i<n;++i)
        {
            for (j=0;j<n;++j)
            {
                G[i][j]=minimum(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
    printf("Final Graph will be\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}

int minimum(int a, int b)
{
    return (a<b?a:b);
}
