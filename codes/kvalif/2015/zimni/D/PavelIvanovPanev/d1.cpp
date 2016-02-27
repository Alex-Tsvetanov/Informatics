#include<iostream>
using namespace std;
int main ()
{
    int a,b,c,n,q;
    cin>>a>>b>>c>>n;
    for(int br=1; br<21; br=br)
    {
        if(br==n)
        {
            q=a;
        }
        br++;
        if(br==n)
        {
            q=b;
        }
        br++;
        if(br==n)
        {
            q=c;
        }
        br++;
        a=a+b+c;
        b=b+c+a;
        c=c+a+b;
    }
    cout<<q;
    return 0;
}
