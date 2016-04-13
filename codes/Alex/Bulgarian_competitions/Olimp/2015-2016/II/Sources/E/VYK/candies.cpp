#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main ()
{
    long long a,b,c,i=1,br=0;
    cin>>a>>b>>c;
    while (i!=0)
    {
        if (a==1) {br++;break;}
        else {a--;br++;}
        if (b==1) {br++;break;}
        else {b--;br++;}
        if (c==1) {br++;break;}
        else {c--;br++;}
    }
    cout<<br<<"\n";
    return 0;
}
