#include<stdio.h>
#include<conio.h>
void knapsack(int n, float weight[10], float profit[10],float capacity);
void main()
{
	clrscr();
	float ratio[10],profit[10],weight[10],temp,capacity;
	int i,j,n;
	printf("Enter capacity of knapsack\n");
	scanf("%f",&capacity);
	printf("Enter the number of items\n");
	scanf("%d",&n);
	printf("Enter the profits and weights of all items\n");
	for(i=0;i<n;++i)
	{
		scanf("%f %f",&profit[i],&weight[i]);
		ratio[i]=profit[i]/weight[i];
		printf("Ratio (P/W) : %f\n",ratio[i]);
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(ratio[i]>ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;

				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;

				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
		}
	}
	knapsack(n,weight,profit,capacity);
	getch();
}

void knapsack(int n,float weight[10],float profit[10],float capacity)
{
	float u=capacity;
	float x[10],tp=0;
	for(int i=0;i<n;++i)
	{
		x[i]=0.0;
	}
	for(i=0;i<n;++i)
	{
		if(weight[i]>capacity)
		{
			break;
		}
		else
		{
			x[i]=1.0;
			tp+=profit[i];
			capacity-=weight[i];
		}
	}
	if(i<n)
	{
		x[i]=capacity/weight[i];
	}
	tp+=(x[i]*profit[i]);
	printf("The selected items are\n");
	for(i=0;i<n;++i)
	{
		if(x[i]==1.0)
		{
			printf("Profit is %.2f with weight %.2f\n",profit[i],weight[i]);
		}
		else if(x[i]>0.0)
		{
			printf("%.2f part of profit %f with weight %.2f\n",x[i],profit[i],weight[i]);
		}
	}
	printf("Total Profit for %d items with %.2f capacity is %.2f\n",n,u,tp);
}
