#include<iostream>
using namespace std;
bool vyzmojnosti[101];
long long kolko=0,n;
long long izbroqvane(long long dokyde,long long segashnacifra)
{
    if(dokyde==n)
    {
        kolko++;
        return 0;
    }
    for(long long i=0; i<10; i++)
    {
        if(vyzmojnosti[segashnacifra*10+i]==1)
        {
            izbroqvane(dokyde+1,i);
        }
    }
    return 0;
}
int main()
{
    long long d1,d2,d3;
    cin>>n>>d1>>d2>>d3;
    long long k=d1;
    while(k<100)
    {
        vyzmojnosti[k]=1;
        k=k+d1;
    }
    k=d2;
    while(k<100)
    {
        vyzmojnosti[k]=1;
        k=k+d2;
    }
    k=d3;
    while(k<100)
    {
        vyzmojnosti[k]=1;
        k=k+d3;
    }
    for(long long i=1; i<10; i++)
    {
        for(long long r=0; r<10; r++)
        {
            if(vyzmojnosti[i*10+r]==1)
            {
                   // cout<<i*10+r<<" ";
                izbroqvane(2,r);
            }
        }
    }
    cout<<kolko;
    return 0;
}
