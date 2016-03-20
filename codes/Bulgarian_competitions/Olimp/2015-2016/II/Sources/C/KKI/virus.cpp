#include<iostream>
#include<vector>
using namespace std;
long long oi[1000];
long long br=0;
long long n;
long long otg;
vector<long long> v[600];
int findo(long long a,long long l)
{
    if(otg==n)return 0;
    if(a==0)
    {
        v[l].push_back(otg);
        otg++;
        return 0;
    }
    for(long long i=l; l<=br; l++)
    {
        for(long long j=l+1; j<br; j++)
        {
            v[i].push_back(otg);
            findo(a-1,j);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    long long ans=0;
    oi[0]=1;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    while(ans<n)
    {
        br++;
        ans=0;
        for(long long i=br+1; i>0; i--)
        {
            oi[i]=oi[i-1]+oi[i];
            ans+=oi[i];
        }
        ans++;
    }
    n--;
    cout<<br<<endl;
    if(n>500)return 0;
    long long br1=0;
    for(long long i=0; i<br; i++)
    {
        v[i].push_back(otg);
        if(otg==n)break;
        otg++;
    }
    long long otg1=otg;
    long long p=0;
    while(otg<n)
    {
        br1++;
        findo(br1, 0);
        if(otg==n)
        {
            for(long long i=0; i<br; i++)
            {
                p=0;
                for(long long j=0; j<v[i].size(); j++)
                {
                    if(v[i][j]<n) p++;
                }
                cout<<p<<" ";
                for(long long j=0; j<v[i].size(); j++)
                {
                    if(v[i][j]<n) cout<<v[i][j]+1<<" ";
                }
                cout<<endl;
            }
            return 0;
        }
    }
}
