#include<iostream>
int br=0,brg=0,brd=0,brn=0,l,h,l1,h1,n,x,y,i,j,z,i1,j1;
bool t[101][101];
using namespace std;
int main()
{
    cin>>l>>h>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>l1>>h1;
        for(j=x;j<l1+x;j++)
        {
            for(z=y;z<h1+y;z++)
            {
                t[j][z]=1;
            }
        }
    }
    if(n!=0)
    {
    for(i=0;i<=l;i++)
    {
        for(j=0;j<=h;j++)
        {
            if(t[i][j]==1)  
            {
                for(i1=i;i1<=l;i1++)
                {
                    for(j1=j;j1<=h;j1++)
                    {
                        if(t[i1][j1]==0)
                        {
                            if(brn<(j1-j+1)*(i1-i+1))brn=(j1-j+1)*(i1-i+1);
                            break;
                        }
                    }
                    if(t[i1+1][j]==1)break;
                }
            }
        }
    }
    cout<<brn<<endl;
    }
    else cout<<l*h<<endl;   
    return 0;
}
// 12 8 2 2 0 3 3 6 1 5 4