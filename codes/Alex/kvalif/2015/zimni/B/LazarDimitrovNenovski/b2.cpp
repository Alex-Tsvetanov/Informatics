#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, m, t;
    cin>>n>>m>>t;
    int table[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            table[i][j]=0;
        }
    }
    pair <int, int> apple1;
    pair <int, int> apple2;
    apple2.first=-1;
    apple2.second=-1;
    cin>>apple1.first>>apple1.second;
    table[apple1.first-1][apple1.second-1]=1;
    cin>>apple2.first>>apple2.second;
    table[apple2.first-1][apple2.second-1]=1;

    int s=n*m-2;
    if(apple2.first==-1)
    {
        s++;
    }

    for(int time=1;time<=t;time++)
    {
        for(int y=1;y<n;y++)
        {
            for(int x=1;x<m;x++)
            {
                if(table[y][x]==time)
                {
                    if(table[y+1][x]==0)
                    {
                        s--;
                        table[y+1][x]=time+1;
                    }
                    if(table[y-1][x]==0)
                    {
                        s--;
                        table[y-1][x]=time+1;
                    }
                    if(table[y][x+1]==0)
                    {
                        s--;
                        table[y][x+1]=time+1;
                    }
                    if(table[y][x-1]==0)
                    {
                        s--;
                        table[y][x-1]=time+1;
                    }
                }

            }
        }
    }
    cout<<s<<endl;
}
