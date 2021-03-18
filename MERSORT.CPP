#include<stdio.h>
#include<conio.h>
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d \t", A[i]);
	printf("\n");
	printf("\n");
}
int call = 0, n;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int n = r-l;
	int a[3], b[2];
	for (i = 0; i < n1; i++)
		a[i] = arr[l + i];
	for (j = 0; j < n2; j++)
	b[j] = arr[m + 1 + j];
	printf("\n");
	printf("Subarray 1: ");
	printArray(a,n1);
	printf("Subarray 2: ");
	printArray(b,n2);
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
	k++;
	}

	while (i < n1)
	{
		arr[k] = a[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void main()
{
	clrscr();
	int arr[100],i;
	int arr_size=5;
	printf("Enter five elements: ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Given array is \n");
	printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	getch();
}