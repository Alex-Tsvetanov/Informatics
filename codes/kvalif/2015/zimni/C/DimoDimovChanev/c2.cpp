#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a [128][128];
long long b [128][128];
vector<long long> sums;

int main()
{
    long long na = 0, nb = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin>>n>>m;
    for(long long i = 0; i<n; i++)
    {
        for(long long j = 0; j<m; j++)
        {
            cin>>a[j][i];
        }
    }
    sums.reserve(m+n+1);
    for(long long i = 0; i < m; i++)
    {
        long long asd = 0;
        for(long long j = 0; j<n; j++)
        {
            asd+=a[i][j];
        }
        sums.push_back(asd);
    }
    for(long long i = 0; i < n; i++)
    {
        long long asd = 0;
        for(long long j = 0; j<m; j++)
        {
            asd+=a[j][i];
        }
        sums.push_back(asd);
    }
    sort(begin(sums), end(sums));
    long long k = 0;
    while(sums[k]==0)
    {
        k++;
    }
    if(k!=sums.size())
        swap(sums[0], sums[k]);
    for(long long i = sums[0]; i>0; i--)
    {
        bool as = true;
        for(auto &x:sums)
        {
            if(x%i!=0)
            {
                as = false;
                break;
            }
        }
        if(as)
        {
            na=i;
            break;
        }
    }
    cin>>n>>m;
    for(long long i = 0; i<n; i++)
    {
        for(long long j = 0; j<m; j++)
        {
            cin>>b[j][i];
        }
    }
    sums.clear();
    sums.reserve(m+n+1);
    for(long long i = 0; i < m; i++)
    {
        long long asd = 0;
        for(long long j = 0; j<n; j++)
        {
            asd+=b[i][j];
        }
        sums.push_back(asd);
    }
    for(long long i = 0; i < n; i++)
    {
        long long asd = 0;
        for(long long j = 0; j<m; j++)
        {
            asd+=b[j][i];
        }
        sums.push_back(asd);
    }
    sort(begin(sums), end(sums));
    k = 0;
    while(sums[k]==0)
    {
        k++;
    }
    if(k!=sums.size())
        swap(sums[0], sums[k]);
    for(long long i = sums[0]; i>0; i--)
    {
        bool as = true;
        for(auto &x:sums)
        {
            if(x%i!=0)
            {
                as = false;
                break;
            }
        }
        if(as)
        {
            nb=i;
            break;
        }
    }
    cout<< na << " " <<nb;
    if(na%nb==0 || nb%na==0)
    {
        cout<<"\nY\n";
    }
    else
    {
        cout<<"\nN\n";
    }
    return 0;
}
