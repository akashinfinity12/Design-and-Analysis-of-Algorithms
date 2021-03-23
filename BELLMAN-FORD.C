#include<stdio.h>
#include<conio.h>
#define MAX 30
#define INFINITY 9999
int bellmanford(int G[MAX][MAX],int n,int e,int E[MAX][2]);
void main()
{
	clrscr();
	int n,G[MAX][MAX],i,j,e=0,E[MAX][2];
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j]!=0)
			{
				E[e][0]=i;
				E[e][1]=j;
				e++;
			}
		}
	}
	if(bellmanford(G,n,e,E))
	{
		printf("\nNo negative cycles\n");
	}
	else
	{
		printf("Negative Cycle exists\n");
	}
	getch();
}

int bellmanford(int G[MAX][MAX],int n,int e,int E[MAX][2])
{
	int u,v,distance[MAX],parent[MAX],i,j,s,flag=1;
	for(i=0;i<n;++i)
	{
		distance[i]=INFINITY;
		parent[i]=-1;
	}
	printf("\nEnter the source vertex : ");
	scanf("%d",&s);
	distance[s-1]=0;
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<e;++j)
		{
			u=E[j][0];
			v=E[j][1];
			if(distance[u]+G[u][v]<distance[v])
			{
				distance[v]=distance[u]+G[u][v];
				parent[v]=u;
			}
		}
	}
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<e;++j)
		{
			u=E[j][0];
			v=E[j][1];
			if(distance[u]+G[u][v]<distance[v])
			{
				flag=0;
			}
		}
	}
	if(flag)
	{
		for(i=0;i<n;++i)
		{
			printf("\nVertex %d : Cost %d\n",i+1,distance[i]);
			if(parent[i]+1==0)
			{
				printf("Path : It is the source");
			}
			else
			{
				printf("Path : %d <- %d",i+1,parent[i]+1);
				j=parent[i]+1;
				if(i>0)
				{
					while(j!=1)
					{
						printf(" <- ");
						printf("%d",parent[j-1]+1);
						j=parent[j-1]+1;
					}
				}
			}
		}
		printf("\n");
	}
	return flag;
}