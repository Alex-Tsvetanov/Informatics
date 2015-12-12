#include<iostream>
#include<algorithm>
using namespace std;
int chisloB,cifri[100000],cifriNaA[100000],cifriNaC[100000],broiCifri=0;
void razpadniMiNaCifri(int chislo)
{
    broiCifri=0;
    int number = chislo;
    while(number!=0)
    {
        cifri[broiCifri] = number%10;
        number=number/10;
        broiCifri=broiCifri+1;
    }
}
int cifriNaChislo(int cifrite[])
{
    int number;
    for(int i=0; i<broiCifri-1; i++)
    {
        number = cifrite[i]*10+cifrite[i+1];
    }
    return number;
}
int main()
{
    cin>>chisloB;
    razpadniMiNaCifri(chisloB);
    sort(cifri+0,cifri+broiCifri);
    for(int i=0; i<broiCifri; i++)
    {
        cifriNaA[i] = cifri[i];
    }

    for(int i=0; i<broiCifri; i++)
    {
        cifriNaC[i] = cifriNaA[broiCifri-i-1];
    }

    for(int i=0; i<broiCifri; i++)
    {
        cout<<cifriNaA[i];
    }
    cout<<endl;
    for(int i=0; i<broiCifri; i++)
    {
        cout<<cifriNaC[i];
    }




    return 0;
}
