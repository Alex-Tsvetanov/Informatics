#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> >s;
long long k,k1;
int main()
{
    cin>>k;
    k1=k-1;
    for(int i=1;i<=100000;i++)
    {
        long long m,n,now;
        m=i;
        //1
        n=(k+m)/(2*m+1);
        now=2*m*n-m+n;
        if(now==k && m<n && n!=0)
            s.insert(make_pair(m,n));
        //2
        n=(k1+m)/(2*m+1);
        now=2*m*n-m+n+1;
        if(now==k && m==n)
            s.insert(make_pair(m,n));
        //3
        n=(k1-m)/(2*m-1);
        now=2*m*n+m-n+1;
        if(now==k && m>n && n!=0)
            s.insert(make_pair(m,n));

        //1
        n=i;
        m=(k-n)/(2*n-1);
        now=2*m*n-m+n;
        if(now==k && m<n && m!=0)
            s.insert(make_pair(m,n));
        //2
        m=(k1-n)/(2*n-1);
        now=2*m*n-m+n+1;
        if(now==k && m==n)
            s.insert(make_pair(m,n));
        //3
        m=(k1+n)/(2*n+1);
        now=2*m*n+m-n+1;
        if(now==k && m>n && m!=0)
            s.insert(make_pair(m,n));
    }
    cout<<s.size()<<endl;
    for(set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++)
    {
        pair<int,int>now=*it;
        cout<<now.first<<" "<<now.second<<endl;
    }
    return 0;
}
