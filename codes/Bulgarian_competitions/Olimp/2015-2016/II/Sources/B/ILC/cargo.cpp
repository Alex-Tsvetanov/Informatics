#include<iostream>
#include<vector>
#define MAXM 1000001
using namespace std;
int m,p;
long long n;


struct info
{
    long long from;
   // vector<long long>to;
   long long to;
   long long dif;


}a[MAXM];
void path_finder()
{

}
void read()
{
    cin>>n>>m>>p;
    for(int i=1;i<=m;i++)
    {
       cin>>a[i].from>>a[i].to;
       a[i].dif=a[i].to-a[i].from;
    }

}
int main ()
{
read();
path_finder();
return 0;

}
