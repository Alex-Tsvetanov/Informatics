#include<iostream>
using namespace std;
struct Colour
{
    int num;
    bool col;
};
int m,n;
int k=1;
Colour a[205][205];

void Init ()
{
    int t;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>t;
            if(t==0)a[i][j].col=false;
            else a[i][j].col=true;
        }
    }
   for(int i=0;i<=m+1;i++)
    for(int j=0;j<=n+1;j++)
        a[i][j].num=0;
   a[1][1].num=k;
}

void Solve ()
{
    int t=0;
    bool tr=true;
    while(true)
    {

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j].col==false && a[i][j].num==0)
                {

                    if(a[i-1][j].num==k){a[i][j].num=k;continue;}
                    if(a[i+1][j].num==k){a[i][j].num=k;continue;}
                    if(a[i][j-1].num==k){a[i][j].num=k;continue;}
                    if(a[i][j+1].num==k){a[i][j].num=k;continue;}
                }

        t=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j].num==0 && a[i][j].col==false)t++;
        if(t==0)break;
        k++;
        tr=true;
        for(int i=0;i<=m and tr==true;i++)
                for(int j=0;j<=n;j++)
                    if(a[i][j].col==false and a[i][j].num==0){a[i][j].num=k;tr=false;}
    }

}

int main()
{
    Init();
    Solve();
    cout<<k--<<endl;
    return 0;
}
