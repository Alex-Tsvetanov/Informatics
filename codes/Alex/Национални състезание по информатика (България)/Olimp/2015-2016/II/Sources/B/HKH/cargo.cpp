#include<iostream>
#include<algorithm>
using namespace std;
struct time
{
    int x,y;
};
time b[1048576];
bool cmp(time n,time m)
{
    if(m.x>n.x) return 1;
    if(m.y>n.y) return 1;
    if(n.x>m.x) return 0;
    else return 0;
}
int main()
{
    long long n,a,pilot;
    cin>>n>>a>>pilot;
    for(long long i=0; i<a; i++)
    {
        cin>>b[i].x>>b[i].y;
    }
    sort(b,b+a,cmp);
    long long ind=0,f=0;
    for(long long i=b[0].x; i<n; i++)
    {
        if(i==6) i+=2;
        for(long long j=0; j<pilot/2; j++)
        {
            if( b[ind].y<i)
            {
                f++;
                break;
            }
            if(b[ind].x<=i) ind++;
            if(ind==a)
            {
                cout<<"OK"<<endl;
                return 0;
            }
        }
        if(f>0) break;
    }
    if(f==0)
    {
        cout<<"OK"<<endl;
        return 0;
    }
    f=0;
    ind=0;
    for(long long i=b[0].x; i<n; i++)
    {
        for(long long j=0; j<pilot/2; j++)
        {
            if(b[ind].y<i)
            {
                f++;
                break;
            }
            if(b[ind].x<=i) ind++;
            if(ind==a)
            {
                cout<<"MIXED"<<"\n";
                return 0;
            }
        }
        if(f>0) break;
    }
    if(f==0) cout<<"MIXED"<<"\n";
    else cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}
