#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> chis;
vector<int> asd = {0, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    int p, n, s;
    cin>>p>>n>>s;
    chis.resize(n);
    for(int i = 0; i<n; i++)
    {
        chis[i]=0;
    }
    int res = 0;
    while(true)
    {
        int sum = 0;
        for(auto &x: chis)
        {
            sum+=x;
        }
        if(sum<s)
        {
            res++;
        }
        chis[n-1]++;
        for(int i = n-1; i>=0; i--)
        {
            if(chis[i]>=p)
            {
                if(i==0)
                {
                    goto GO;
                }
                chis[i-1]++;
                chis[i]-=p;
            }
        }
    }
GO:
    cout<<res<<endl;
    return 0;
}
