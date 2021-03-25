#include<stdio.h>
#include<conio.h>
#define MAX 30
int minimum(int a, int b);
int maximum(int a, int b);
void minmax(int x, int y);
int max,min,calls=0,a[MAX];
int main()
{
    int n,i;
    printf("Enter the number of elements in array : ");
    scanf("%d",&n);
    printf("\nEnter the elements in the array\n");
    for (i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    max=min=a[0];
    minmax(0,n-1);
    printf("\n--------------------\n");
    printf("Maximum element in the array : %d",max);
    printf("\nMinimum element in the array : %d",min);
    return 0;
}

void minmax(int x, int y)
{
    int mid,max1,min1;
    if (x==y)
    {
        max=min=a[x];
    }
    else if (x == y-1)
    {
        max=maximum(a[x],a[y]);
        min=minimum(a[x],a[y]);
    }
    else
    {
        mid = (x+y)/2;
        minmax(x,mid);
        max1=max;
        min1=min;
        minmax(mid+1,y);
        max=maximum(max,max1);
        min=minimum(min,min1);
    }
    printf("\n--------------------\n");
    printf("Pass %d\n",calls+1);
    calls++;
    printf("Maximum is %d\nMinimum is %d\n",max,min);
}

int maximum(int a, int b)
{
    return (a>b?a:b);
}

int minimum(int a, int b)
{
    return (a<b?a:b);
}
