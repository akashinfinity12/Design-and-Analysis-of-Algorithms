#include<stdio.h>
#include<conio.h>
#define MAX 30
#define INFINITY 999
int G[MAX][MAX],parent[MAX];
int a,b,u,v,n,count=1,mindistance,mincost=0;
int find(int i);
int unio(int i, int j);
void main()
{
	clrscr();
	int i,j;
	printf("Enter number of vertices : ");
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
	printf("\nThe edges of minimum cost spanning tree are\n");
	while(count<n)
	{
		mindistance=INFINITY;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(G[i][j]<mindistance)
				{
					mindistance=G[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(unio(u,v))
		{
			printf("%d edge (%d,%d) = %d\n",count++,a,b,mindistance);
			mincost+=mindistance;
		}
		G[a][b]=G[b][a]=INFINITY;
	}
	printf("\nMinimum cost = %d\n",mincost);
	getch();
}

int find(int i)
{
	while(parent[i])
	{
		i=parent[i];
	}
	return i;
}

int unio(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
