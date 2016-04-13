#include<iostream>
using namespace std;
int main()
{
    char h1[6],h2[6];
    int a,b,s;
    cin>>h1>>h2;
    for(int i=0;i<5;i++)
    {
        h1[i]-='0';
        h2[i]-='0';
    }
    a=(h1[0]*10+h1[1])*60+h1[3]*10+h1[4];
    b=(h2[0]*10+h2[1])*60+h2[3]*10+h2[4];
    if(a==b)
    {
        cout<<"00:00";
        return 0;
    }
    if(a<b)
    {
        s=b-a;
    }
    else
    {
        s=1440-a+b;
    }
    if(s<600) cout<<"0";
    cout<<s/60<<":"<<s%60;
    return 0;
}
