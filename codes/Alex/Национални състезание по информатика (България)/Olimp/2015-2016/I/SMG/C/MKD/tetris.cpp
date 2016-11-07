#include<iostream>
using namespace std;
int main()
{
    int n,m,s=0;
    char p[101][101];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>p[i][j];
        }
    }
    bool f;
    int k=0;
    for(int i=0;i<n;i++)
    {
        f=true;
        for(int j=0;j<m;j++)
        {
            if(p[i][j]=='.')
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            k++;
        }
        else
        {
            k=0;
        }
        s+=k;
    }
    cout<<s;
    return 0;
}
