#include <iostream>
using namespace std;
int main ()
{
    char a,n;
    long long br1=0,br2=0;
    cin>>a;
    n=a;
    while(a!='.')
    {
        cin>>a;
        if(a==n)br1++;
        else br2++;
        n=a;
    }
    if(br1>br2)cout<<br1-br2<<endl;
    else
    {
        if(br2==1&&br1==0)cout<<"0"<<endl;
        else cout<<br2-br1<<endl;
    }

    return 0;
}
