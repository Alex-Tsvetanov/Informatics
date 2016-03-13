#include<iostream>
#include<cstring>
using namespace std;
char a;
int dig,pulls,hph,hpw,chess[27][27],n,m;
int X[]= {2,2,-2,-2,1,1,-1,-1};
int Y[]= {1,-1,1,-1,2,-2,2,-2};
bool check(int x,int y)
{
    if(x>0 && x<m && y>0 && y<n)
        return 1;
    return 0;
}
int main()
{
    cin>>a>>dig;
    if(dig>9)
        pulls=2;
    else
        pulls=1;
    n=a-'a'+2;
    m=dig+1;
    cin>>a>>dig;
    hph=dig;
    hpw=(a-'a'+1);
    chess[hph][hpw]=2;
    for(int i=0; i<8; i++)
        if(check(hph+X[i],hpw+Y[i]))
        {
            chess[hph+X[i]][hpw+Y[i]]=1;
        }
    for(int b=0; b<pulls+1; b++)
    {
        cout<<" ";
    }
    for(int b=0; b<n-1; b++)
        cout<<char(b+'a');
    cout<<endl;
    for(int i=1; i<m; i++)
    {
        if(i<10)
            for(int b=0; b<pulls-1; b++)
                cout<<" ";
        else
            for(int b=0; b<pulls-2; b++)
                cout<<" ";
        cout<<i<<" ";
        for(int j=1; j<n; j++)
        {
            if(chess[i][j]==0)
                cout<<"O";
            if(chess[i][j]==1)
                cout<<"X";
            if(chess[i][j]==2)
                cout<<"H";

        }
        cout<<endl;
    }
    return 0;
}
