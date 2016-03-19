#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
#include <windows.h>
using namespace std;
int k[20000][20000]={0};
bool beznak(int n,int a,int b)
{  if(a==b)return false;
if(k[a-1][b-1]==1)return true;
    for(int i=a;i<n;i++)
    {

        if(k[a-1][i]==1)return beznak(n,i+1,b);
    }
}
int nak(int n,int a,int b,int s=0)
{
    if(a==b&&s==0)return -1;
    if(k[a-1][b-1]==1)return s;
    if(k[a-1][b-1]==2){s++;return s;}
    for(int i=a;i<n;i++)
    {

        if(k[a-1][i]==1){return nak(n,i+1,b,s);}
        if(k[a-1][i]==2){s++;return nak(n,i+1,b,s);}
    }
    return -2;

}
int nak1(int n,int a,int b,int s=0,int s1=-1)
{
    if(a==b&&s==0)return -1;
    if(k[a-1][b-1]==2)return s;
    if(k[a-1][b-1]==1){s++;return s;}
    for(int i=a;i<n;i++)
    {

        if(k[a-1][i]==2){return nak(n,i+1,b,s);}
        if(k[a-1][i]==1){s++;return nak(n,i+1,b,s);}
    }


}
int main()
{
ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;


    int r,l;
    cin>>r>>l;
    while(!cin.eof())
    {
        k[r-1][l-1]=1;
        if(k[l-1][r-1]==0)k[l-1][r-1]=2;

        cin>>r>>l;

    }
    cin.clear();
int s=0;



if(beznak(n,a,b)){cout<<0<<endl;return 0;}
    int v=nak(n,a,b,s);
    if(v==-2){cout<<"X"<<endl;return 0;}
    int q=nak1(n,a,b,s);
if(v<q)cout<<v<<endl;
  else cout<<q<<endl;






return 0;
}
