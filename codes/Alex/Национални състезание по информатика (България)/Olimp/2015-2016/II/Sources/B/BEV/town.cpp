#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long used[10001][10001],n,a,b,x,y,next,br,flag,used1[10001];
vector  <long long> v[10001];
queue <long long> q,q1;
int main()
{
    cin>>n>>a>>b;
    for(int i=1; i<=n; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        used[x][y]=1;
        used[y][x]=-1;
    }

    q.push(a);
    q1.push(1);
    used[a][a]=1;int check;
    for(; !q.empty();)
    {

        a=q.front();
        q.pop();
        check=q1.front();
        q1.pop();
        if(check==-1)br++;
        used1[a]=1;
        if(a==b)
        {
            flag=1;
            break;
        }
        for(int i=0; i<v[a].size(); i++)
        {
            next=v[a][i];
            if(used1[next]==0)
            {
                if(used[a][next]=-1)
                    q1.push(-1);
                else q1.push(1);
                q.push(next);

            }
        }
        if(flag=1)break;

    }
    if(br==0)cout<<"X"<<endl;
    else cout<<br<<endl;
    return 0;
}
