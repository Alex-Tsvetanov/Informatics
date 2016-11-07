#include<iostream>
using namespace std;
int main()
{
    long long brs=0,br=0,m,n,k;
    long long index[2][10000];
    cin>>k;
    m=n=k/2;
   // cout<<"----"<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j+2) { brs=(2*j*i+j+i)-(j+j); }
            if(j>=i+1) { brs=(2*j*i+j+i)-(i+i-1); }
            if(j==i || i==j+1) { brs=(2*j*i+j+i)-(j+i-1); }
            if(brs==k)
            {
                br++;
                index[1][br]=i;
                index[2][br]=j;
            }
            //cout<<brs<<endl;
            //if(j==n) cout<<"----"<<i<<endl;
            //cout<<index[1][br]<<" "<<index[2][br]<<endl;
            brs=0;
        }
    }
    cout<<br<<endl;
    for(int i=1;i<=br;i++) cout<<index[2][i]<<" "<<index[1][i]<<endl;
    return 0;
}
