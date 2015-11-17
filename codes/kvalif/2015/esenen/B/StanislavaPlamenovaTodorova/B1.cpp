#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long n=0, ind;
double  minn=10000000000000000;
struct polinom
{
    int m;
    double vurhoveX[144];
    double vurhoveY[144];
};
vector<polinom> v;
vector<polinom> kandidati;
double liceTrapec(double aX,double aY, double bX, double bY)
{
    double a;
    return a=((aX+bX)*(aY-bY))/2;
}
double lice(polinom p)
{
    double lice=0;
    for(int i=0;i<p.m-1;i++)
    {
        lice+=liceTrapec(p.vurhoveX[i], p.vurhoveY[i], p.vurhoveX[i+1], p.vurhoveY[i+1]);
    }
    lice+=liceTrapec(p.vurhoveX[p.m-1], p.vurhoveY[p.m-1], p.vurhoveX[0], p.vurhoveY[0]);
  //  cout<<lice<<endl;
    return lice;
}
int main(){

cin.tie(NULL);
ios::sync_with_stdio(false);
while(1)
{
    int a;
    cin>>a;
    if(a>0)
    {
        polinom poli;
        poli.m=a;
        for(int i=0;i<a;i++)
        {
            cin>>poli.vurhoveX[i]>>poli.vurhoveY[i];
        }
        v.push_back(poli);
        n++;
    }
    else
        break;
}
int minVurhove=1024;
for(int i=0;i<n;i++)
{
    if(abs(lice(v[i]))<minn)
    {
        minn=abs(lice(v[i]));
        minVurhove=v[i].m;
        ind=i;
    }
    if(abs(lice(v[i])==minn))
    {
        if(v[i].m<minVurhove)
        {
            minVurhove=v[i].m;
            ind=i;
        }
    }
}
//cout<<minn<<endl;
cout<<ind+1<<endl;


return 0;
}
