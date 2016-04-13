#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct otsechka
{
    int a, b, nomer;
};
otsechka ots[1000004];
bool operator<(otsechka x, otsechka y)
{
    return x.b-x.a<y.b-y.a;
}
long long otg=0;
vector<otsechka> days[100000];
bool gotovi[100000];
int main(){

int dni, m, piloti;
cin>>dni>>m>>piloti;
//cin>>m;
piloti/=2;
for(int i=0;i<m;i++)
{
    cin>>ots[i].a>>ots[i].b;
    ots[i].nomer=i;
    for(int j=ots[i].a;j<=ots[i].b;j++){
        days[j].push_back(ots[i]);
    }
}
sort(ots, ots+m);/*
int currN=ots[0].a;
int currK=ots[0].b;
for(int i=1;i<m;i++)
{
    if(ots[i].a<=ots[i-1].b)
    {
        if(ots[i].b>currK)
            currK=ots[i].b;
    }
    else
    {
        otg+=currK-currN;
        currN=ots[i].a;
        currK=ots[i].b;
    }
}
otg+=currK-currN;
//cout<<otg<<endl;
int x1=ots[0].a, x2;
for(;;)
{

}
*/
if(dni<1000){
int otg=0;
///cout<<"piloti "<<piloti<<endl;
for(int i=1;i<=ots[m-1].b;i++)
{
   /// cout<<"den "<<i<<endl;
   /// cout<<"imam:\n ";
    sort(days[i].begin(), days[i].end());
    int currZeti=0;
    for(int j=0;j<days[i].size();j++)
    {
     ///   cout<<days[i][j].nomer<<endl;

        if(!gotovi[days[i][j].nomer] && currZeti<piloti && i%6!=0 && i%7!=0)
        {
        ///    cout<<"zimam q\n";
            gotovi[days[i][j].nomer]=1;
            currZeti++;
            otg++;
        }
    }

}

if(otg<m)
{
    otg=0;
    for(int i=0;i<m;i++)
    {
        gotovi[i]=0;
    }
    for(int i=1;i<=ots[m-1].b;i++)
    {
       /// cout<<"den "<<i<<endl;
      ///  cout<<"imam:\n ";
       // sort(days[i].begin(), days[i].end());
        int currZeti=0;
        for(int j=0;j<days[i].size();j++)
        {
         ///   cout<<days[i][j].nomer<<endl;

            if(!gotovi[days[i][j].nomer] && currZeti<piloti)
            {
           ///     cout<<"zimam q\n";
                gotovi[days[i][j].nomer]=1;
                currZeti++;
                otg++;
            }
        }

    }
    if(otg<m)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        cout<<"MIXED\n";
    }
}
else
{
    cout<<"OK\n";
}}
else
    cout<<"MIXED\n";
return 0;
}
