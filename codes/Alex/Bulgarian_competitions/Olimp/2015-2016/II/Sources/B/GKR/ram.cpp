#include<iostream>
using namespace std;
int main()
{
    long long k,p=0,b,br=0,a[500][500];
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            b=(i*(j+1))+(j*(i+1));
            br=0;
            if(b>k)
            {
                if(i>j || i==j) br=j+j-1;
                if(j>i) br=i*2;
                if(b-br==k)
                {
                    a[i][j]=1;
                    p++;
                }
            }
        }
    }
    cout<<p<<endl;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(a[i][j]==1) cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}
