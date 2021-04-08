#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
int x[MAX][MAX], y[MAX][MAX];
char a[MAX], b[MAX];
void longestcomseq(int len1, int len2);
void printseq(int i, int j);
int main()
{
    int alen, blen;
    int i;
    printf("\nEnter first string : ");
    scanf("%s", a);
    printf("Enter second string : ");
    scanf("%s", b);
    alen = strlen(a);
    blen = strlen(b);
    longestcomseq(alen, blen);
    return 0;
}

void longestcomseq(int len1, int len2)
{
    int i,j;
    for (i=0;i<=len1;++i)
    {
        x[i][0] = 0;
    }
    for (i=0;i<=len2;++i)
    {
        x[0][i] = 0;
    }
    for (i=1;i<=len1;++i)
    {
        for (j=1;j<=len2;++j)
        {
            if (a[i-1] == b[j-1])
            {
                x[i][j] = x[i-1][j-1] + 1;
                y[i][j] = 'D';
            }
            else if (x[i-1][j] > x[i][j-1])
            {
                x[i][j] = x[i-1][j];
                y[i][j] = 'U';
            }
            else
            {
                x[i][j] = x[i][j-1];
                y[i][j] = 'L';
            }
        }
    }
    printf("\nTable\n");
    for (i=1;i<=len1;++i)
    {
        for (j=1;j<=len2;++j)
        {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
    printf("\nThe longest common subsequence : ");
    printseq(len1, len2);
}

void printseq(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    else if (y[i][j] == 'D')
    {
        printseq(i-1, j-1);
        printf("%c", a[i-1]);
    }
    else if (y[i][j] == 'U')
    {
        printseq(i-1,j);
    }
    else
    {
        printseq(i,j-1);
    }
}
