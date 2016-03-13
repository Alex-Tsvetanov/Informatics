#include<iostream>
#include<queue>
using namespace std;
int posokaX[8]={0,1,0,-1};
int posokaY[8]={-1,0,1,0};
long long otg=0,n,m,T,br, qb[4]={-1,-1,-1,-1}, put1[1024][1024], put2[1024][1024],a;
void bfs(int sX, int sY, bool koe)
{

    queue<int> q;
    q.push(sX);
    q.push(sY);
    if(koe==0){
        put1[sX][sY]=1;
        otg++;
    }
        else{
            put2[sX][sY]=1;
            if(put1[sX][sY]==0)
                otg++;
        }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        int y=q.front();
        q.pop();
        if(koe==0)
        {
            if(put1[x][y]<T+1)
            {
                for(int i=0;i<4;i++)
                {

                    if(x+posokaX[i]>0 && x+posokaX[i]<=n && y+posokaY[i]>0 && y+posokaY[i]<=m && put1[x+posokaX[i]][y+posokaY[i]]==0)
                    {
                        otg++;
                        q.push(x+posokaX[i]);
                        q.push(y+posokaY[i]);
                        put1[x+posokaX[i]][y+posokaY[i]]=put1[x][y]+1;
                    }
                }
            }
        }
        else
        {
            if(put2[x][y]<T+1)
            {
                for(int i=0;i<4;i++)
                {

                    if(x+posokaX[i]>0 && x+posokaX[i]<=n && y+posokaY[i]>0 && y+posokaY[i]<=m && put2[x+posokaX[i]][y+posokaY[i]]==0)
                    {
                        //otg++;
                        q.push(x+posokaX[i]);
                        q.push(y+posokaY[i]);
                        put2[x+posokaX[i]][y+posokaY[i]]=put2[x][y]+1;
                        if(put1[x+posokaX[i]][y+posokaY[i]]==0)
                            otg++;
                    }
                }
            }
        }
    }
}

int main(){
cin>>n>>m>>T;
for( br=0;cin>>a;br++)
  {
      qb[br]=a;
  }
    bfs( m-qb[1]+1, qb[0],0);

if(qb[2]!=-1)
{
    bfs( m-qb[3]+1, qb[2],1);
}

cout<<n*m-otg<<endl;
//cout<<otg<<endl;
return 0;
}
