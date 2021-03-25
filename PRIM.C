#include<stdio.h>
#include<conio.h>
#define MAX 30
#define INFINITY 999
int G[MAX][MAX],visited[MAX],a,b,u,v,n,count=1;
int mindistance,mincost=0;
void main()
{
	clrscr();
	int i,j;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the graph matrix\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j]==0)
			{
				G[i][j]=INFINITY;
			}
		}
	}
	printf("\nThe edges of minimum spanning tree are\n");
	visited[1]=1;
	while(count<n)
	{
		mindistance=INFINITY;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(visited[i]==1 && G[i][j]<mindistance)
				{
					mindistance=G[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		if(visited[u]==0 || visited[v]==0)
		{
			visited[v]=1;
			mincost+=mindistance;
			printf("%d edge (%d,%d) = %d\n",count++,a,b,mindistance);
		}
		G[a][b]=G[b][a]=INFINITY;
	}
	printf("\nMinimum cost : %d",mincost);
	getch();
}
