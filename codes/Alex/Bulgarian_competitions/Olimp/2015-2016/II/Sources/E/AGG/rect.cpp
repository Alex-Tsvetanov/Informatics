#include <iostream>
using namespace std;
int main()
{
    int n,br=0,x,y,z,a,b;
    cin>>n;
    if(n<12&&n>4)
    {
        if(n%4==3) cout<<n/4+1<<endl;;
        else cout<<"0"<<endl;
    }
    if(n<5)
    {
        if(n==4) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    if(n>=12)
    {
        if(n%4==2)
        for(x=1;3*x;x++)
        {
            for(y=1;y*2<=n-(x+4)*3)
            if(y*2+x*3+4==n) br++

        }
        cout<<br<<endl;
    }
    return 0;
}

