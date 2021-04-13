#include<stdio.h>
#define MAX 30
void mergeSort(int low, int high);
void merge(int low, int mid, int high);
void printArray();
int a[MAX],b[MAX],n;
int main()
{
    int i;
    printf("\n------ MERGE SORT ------\n");
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i=0;i<n;++i)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(0,n-1);
    printf("\n");
    printf("\nSorted Array : ");
    for (i=0;i<n;++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int h,i,j,k;
    h = low, i = low, j = mid+1;
    while ((h <= mid) && (j <= high))
    {
        if (a[h] < a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (k=j;k<=high;++k)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k=h;k<=mid;++k)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (k=0;k<=high;++k)
    {
        a[k] = b[k];
    }
    printArray();
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
