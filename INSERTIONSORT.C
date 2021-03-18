#include<stdio.h>
#include<conio.h>
void insertionSort(int a[], int size);
void printArray(int a[], int size);
void main()
{
	clrscr();
	int a[]={12,3,1,4,5};
	int size=sizeof(a)/sizeof(a[0]);
	insertionSort(a,size);
	printf("\nSorted array is");
	printArray(a,size);
	getch();
}

void insertionSort(int a[], int size)
{
	int swaps,comparison;
	for(int i=1;i<size;++i)
	{
		swaps=0;
		comparison=1;
		int key=a[i];
		int j=i-1;
		while(key<a[j] && j>=0)
		{
			a[j+1]=a[j];
			--j;
			swaps++;
			comparison++;
		}
		a[j+1]=key;
		printArray(a,size);
		printf("CC:%d\t",comparison);
		printf("SC:%d\t",swaps);
	}

}

void printArray(int a[], int size)
{
	printf("\n");
	for(int k=0;k<size;++k)
	{
		printf("%d\t",a[k]);
	}
}
