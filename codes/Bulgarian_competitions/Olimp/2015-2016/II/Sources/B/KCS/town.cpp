#include<iostream>
#include<queue>
#include<stdio.h>
#include<stack>
#include<string.h>
#include<math.h>
using namespace std;
/*bool visited[200001],a[1001][1001];
int n,i=1,p,q,x,y,key=0,j,t,c[1001][2];
queue<int> m;
void null()
{
    for(j=0;j<n;j++)
        visited[j]=0;
}
void copy()
{
    for(j=1;j<=i;j++)
        a[c[j][0]][c[j][1]]=1;
    //cout<<c[1][0]<<' '<<c[1][1]<<endl;
}
void bfs()
{
    m.push(x);
    visited[x]=1;
    while(m.empty()==0)
    {
        t=m.front();
        cout<<t<<endl;
        m.pop();
        for(j=1;j<=n;j++)
        {
            if(a[t][j]==1)
            {
                if(visited[j]==1) {key=1;break;}
                m.push(j);
                visited[j]=1;
                a[t][j]=0;
            }
            else
            {
                if(a[j][t]==1)
                {
                    if(visited[j]==1) {key=1;break;}
                    m.push(j);
                    visited[j]=1;
                    a[j][t]=0;
                }
            }
        }
    }
}*/
int main ()
{
    /*
    scanf("%d %d %d",&n,&p,&q);
    while(key==0)
    {
        scanf("%d%d",&x,&y);
        //cout<<i<<endl;
        c[i][0]=x;
        c[i][1]=y;
        copy();
        null();
        bfs();
    }
    printf("%d\n",n);*/
    return 0;
}