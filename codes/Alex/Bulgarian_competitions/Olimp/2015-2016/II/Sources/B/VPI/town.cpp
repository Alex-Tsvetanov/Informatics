#include  <iostream>
#include  <cstdlib>
#include  <algorithm>
#include  <cmath>
#include  <string>
#include  <windows.h>
using  namespace  std;
int c[20000][20000]={0};
int main()
{
    int n;
    cin>>n;
    int a;
    cin>>a;
    int b;
    cin>>b;
    int p;
    cin>>p;
    int q;
    cin>>q;
    int greshki=0;
    while(!cin.eof())
    {
        c[p][q]=1;
        if(c[q][p]==0) c[q][p]=2;
        cin>>p>>q;
    }
    if(c[a][b]==1)
    {
        cout<<0;
        return 0;
    }
    if(c[a][b]==2)
    {
        cout<<1;
        return 0;
    }
    if(a<b)
    {
        for(int i=a;i<b;i)
        {
            if(c[i][i+1]==1) i++;
            if(c[i][i+1]==2)
            {
                i++;
                greshki++;
            }
            if(i==b)
            {
                cout<<greshki;
                return 0;
            }
            if(c[i][i+1]==0)
            {
                cout<<"X";
                return 0;
            }
        }

    }
    if(a>=b)
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    {
        for(int i=a;i>b;i)
        {
            if(c[i][i-1]==1) i--;
            if(c[i][i-1]==2)
            {
                i--;
                greshki++;
            }
            if(i==b)
            {
                cout<<greshki;
                return 0;
            }
            if(c[i][i-1]==0)
            {
                cout<<"X";
                return 0;
            }
        }
    }







return 0;

}
