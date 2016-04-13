#include<iostream>
using namespace std;long long ar[40000];
int main()
{
    long long  m,n,br=0,l=1;cin>>m>>n;
    for(int i=0; i<m*n; i++)
    {
        cin>>ar[i];if(ar[i]!=0)br++;
    }
    ar[0]=1;
    for(int i=2; i<=m*n; i++)
    {
        if(br==m*n)break;
        for(int i1=0; i1<=m*n; i1++)
        {
            if(ar[i1]==0)
            {
                if(ar[i1+n]==i-1||ar[i1-n]==i-1||ar[i1+1]==i-1||ar[i1-1]==i-1)
                {
                    ar[i1]=i;
                    br++;l=i;
                }
            }
        }
    }
cout<<l<<endl;
    return 0;
}
