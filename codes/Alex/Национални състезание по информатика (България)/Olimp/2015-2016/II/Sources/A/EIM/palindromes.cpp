#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool IsPali[10111][10111];
int n;
char inp[10111];
int F[10111];

inline int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    int i,j;
    int ans;

    scanf("%s",inp+1);
    n=strlen(inp+1);

    for (i=1;i<=n;i++)
    {
        IsPali[i][i]=true;
        IsPali[i+1][i]=true;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j+i<=n;j++)
        {
            IsPali[j][j+i]=(IsPali[j+1][j+i-1])&&(inp[j]==inp[j+i]);
        }
    }

    F[0]=0;

    for (i=1;i<=n;i++)
    {
        ans=999999999;
        for (j=i;j>=1;j--)
        {
            if (IsPali[j][i])
            {
                ans=MIN(ans,F[j-1]+1);
            }
        }
        F[i]=ans;
    }

    printf("%d\n",F[n]-1);

    return 0;
}
