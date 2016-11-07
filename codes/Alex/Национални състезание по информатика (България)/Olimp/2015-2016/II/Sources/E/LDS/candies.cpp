#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long int a,b,c,br=0;
    cin>>a>>b>>c;
    while (b!=0||a!=0||c!=0)
    {
        int bra=a-1;
        int brb=b-1;
        int brc=c-1;
        br=br+3;
        cin>>br;
    }
    cout<<br<<endl;


    return 0;
}
