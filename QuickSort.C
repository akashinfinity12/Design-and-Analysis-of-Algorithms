#include<stdio.h>
#define MAX 30
#define INFINITY 999
int a[MAX],n;
int partition(int m, int p);
void QuickSort(int p, int q);
void interChange(int x, int y);
void printArray();
int main()
{
    int i;
    printf("\n------ QUICK SORT ------\n");
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i=0;i<n;++i)
    {
        scanf("%d", &a[i]);
    }
    a[n] = INFINITY;
    QuickSort(0,n-1);
    printf("\n");
    printf("\nSorted Array : ");
    for (i=0;i<n;++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void QuickSort(int p, int q)
{
    int j;
    if (p < q)
    {
        j = partition(p,q+1);
        QuickSort(p, j-1);
        QuickSort(j+1, q);
    }
}

int partition(int m, int p)
{
    int pivot,i,j;
    pivot = a[m], i=m, j=p;
    do
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            interChange(i,j);
        }
    }while (i < j);
    a[m] = a[j];
    a[j] = pivot;
    printArray();
    return j;
}

void interChange(int x, int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void printArray()
{
    int i;
    printf("\nPASS\n");
    for (i=0;i<n;++i)
    {
        printf("%d ", a[i]);
    }
}
