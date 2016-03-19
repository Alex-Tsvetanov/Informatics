#include<iostream>
#include<vector>
using namespace std;
long long oi[1000];
long long br=0;
long long n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long a,b,c;
    cin>>a>>b>>c;
    long long ans=0;
     while(ans<=n)
    {
        br++;
        ans=0;
        for(long long i=br+1; i>0; i--)
        {
            oi[i]=oi[i-1]+oi[i];
            ans+=oi[i];
        }
    }
    cout<<ans<<endl;
}
