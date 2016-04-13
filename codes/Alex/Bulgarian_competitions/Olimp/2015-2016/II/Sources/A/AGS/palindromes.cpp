#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_S 10024

int solve(char *str)
{
    int n=strlen(str),A[n];
    bool f[n][n];
    int i,j,k,t;
    memset(f,1,sizeof(f));
    for(t=2;t<=n;t++)
    {
        for(i=0;i<n-t+1;i++)
        {
            j=i+t-1;
            if(t==2)f[i][j]=(str[i]==str[j]);
            else f[i][j]=(str[i]==str[j])&&f[i+1][j-1];
        }
    }
    for(i=0;i<n;i++)
    {
        if(f[0][i]==1)A[i]=0;
        else
        {
            A[i]=INT_MAX;
            for(j=0;j<i;j++)
            {
                if(f[j+1][i]==1&&1+A[j]<A[i])A[i]=1+A[j];
            }
        }
    }
    return A[n-1];
}

int main()
{
    char str[MAX_S];
    scanf("%s", str);
    printf("%d\n", solve(str));
    return 0;
}
