#include<iostream>
#include<queue>
using namespace std;
short gn[1016][1016];
int N,M,T,br=0;
queue<pair<int,int> > q;

void DFS(int x,int y)
{
    pair<int,int> c;
    c.first = x;
    c.second = y;
    q.push(c);
    gn[c.first][c.second]=0;
    while(!q.empty())
    {
        c = q.front();
        q.pop();
        if(gn[c.first][c.second]==T)continue;
        if(c.first!=0)
        {
            if(!gn[c.first+1][c.second]){
            q.push(make_pair(c.first-1,c.second));
            gn[c.first-1][c.second]=gn[c.first][c.second]+1;
        }}
        if(c.second!=0)
        {
            if(!gn[c.first+1][c.second]){
            q.push(make_pair(c.first,c.second-1));
            gn[c.first][c.second-1]=gn[c.first][c.second]+1;
        }}
        if(c.second!=M-1)
        {
            if(!gn[c.first+1][c.second]){
            q.push(make_pair(c.first,c.second+1));
            gn[c.first][c.second+1]=gn[c.first][c.second]+1;
        }}
        if(c.first!=N-1)
        {
            if(!gn[c.first+1][c.second]){
            q.push(make_pair(c.first+1,c.second));
            gn[c.first+1][c.second]=gn[c.first][c.second]+1;
        }}
    }

}

int main()
{
    int x=-100,y=-100,x1=-100,y1=-100;
    cin>>N>>M>>T;
    cin>>x>>y;
    cin>>x1>>y1;
    x1--;
    y1--;
    x--;
    y--;
    if(x1!=-101)DFS(x1,y1);
    DFS(x,y);

    for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(gn[i][j])br++;
    cout<<N*M-br<<"\n";

    return 0;
}
