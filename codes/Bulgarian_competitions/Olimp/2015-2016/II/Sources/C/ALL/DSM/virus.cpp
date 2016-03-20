#include<iostream>
#include<algorithm>
using namespace std;
long long f(long long a)
{
    long long answ = a - 1, ways = 0, globalWays = 0, i;
    for(i=1; i<=answ; i++)
    {
        ways = ways + i;
    }
    globalWays = ways;
    for(ways = ways - answ; ways > 0; ways = ways - answ)
    {
        globalWays = globalWays + ways;
    }
    return globalWays + a;
}
long long arr[501][501],arrSize[501];
int main ()
{
    long long n,answ,ways=0,i,j,k;
    cin>>n;
    for(i = 1; i < n; i++)
    {
        if(f(i)>=n)
        {
            ways = i;
            break;
        }
    }
    cout<<ways<<endl;
    long long num = 1;
    if(n<=500)
    {
        for(i = 1; i <= ways; i++)
        {
            arr[arrSize[i]][i] = num;
            arrSize[i]++;
            num++;
        }
        long long cages[100], k=2,i = 2;
            for(long long m = 1; m <= i; m++)
            {
                cages[m] = m;
            }
            while(num-1<n)
            {
                for(long long m = 1; m <= i; m++)
                {
                    arr[arrSize[cages[m]]][cages[m]] = num;
                    arrSize[cages[m]]++;
                }
                num++;
                cages[i]++;
                if(cages[i] > ways)
                {
                    long long p = i;
                    while(cages[p] > ways - (i - p))
                    {
                        p--;
                    }
                    cages[p]++;
                    for(long long m = p+1; m <= i; m++)
                    {
                        cages[m] = cages[m-1] + 1;
                    }
                }
            }

        for(i = 1; i <= ways; i++)
        {
            cout<< arrSize[i]<<" ";
            for(j = 0; j < arrSize[i]; j++)
            {
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
