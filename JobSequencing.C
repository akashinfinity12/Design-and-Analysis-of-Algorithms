#include<stdio.h>
#include<conio.h>
int maximum(int n);
int JobSequencing(int n);
int pass=1;
int i,j;
struct Job
{
    int id;
    int profit;
    int deadline;
}J[20],JS[20];

int main()
{
    int n,temp;
    printf("Enter the number of jobs\n");
    scanf("%d",&n);
    printf("Enter the profits and deadlines for each job\n");
    for (i=0;i<n;++i)
    {
        printf("Job %d : ",i+1);
        J[i].id=i+1;
        scanf("%d %d", &J[i].profit,&J[i].deadline);
    }
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            if (J[i].profit>J[j].profit)
            {
                temp=J[j].profit;
                J[j].profit=J[i].profit;
                J[i].profit=temp;

                temp=J[j].deadline;
                J[j].deadline=J[i].deadline;
                J[i].deadline=temp;

                temp=J[j].id;
                J[j].id=J[i].id;
                J[i].id=temp;
            }
            
        }
    }
    int m = JobSequencing(n);
    return 0;
}

int maximum(int n)
{
    int max=J[0].deadline;
    for (i=0;i<n;++i)
    {
        if (J[i].deadline>max)
        {
            max=J[i].deadline;
        }
        
    }
    return max;
}

int JobSequencing(int n)
{
    int slot[20],maxprofit=0,k=0,t;
    int deadlinemax=maximum(n);
    printf("\nJob\tProfit\tDeadline\n");
    for (i=0;i<n;++i)
    {
        printf("%d\t%d\t%d\n",J[i].id,J[i].profit,J[i].deadline);
    }
    printf("Maximum Deadline : %d\n",deadlinemax);
    for (i=0;i<n;++i)
    {
        slot[i]=-1;
    }
    for (j=0;j<n;++j)
    {
        t=J[j].deadline;
        t--;
        while (t>=0)
        {
            if (slot[t]==-1)
            {
                slot[t]=J[j].id;
                JS[k]=J[j];
                k++;
                maxprofit+=J[j].profit;
                break;
            }
            else
            {
                t--;
            }                                            
        }
        printf("\n----------------\n");
        printf("Pass %d\n",pass);
        printf("Job\tProfit\tDeadline\n");
        for (i=0;i<=j;++i)
        {
            printf("%d\t%d\t%d\n",JS[i].id,JS[i].profit,JS[i].deadline);
        }
        printf("\nTime array : ");
        for (i=0;i<deadlinemax;++i)
        {
            printf("%d ",slot[i]);
        }
        printf("\nCurrent Max Profit : %d",maxprofit);
        pass++;
    }
    return maxprofit;
}