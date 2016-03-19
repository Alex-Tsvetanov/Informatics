#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin>>k;
    long long n;
    queue<long long> s[2];
    long long br=0;
    for(long long m=1;m<=k+2;m++)
    {
        if(2*m*m+1<k)
        {
            if((k+m)%(2*m+1)==0){n=(k+m)/(2*m+1);if(n>0){br++;s[0].push(m);s[1].push(n);}}
        }
        else
           if((k-m-1)%(2*m-1)==0){n=(k-m-1)/(2*m-1);if(n>0){br++;s[0].push(m);s[1].push(n);}}
           //cout<<m<<" "<<2*m*m-(2*m-1)<<endl;
    }
    cout<<br<<endl;
    while(!s[1].empty())
    {
        cout<<s[0].front()<<" "<<s[1].front()<<endl;
        s[0].pop();
        s[1].pop();
    }
    return 0;
}
