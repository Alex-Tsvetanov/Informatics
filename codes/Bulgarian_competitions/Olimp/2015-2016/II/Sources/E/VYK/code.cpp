#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main ()
{
    char a='a',b='0';
    long long brs=0,br=0;
    bool flag=false;
    while (a!='.')
    {
        cin.get (a);brs++;
        if (a=='.')
        {
        if (flag==true)
        {
        br+=2;
        break;
        }
        else break;
        }
        if (a==b) {if (flag==true)continue; else {br--;flag=true;continue;}}
        else {if (flag==true) {br=br+3;flag=false;} else {br++;}}
        b=a;
    }
    brs--;
    cout<<abs (br-brs)<<"\n";
    return 0;
}
/*
abcddde.    a.      xxxxxx.

2           0       4
*/
