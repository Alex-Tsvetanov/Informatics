#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{

    char a;
    char n;
    int br=0,p=0,ost=0,d=0,brc=0;
    cin>>a;

    do
    {
        n=a;
        cin>>a;
        if(a==n)p++;
        else {
    do
    {
        brc++;
        p=p/10;
    }
    while(p!=0 );
             ost++;

         p=1;}
        br++;

    }
    while(a!='.');


    if(p<=9)d=2+ost;
    else
    {

        d=brc+2+ost;

    }

    if(br==1 or br==d)cout<<0<<endl;
    else cout<<br-d<<endl;

    return 0;
}
