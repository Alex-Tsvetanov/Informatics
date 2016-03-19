#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define NMax 3000
#define MaxValue (1LL<<31)-1

using namespace std;

struct couple
{
    int fi,se;

    couple(){};
    couple(int a,int b)
    {
        fi=a,se=b;
    }
};

int n,m,from,to,ans=MaxValue,cur,cnt,arr[NMax+5];
vector<int> nb[NMax+5];
int used[NMax+5];

void bfs(int s)
{
    for(int i=0;i<n;i++)
        used[i]=-1;
    cur=-1;

    queue<couple> q;
    q.push(couple(s,0));

    while(!q.empty())
    {
        int tmp=q.front().fi,wave=q.front().se;
        q.pop();

        if(used[tmp]!=-1)continue;
        used[tmp]=wave;

        for(int i=0;i<nb[tmp].size();i++)
            if(used[nb[tmp][i]]==-1)
                q.push(couple(nb[tmp][i],wave+1));
    }

    for(int i=0;i<n;i++)
    {
        if(used[i]==-1)
        {
            cur=-1;
            break;
        }
        if(used[i]>cur)
            cur=used[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>from>>to;
        nb[from].push_back(to);
    }

    for(int i=0;i<n;i++)
    {
        bfs(i);
        if(cur==-1)continue;
        if(cur<ans)
        {
            ans=cur;
            for(int j=0;j<cnt;j++)
                arr[j]=0;
            cnt=0;
            arr[cnt++]=i;
        }
        else if(cur==ans)
        {
            arr[cnt++]=i;
        }
    }

    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        if(i==0)cout<<arr[i];
        else cout<<" "<<arr[i];
    }
    cout<<endl;

    return 0;
}
/**
8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4
*/
