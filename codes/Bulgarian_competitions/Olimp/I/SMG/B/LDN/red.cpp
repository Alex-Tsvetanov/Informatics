#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int amin=1000000, amax=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>amax)
        {
            amax=a[i];
        }
        if(a[i]<amin)
        {
            amin=a[i];
        }
    }
    int astartmin=-1, aendmin=n+1;
    int astartmax=-1, aendmax=n+1;
    bool tg1=true;
    bool tg2=true;
    bool tg3=true;
    bool tg4=true;
    for(int i=0, j=n;i<n;i++)
    {
        if(a[i]==amin and tg1)
        {
            astartmin=i;
            tg1=false;
        }
        if(a[i]==amax and tg2)
        {
            astartmax=i;
            tg2=false;
        }
        if(!tg1 and !tg2)
        {
            break;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==amax and tg3)
        {
            aendmax=i;
            tg3=false;
        }
        if(a[i]==amin and tg4)
        {
            aendmin=i;
            tg4=false;
        }
        if(!tg3 and !tg4)
        {
            break;
        }
    }
    if(abs(astartmax-aendmin)>abs(astartmin-aendmin))
    {
        cout<<astartmax+1<<" "<<aendmin+1<<endl;
    }else
    {
        cout<<astartmin+1<<" "<<aendmax+1<<endl;
    }

}
