#include <iostream>
using namespace std;
int main ()
{
    long long table[25][35],n,p,s,j,i,sum=0;
    cin>>p>>n>>s;
    for(j=0;j<=p-1;j++)table[1][j]=1;
    for(j=p;j<=s-1;j++)table[1][j]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=s-1;j++)
        {
            sum=0;
            if(j<=p-1)
            {
                for(int k=0;k<=j;k++)sum+=table[i-1][k];
                table[i][j]=sum;
            }
            else
            {
                for(int k=j-p+1;k<=j;k++)sum+=table[i-1][k];
                table[i][j]=sum;
            }
        }
    }
    sum=0;
    for(int j=0;j<=s-1;j++)sum+=table[n][j];
    cout<<sum<<endl;
    return 0;
}
