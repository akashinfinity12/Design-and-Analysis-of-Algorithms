#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int g[MAX][MAX],int n,int start);
void main()
{
	clrscr();
	int n,start,g[MAX][MAX];
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix\n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("\nEnter the source node\n");
	scanf("%d",&start);
	dijkstra(g,n,start);
	getch();
}

void dijkstra(int g[MAX][MAX],int n,int start)
{
	int distance[MAX],cost[MAX][MAX],visited[MAX],pred[MAX];
	int count,mindistance,nextnode,j;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(g[i][j]!=0)
			{
				cost[i][j]=g[i][j];
			}
			else
			{
				cost[i][j]=INFINITY;
			}
		}
	}
	for(i=0;i<n;++i)
	{
			distance[i]=cost[start][i];
			pred[i]=start;
			visited[i]=0;
	}
	visited[start]=1;
	distance[start]=0;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;++i)
		{
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;
		for(i=0;i<n;++i)
		{
			if(!visited[i])
			{
				if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
	for(i=0;i<n;++i)
	{
		if(i!=start)
		{
			printf("\nDistance of node %d : %d\n",i,distance[i]);
			printf("Path : %d",i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <- %d",j);
			}while(j!=start);
		}
	}
}