#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[61],b[61],c[121],n='0',x,y;
    int m,j=-1;
    cin>>a>>b;
    if(strlen(a)>=strlen(b))m=strlen(a);
    else m=strlen(b);
    x=a[strlen(a)-1];
    y=b[strlen(b)-1];
    for(int i=m-1;i>=0;i--)
    {
        j++;
        if(x=='?' and y!='?')
        {
            if(n=='?')
            {
                c[j]='?';
                n='?';
            }
            else
            {
                if((y-'0'+n-'0')%2==0)
                {
                    c[j]='?';
                    if(y-'0'+n-'0'!=0)n='1';
                    else n='0';
                }
                else
                {
                    c[j]='?';
                    n='?';
                }
            }
        }
        else if(x!='?' and y=='?')
        {
            if(n=='?')
            {
                c[j]='?';
                n='?';
            }
            else
            {
                if((x-'0'+n-'0')%2==0)
                {
                    c[j]='?';
                    if(x-'0'+n-'0'!=0)n='1';
                    else n='0';
                }
                else
                {
                    c[j]='?';
                    n='?';
                }
            }
        }
        else if(x=='?' and y=='?')
        {
            c[j]='?';
            n='?';
        }
        else if(x!='?' and y!='?')
        {
            if(n=='?')
            {
                c[j]='?';
                if((y-'0'+x-'0'+n-'0')%2==0)
                {
                    if((y-'0'+x-'0'+n-'0')==0)n='0';
                    else n='1';
                }
                else n='?';
            }
            else{
                if((y-'0'+x-'0'+n-'0')%2==0)
                {
                        c[j]='0';
                        if(y-'0'+x-'0'+n-'0'!=0)n='1';
                        else n='0';
                }
                else
                {
                    c[j]='1';
                    if(y-'0'+x-'0'+n-'0'>1)n='1';
                    else n='0';
                }
            }
        }
        if(strlen(a)<=m-i)x='0';
        else x=a[i-1];
        if(strlen(b)<=m-i)y='0';
        else y=b[i-1];
    }
    if(n!='0')
    {
        j++;
        c[j]=n;
    }
    for(j;j>=0;j--)cout<<c[j];
    cout<<endl;
    return 0;
}
