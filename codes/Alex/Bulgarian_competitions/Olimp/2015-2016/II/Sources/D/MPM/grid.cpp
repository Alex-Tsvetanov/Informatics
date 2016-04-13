#include<iostream>
#include<queue>
using namespace std;
char grid[200][200];
long long m,n,i,j,brb=0,x,y,res=0;
queue <long long> neigh;
int main()
{
    cin>>m>>n;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++){cin>>grid[i][j];if(grid[i][j]=='0')brb++;}
    neigh.push(1);
    while(brb>0)
    {
    while(neigh.empty()==0)
    {
        if(neigh.front()%n==0){x=neigh.front()/n-1;y=n-1;}
        else {x=neigh.front()/n;y=neigh.front()%n-1;}
        grid[x][y]='2';
        brb--;
        if(x<m-1 && grid[x+1][y]=='0'){neigh.push(neigh.front()+n);grid[x+1][y]='2';}
        if(y<n-1 && grid[x][y+1]=='0'){neigh.push(neigh.front()+1);grid[x][y+1]='2';}
        if(x>0 && grid[x-1][y]=='0'){neigh.push(neigh.front()-n);grid[x-1][y]='2';}
        if(y>0 && grid[x][y-1]=='0'){neigh.push(neigh.front()-1);grid[x][y-1]='2';}
        neigh.pop();
    }
    for(i=1;i<=n*m;i++)
    {
        if(i%n==0){x=i/n-1;y=n-1;}
        else {x=i/n;y=i%n-1;}
        if(grid[x][y]=='0'){neigh.push(i);break;}
    }
    res++;
    }
    cout<<res<<endl;
    return 0;
}