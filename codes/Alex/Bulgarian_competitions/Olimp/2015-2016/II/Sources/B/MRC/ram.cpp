#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int k,inp;
int ans;
queue<int> q;

void cs()
{
    if(inp<10000000) k=3000;
    else k=5000;
}

long long cnt_ogr(int n, int m)
{
    long long ans;
    ans=(n+m)*2 + (n-1)*m + (m-1)*n;
    return ans;
}

long long cnt_path(int n, int m)
{
    long long ans;
    if(m>n) ans=n*2;
    else ans=(n*2)-((n-m)*2+1);

    return ans;
}

void gen()
{
    int curr;
    for(int i=1; i<k; i++)
    {
        for(int j=1; j<k; j++)
        {
            curr=cnt_ogr(i,j)-cnt_path(i,j);
            if(curr==inp)
            {
                ans++;
                q.push(i);
                q.push(j);
            }
        }
    }
}
void print()
{
    printf("%d\n",ans);
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
        printf("%d\n",q.front());
        q.pop();
    }
}

int main()
{
    scanf("%d",&inp);
    cs();
    gen();
    print();
    return 0;
}
