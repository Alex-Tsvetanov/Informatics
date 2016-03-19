#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    char a='a',b='.',c;
    int brc=0,bri=0,d=0,m=0;
    while (a!='.')
    {
        cin>>a;
        if (a=='.') break;
        brc++;
        if (a==b && d==0)
        {
            d=1;
        }
        if (a==b)
        {
            d++;
        }
        if (a!=b)
        {
            while (d!=0)
            {
                m=m+1;
                d=d/10;
            }
            bri+=m;
            d=0;
            m=0;
            bri++;
        }
        c=b;b=a;
    }
    while (d!=0)
            {
                m=m+1;
                d=d/10;
            }
    if (c==b) bri+=m;
    cout<<brc-bri<<endl;
    return 0;
}
