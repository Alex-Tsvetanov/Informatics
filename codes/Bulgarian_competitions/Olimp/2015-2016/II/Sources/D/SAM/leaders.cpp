#include<iostream>
using namespace std;
int a[1000000];
int b[1000000];
int n;
int mi;
int br=0;
void Read()
{
    cin>>n;
     for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void Solve()
{
    int ti=0;
    int m;
    while(ti<n-2)
    {
        m=-1000000000;
        for(int i=ti;i<n;i++)
        {
            if(m<a[i]) {m=a[i];mi=i;}
        }
        if(mi==n-1) break;
        b[br]=m;
        br++;
        ti=mi+1;
    }
    for(int i=0;i<br;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<a[n-1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    Read();
    Solve();
    return 0;
}
