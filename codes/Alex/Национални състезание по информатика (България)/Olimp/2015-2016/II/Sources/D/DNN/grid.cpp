#include <iostream>
using namespace std;
long long m,n,a[200][200],b,d=1;

bool zero()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)return true;
        }
    }

    return false;
}
int main()
{

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b;

            if(b)a[i][j]=-1;
            else a[i][j]=0;
        }
    }

    d=1;

    long long ii,jj,br;bool k;

    while(zero())
    {
        k=false;

        for(ii=0;ii<n;ii++)
        {
            for(jj=0;jj<m;jj++)
            {
                if(a[ii][jj]==0){a[ii][jj]=d;k=true;break;}
            }
            if(k==true)break;
        }

        for(ii=0;ii<n;ii++)
        {
            for(jj=0;jj<m;jj++)
            {
                if(a[ii][jj]==0)
                {
                    br=0;
                    if(a[ii-1][jj]==d&&ii>0)br++;
                    if(a[ii+1][jj]==d&&ii<n)br++;
                    if(a[ii][jj-1]==d&&jj>0)br++;
                    if(a[ii][jj+1]==d&&jj<m)br++;
                    if(br>0)a[ii][jj]=d;
                }
            }
        }

        d++;
    }

    cout<<d-1<<endl;

    return 0;

}
