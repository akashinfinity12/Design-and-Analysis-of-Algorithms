#include<stdio.h>
#include<conio.h>
int max,min,calls=0;
int a[50];

void max_min(int i,int j)
{
    int mid,max1,min1;
    if(i==j)
    {
        max=min=a[i];
    }
    else 
    {
        if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];
        }
    }
        else
        {
            mid=(i+j)/2;
            max_min(i,mid);
            max1 = max; 
            min1 = min;
            max_min(mid+1,j);
            if(max<max1)
                max=max1;
                
            if(min>min1)
                min=min1;
                
    }
}
calls++;
printf("\nPASS\n");
printf("MAX=%d MIN=%d\n",max,min);
}


void main()
{
    clrscr();
    int n,i;
    printf("ENTER THE SIZE OF THE ARRAY\n");
    scanf("%d",&n);
    printf("\nENTER THE ELEMENTS OF THE ARRAY\n");
    for(i=1;i<=n;i++)
    {
        scanf("\n%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    max_min(1,n);
    printf ("\nMinimum : %d\n", min);
    printf ("Maximum : %d\n", max);
    printf ("Calls : %d\n", calls);
    getch();
}