#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,q,ans=0,add=1;
double nx[10000],ny[10000],nr[10000];
double mx[10],my[10],mr[10][10001];
double s[10000];
double * mrp[10];
int cp(int a, int b,int ii, int jj)
{
    if(b-a<=1)
    {
        return a+1;
    }
    if(s[jj]<mr[ii][(a+b)/2])
    {
        return cp(a,(a+b)/2,ii,jj);
    }
    return cp((a+b)/2,b,ii,jj);
}
int main()
{
    cin>>n>>m>>q;
    for(int i=0;i<n;++i)
    {
        cin>>nx[i]>>ny[i]>>nr[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>mx[i]>>my[i];
    }
    for(int i=0;i<q;++i)
    {
        cin>>s[i];
    }
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            mr[i][j]=nr[j]+sqrt((nx[j]-mx[i])*(nx[j]-mx[i])+(ny[j]-my[i])*(ny[j]-my[i]));
        }
        sort(&mr[i][0],&mr[i][n]);
    }
    for(int asdf=0;asdf<q;++asdf)
    {
        if(!(add%2))
        {
            s[asdf]*=2;
        }
        add=0;
        for(int i=0;i<m;++i)
        {
            if(s[asdf]>mr[i][0])
            {
                add+=cp(0,n,i,asdf);
            }
        }
        ans+=add;
    }
    cout<<ans<<'\n';
    return 0;
}
