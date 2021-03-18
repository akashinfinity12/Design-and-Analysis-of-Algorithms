#include<stdio.h>
#include<conio.h>
void selectionSort(int a[], int size);
void swap(int *x, int *y);
void printArray(int a[], int size);
void main()
{
	clrscr();
	int a[] = {12,3,4,15,2,1};
	int size = sizeof(a)/sizeof(a[0]);
	selectionSort(a,size);
	printf("\nSorted Array is");
	printArray(a,size);
	getch();
}

void selectionSort(int a[], int size)
{
	for(int i=0;i<size-1;++i)
	{
		int swapcount=0;
		int compcount=0;
		int minimum=i;
		for(int j=i+1;j<size;++j)
		{
			if(a[j]<a[minimum])
			{
				minimum=j;
			}
			compcount++;
		}
		swap(&a[minimum],&a[i]);
		swapcount++;
		printArray(a,size);
		printf("CC:%d\tSC:%d",compcount,swapcount);
	}
}

void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void printArray(int a[], int size)
{
	printf("\n");
	for(int k=0;k<size;++k)
	{
		printf("%d\t",a[k]);
	}
}
