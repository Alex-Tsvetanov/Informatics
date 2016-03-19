#include<iostream>
using namespace std;
int main()
{
    char a[100000];
    int i,br=0,s,c,f,n;
    cin>>a[i];
    for (i=0;i<100000;i++)
    {
        br++;
        if (a[i]=='.')break;
    }
    for (i=0;i<br;i++)
    {
        s=i-1;
        c=i-1;
        if (a[i]!=a[s] && a[i]!=a[s])
        {
            do
            {
                n++;
            }while(a[i]!=a[s] && a[i]!=a[c]);
        }
        else if (a[i]==a[s] && a[i]==a[c]);
        {
            do
        {
        f=f+2;
        }while(a[i]=a[c]);

        }
    }
    if(br<=f)cout<<br-f<<endl;
    else cout<<f-br<<endl;
    return 0;
}






