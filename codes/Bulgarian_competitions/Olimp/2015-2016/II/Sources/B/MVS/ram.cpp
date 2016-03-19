#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct table
{
    long M, N;
    table(long m, long n)
    {
        M = m;
        N = n;
    }
};

bool comp(table a, table b)
{
    return a.M<a.N;
}

vector <table> ans;

long K;

int main()
{
    cin>>K;
    long m, n, curr;
    for(n = 1; n+2<=K; n++)
    {
        for(m = n; 1; m++)
        {
            curr = 2*m*n + m - n + 1;
            if(curr==K)
            {
                ans.push_back(table(m, n));
            }
            if(curr>K)
                break;
        }
    }
    for(m = 1; m+1<=K; m++)
    {
        for(n = m+1; 1; n++)
        {
            curr = 2*m*n-m+n;
            if(curr==K)
                ans.push_back(table(m,n));
            if(curr>K)
                break;
        }
    }
    sort(ans.begin(), ans.end(), comp);
    long size = ans.size();
    cout<<size;
    for(int i = 0; i<size; i++)
    {
        cout<<endl<<ans[i].M<<" "<<ans[i].N;
    }
    return 0;
}
