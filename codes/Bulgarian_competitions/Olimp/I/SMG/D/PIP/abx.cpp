#include<iostream>
using namespace std;
int main ()
{
    char a[2010];
    cin>>a;
    int b,c=1,a1=0,b1=0;
    if(a[0]=='X')
    {
        for(b=2; a[b]!='='; b++)
        {
            c=c*10;
        }
        b=2;
        c=c/10;
        while(c>=1)
        {
            a1=a1+(a[b]-48)*c;
            c=c/10;
            b=b+1;

        }
        int g=b+1;
        c=1;
        for(b++; a[b]!='\0'; b++)
        {
            c=c*10;
        }
        c=c/10;
        while(c>=1)
        {
            b1=b1+(a[g]-48)*c;
            c=c/10;
            g=g+1;
        }
        cout<<b1-a1;
    }
    if(a[0]!='X')
    {
        for(b=0; a[b]!='+'; b++)
        {
            c=c*10;
        }
        c=c/10;
        b=0;
        while(c>=1)
        {
            a1=a1+(a[b]-48)*c;
            c=c/10;
            b=b+1;
        }
        b=b+3;
        int g=b;
        c=1;
        for(b=b; a[b]!='\0'; b++)
        {
            c=c*10;
        }
        c=c/10;
        while(c>=1)
        {
            b1=b1+(a[g]-48)*c;
            c=c/10;
            g=g+1;
        }
        cout<<b1-a1;
    }
    cout<<"\n";
    return 0;
}
