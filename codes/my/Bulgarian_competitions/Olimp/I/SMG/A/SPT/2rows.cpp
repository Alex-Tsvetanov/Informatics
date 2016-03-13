#include<iostream>
using namespace std;
int a[100000],b[100000],ai,bi,i,j,ci;
char bla[6];
bool ans;
bool f()
{
    ci=-1;
    ans=1;
    cin>>ai;
    for(i=0;i<ai;++i)
    {
        cin>>a[i];
    }
    cin>>bi;
    for(i=0;i<bi;++i)
    {
        cin>>b[i];
        for(j=0;j<ai;++j)
        {
            if(a[j]==b[i])
            {
                if(j<ci+1)
                {
                    ans=0;
                }
                else
                {
                    ci=j;
                }
            }
        }
    }
    return ans;
}
int main()
{
    for(int z=0;z<5;++z)
    {
        if(f())
        {
            bla[z]='1';
        }
        else
        {
            bla[z]='0';
        }
    }
    bla[6]='\0';
    cout<<bla;
    return 0;
}
