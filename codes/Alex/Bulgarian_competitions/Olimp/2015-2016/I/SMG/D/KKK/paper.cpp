#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int res=0;
    while(a!=1)
    {
        if(a%2==0)
        {
            a=a/2;
            res+=1;
        }
        else
        {
            a=a/2+1;
            res+=1;
        }
    }
    while(b!=1)
    {
        if(b%2==0)
        {
            b=b/2;
            res+=1;
        }
        else
        {
            b=b/2+1;
            res+=1;
        }
    }
    cout<<res<<endl;
    return 0;
}
