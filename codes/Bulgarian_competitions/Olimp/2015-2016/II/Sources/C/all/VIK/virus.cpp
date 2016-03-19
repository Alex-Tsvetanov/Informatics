#include<iostream>
#include<string.h>

using namespace std;

long long a[502],res[502][502],br[502],n,num=3,p,maxi=0;

void solve(int x)
{
    long long i,t;
    
    if(num>n)return;
    
    if(a[x]==p-x)
    {
        if(maxi==x)
        {
            maxi++;
        }
        
        if(x==p-1)return;
        
        cout<<x<<" "<<a[x]<<endl;
        
        solve(x+1);
        
        return;
    }
    
    a[x]++;
    t=a[x]+1;
    
    for(i=x-1;i>=0;i--)
    {
        a[i]=t;
        t++;
    }
    
    for(i=0;i<=maxi;i++)
    {
        res[a[i]-1][br[a[i]-1]]=num;
        br[a[i]-1]++;
    }
    num++;
    
    cout<<x<<" "<<a[x]<<" "<<p<<" "<<maxi<<endl;
    
    if(x!=0 && a[x]<p-x)solve(x-1);
    else solve(x);
    
    return;
}

int main ()
{
    long long i=0,j,k=1;
    
    cin>>n;
    
    if(n>500)
    {
        
        while(k<n)
        {
            k*=2;
            i++;
        }
        
        cout<<i<<endl;
        
        return 0;
    }
    else
    {
        while(k<n)
        {
            k*=2;
            i++;
        }
        
        
        p=i;
        
        cout<<p<<endl;
        
        a[0]=1;
        res[0][0]=2;
        br[0]=1;
        
        solve(0);
        
        for(i=0;i<p;i++)
        {
            cout<<br[i]<<" ";
            
            for(j=0;j<br[i]-1;j++)
            {
                cout<<res[i][j]<<" ";
            }
            if(br[i]!=0)cout<<res[i][br[i]-1]<<endl;
        }
    }
    
    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}