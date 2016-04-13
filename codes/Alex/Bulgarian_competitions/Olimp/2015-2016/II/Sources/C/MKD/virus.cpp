#include<iostream>
#include<vector>
using namespace std;
bool l[40];
void inc()
{
    for(int i=0;true;i++)
    {
        if(l[i])
        {
            l[i]=false;
        }
        else
        {
            l[i]=true;
            return;
        }
    }
}
int log(long long n)
{
    long long p=2;
    int q=1;
    while(p<n)
    {
        p*=2;
        q++;
    }
    return q;
}
int main()
{
    int n;
    cin>>n;
    int k=log(n);
    cout<<k<<"\n";
    if(n>500) return 0;
    vector <int> v[k+1];
    for(int i=1;i<=n;i++)
    {
        inc();
        for(int j=0;j<k;j++)
        {
            if(l[j])
            {
                v[j+1].push_back(i);
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        cout<<v[i].size()<<" ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
