#include<iostream>
using namespace std;
bool lider(int a,int b)
{
    if(a>=b)return 1;
    return 0;
}
int main()
{
long long int n,h=0,j=0,i,a[1000];
cin>>n;
for(i=0;i<n;i++)
{
    cin>>a[i];
}
int testa=a[0];
int l=0;
int bonus=0;
while(h!=i)
{
    h++;
for(j=bonus;j<n;j++)
{
    l=lider(testa,a[j]);
    if(l==0)testa=a[j];
    if(j+1==n)
    {
        cout<<testa<<endl;
        bonus++;
    }
}
}
return 0;
}
