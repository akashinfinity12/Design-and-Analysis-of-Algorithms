#include<stdio.h>
#include<math.h>
#define MAX 30
int board[MAX],n,count=1;
int safe(int row, int column);
void nqueen(int row, int n);
void printresult(int n);
int main()
{
    int i,j;
    printf("\n--------- N QUEEN PROBLEM ---------\n");
    printf("Enter the number of queens to be placed : ");
    scanf("%d", &n);
    printf("%d X %d BOARD\n", n, n);
    if (n<4)
    {
        printf("No placements available");
    }
    else
    {
        nqueen(1,n);
    }
    return 0;
}

void nqueen(int row, int n)
{
    int i;
    for (i=1;i<=n;++i)
    {
        if (safe(row,i))
        {
            board[row] = i;
            if (row == n)
            {
                printresult(n);
            }
            else
            {
                nqueen(row+1,n);
            }
        }
    }
}

int safe(int row, int column)
{
    int i;
    for (i=1;i<=row-1;++i)
    {
        if (board[i] == column)
        {
            return 0;
        }
        else
        {
            if (abs(board[i]-column) == abs(i-row))
            {
                return 0;
            }
        }
    }
    return 1;
}

void printresult(int n)
{
    int i,j;
    printf("\nPlacement %d\n", count++);
    printf("----------------\n");
    for (i=1;i<=n;++i)
    {
        printf("\t%d", i);
    }
    for (i=1;i<=n;++i)
    {
        printf("\n\n%d", i);
        for (j=1;j<=n;++j)
        {
            if (board[i] == j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t-");
            }
        }
    }
    printf("\n");
}
