#include<iostream>
using namespace std;
int main()
{
    long long m,n,a=1,k[200][200],key=1,j=0,key2=0;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>k[i][j];
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k[i][j]==1) k[i][j]=-1;
        }
    }
    k[0][0]=1;
    while(key==1)
    {
        key=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(k[i][j]==0) key2=1;
            }
        }
        j=0;
        if(key2==1) key=1;
        key2=0;
        for(int i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {   
                if((k[i+1][j] || k[i][j+1] || k[i-1][j] || k[i][j-1])==a && k[i][j]==0) k[i][j]=a; 
            }
        }
        key2=0;
        a++;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<k[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<a<<endl;
    return 0;
} 
