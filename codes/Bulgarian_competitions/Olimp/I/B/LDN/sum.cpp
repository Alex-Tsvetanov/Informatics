#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n, solution=0;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }

    int summax[n];
    int summin[n];
    for(int i=0;i<=n;i++)
    {
        summax[i]=0;
        summin[i]=0;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(summax[j]==summax[j+1])
            {
                summax[j]++;
                summax[j+1]=0;
                break;
            }
        }
        for(int j=n-i;j>=0;j--)
        {
            if(summin[j]==summin[j-1])
            {
                summin[j]++;
                summin[j-1]=0;
                sort(summin+0, summin+n);
                reverse(summin, summin+n);
                break;
            }
        }
        bool breaker=false;
        for(int k=0;k<n-i;k++)
        {
            if(summax[k]!=summin[k])
            {
                breaker=true;
                break;
            }
        }
        if(breaker)
        {
            solution+=2;
        }else
        {
            solution++;
        }
    }
    for(int i=0;i<12;i++)
    {
        if(pow(2, i)==n)
        {
            solution++;
        }
    }
    cout<<solution<<endl;
}
