#include<iostream>

using namespace std;

int a[32][32][22];
bool x[32][32][22];

long long solve(int p,int n,int s)
{
    long long i,res=0;
    
    if(s<p)
    {
        p=s;
    }
        
    if(x[p][n][s]==1)return a[p][n][s];
    
    if(n==0)
    {
        a[p][n][s]=1;
        x[p][n][s]=1;
        return 1;
    }
    if(p==0)return 0;
    
    if(p*n<=s)
    {
        a[p][n][s]=p*n;
        x[p][n][s]=1;
        return p*n;
    }
    
    for(i=p-1;i>=0;i--)
    {
        res+=solve(p,n-1,s-i);
    }
    
    a[p][n][s]=res;
    x[p][n][s]=1;
    
    return res;
}

int main ()
{
    int p,n,s;
    
    cin>>p>>n>>s;
    
    cout<<solve(p,n,s)<<endl;
    
    return 0;
}