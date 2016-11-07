#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a,b[1000001],c[1000001];
    long long br=0,d,e=0,f,g,h=0,i,j;
    do
    {
        cin.get(a);
        b[br]=a;
        br++;
    }
    while (a!='.');
    d=strlen(b)-1;
    br=0;
    for(e=0;e<=d-1;e++)
    {
        if(b[e]==b[e+1])
        {
            if(e==d-1)
            {
                br++;
                while (br!=0)
             {
                e=br%10;
                br=br/10;
                c[h]=e+48;
                h++;
             }
            c[h]=b[e];
            h++;
            c[h]=b[e+1];
            }
            else br++;
        }
        else
        if(b[e]!=b[e+1]&&br!=0)
        {
            if(e==d-1)
            {
            while (br!=0)
            {
                e=br%10;
                br=br/10;
                c[h]=e+48;
                h++;
            }
            c[h]=b[e];
            h++;
            c[h]=b[e+1];
            }
            else
            {
            while (br!=0)
            {
                e=br%10;
                br=br/10;
                c[h]=e+48;
                h++;
            }
            c[h]=b[e];
            h++;
            }
        }
        else
        if(b[e]!=b[e+1]&&br==0)
        {
            if(e==d-1)
            {
             c[h]=b[e];
             h++;
             c[h]=b[e+1];
            }
            else
            {
             c[h]=b[e];
             h++;
            }
        }
    }
    i=strlen(b);
    j=strlen(c);
    if(i>=j)cout<<i-j<<endl;
    else cout<<j-i<<endl;

    return 0;
}
