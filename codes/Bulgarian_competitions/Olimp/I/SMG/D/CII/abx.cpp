#include<iostream>
#include<cstring>
using namespace std;
char n[12];
int A,B,res,l;
int main()
{
    cin>>n;
    l=strlen(n);
    if(n[0]=='X')
    {
        int i=2;
        while(n[i]!='=')
        {
            A*=10;
            A+=n[i]-'0';
            i++;
        }
        i++;
        while(i<l)
        {
            B*=10;
            B+=n[i]-'0';
            i++;
        }
    }
    else
    {
        int i=0;
        while(n[i]!='+')
        {
            A*=10;
            A+=n[i]-'0';
            i++;
        }
        i+=3;
        while(i<l)
        {
            B*=10;
            B+=n[i]-'0';
            i++;
        }
    }
    res=B-A;
    cout<<res<<endl;
    return 0;
}
/**
12+X=30

X+12=3
*/
