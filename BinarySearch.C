#include<stdio.h>
#include<conio.h>
int n=0,calls=0;
void binarySearch(int a[], int p, int r, int x);
void main()
{
	clrscr();
	int a[5];
	int x=0;
	printf("Enter five elements\n");
	for(int i=0;i<5;++i)
	{
		scanf("%d",&a[i]);
	}
	int size=5;
	printf("Element you want to search?\n");
	scanf("%d",&x);
	printf("Position is ");
	binarySearch(a,0,size-1,x);
	getch();
}

void binarySearch(int a[], int p, int r, int x)
{
	calls++;
	if(p<=r)
	{
		int mid=(p+r)/2;
		if(x==a[mid])
		{
			printf("%d\n",mid);
			printf("Number of calls : %d\n",calls);
		}
		else if(x>a[mid])
		{
			binarySearch(a,mid+1,r,x);
		}
		else if(x<a[mid])
		{
			binarySearch(a,p,mid-1,x);
		}
		else
		{
			printf("\nElement not found");
		}
	}
}
