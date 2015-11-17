#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int tempcifrinachislo[21],vuzmojnikombinacii[1000000];
void razpadniNaCifri(int chislo)
{
    int broiCifri=0;
    for(int i=0; i<20; i++)
    {
        tempcifrinachislo[i] = 0;
    }
    while(chislo!=0)
    {
        int cifri = chislo % 10;
        chislo = chislo / 10;
        tempcifrinachislo[broiCifri] = cifri;
        broiCifri=broiCifri+1;
    }

}
int sglobiCifriNaChislo(int a, int b)
{
    int times = 1;
    while(times<=b)
    {
        times=times*10;
    }
    return a*times+b;

}
int kolkoCifrenoE(int chislo)
{
    int broiCifri = 0;
    for(int i=1; i<chislo; i=i*10)
    {
        broiCifri=broiCifri+1;
    }
    return broiCifri;
}
int main()
{
    int n,d[3],g=0,chisla=0;
    cin>>n>>d[0]>>d[1]>>d[2];
    for(int i = pow(10,n-1); i< pow(10,n); i++)
    {
        razpadniNaCifri(i);
        for(int j=kolkoCifrenoE(i)-1; j>=0; j=j-1)
        {
            vuzmojnikombinacii[g] = vuzmojnikombinacii[g] * 100 + sglobiCifriNaChislo(tempcifrinachislo[j],tempcifrinachislo[j-1]);
        }
        if((vuzmojnikombinacii[g]%d[0]==0 or vuzmojnikombinacii[g]%d[1]==0 or vuzmojnikombinacii[g]%d[2]==0))
        {
            chisla = chisla + 1;
        }
        g=g+1;

    }
    razpadniNaCifri(chisla);
    cout<<chisla<<endl;
    return 0;
}
