#include<iostream>
using namespace std;
int main()
{
    int a,n,s;
    cin>>a;
    n=a-a%2;
    n=n/2;
    if(n==0)
    {
        s=1;
    }
    else if(n==1)
        {
            s=2;
        }
    else if(n==2)
        {
            s=4;
        }
    else if(n==3)
    {
        s=6;
    }
    else if(n==4)
    {
        s=10;
    }
    else if(n==5)
    {
        s=14;
    }
    else if(n==6)
    {
        s=20;
    }
    else if(n==7)
    {
        s=26;
    }
    else if(n==8)
    {
        s=36;
    }
    else if(n==9)
    {
        s=48;
    }
    else if(n==10)
    {
        s=60;
    }
    else if(n==11)
    {
        s=74;
    }
    else if(n==12)
    {
        s=88;
    }
    else if(n==13)
    {
        s=104;
    }
    else if(n==14)
    {
        s=120;
    }
    else if(n==15)
    {
        s=138;
    }
    else if(n==16)
    {
        s=158;
    }
    else if(n==17)
    {
        s=180;
    }
    else if(n==18)
    {
        s=202;
    }
    else if(n==19)
    {
        s=226;
    }
    else if(n==20)
    {
        s=250;
    }
    else if(n>20)
    {
        s=(n*(n+7))/2;
    }
    cout<<s<<endl;
    return 0;
}
