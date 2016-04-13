#include <iostream>
using namespace std;
int main()
{
    long long n,br_sqr,i,j,br=0;
    cin>>n;
br_sqr=(n-1)/3;

    for(i=1;i<=br_sqr/1;i++)
    for(j=i;j<=br_sqr/i;j++)
    {
        if(i*j==br_sqr)br++;
    }
    if(n%12%2==0)br++;
    if(n-(((br_sqr-1)*3)+4)!=0)cout<<"0"<<endl;
    else
    cout<<br<<endl;

    return 0;
}
