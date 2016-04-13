#include<iostream>
using namespace std;
bool m[200][200]; int a,b,br=0;
void range(int i,int j)
{
    if(i==a||j==b||i<0||j<0||m[i][j]==1) return;
    else
    {
        br++;
        m[i][j]=1;
        range(i+1,j);
        range(i,j+1);
        range(i-1,j);
        range(i,j-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>a>>b;
    for(int i=0;i<a*b;i++)
    {
        cin>>x;
        if(x){br++; m[i/b][i%b]=1;}
    }
    int p=0;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(!m[i][j]){range(i,j); p++;}
        }
    }cout<<p<<'\n';
    return 0;
}
