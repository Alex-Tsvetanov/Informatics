#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    unsigned int M;
    cin>>M;
    int koordinati,lice=0;
    for(M=3; M<100; M++)
    {
        koordinati=2*M;
        cin>>koordinati;
    }
    switch (M)
    {
    case 3:
        int a,a1,b,b1,c,c1;
        cin>>a>>a1>>b>>b1>>c>>c1;
        lice = (abs(c1-a1)+abs(a1-b1))*(abs(a-b));
        break;
    case 4:
        int d,d1,e,e1,f,f1,g,g1;
        cin>>d>>d1>>e>>e1>>f>>f1>>g>>g1;
    }


    return 0;
}
