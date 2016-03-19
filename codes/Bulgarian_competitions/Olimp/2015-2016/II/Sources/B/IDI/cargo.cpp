#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct beg
{
    int x,y;
};
bool operator<(beg a,beg b)
{
    return a.x<b.x;
}
beg del[1000001];
int br;
priority_queue<int> pending;
int workt(int from,int to)
{
    int ans=to-from;
    int fst=(from-1)/7;
    int lst=(to-1)/7;
    ans-=(lst-fst);
    from+=7;
    to+=7;
    fst=(from-7)/7;
    lst=(to-7)/7;
    ans-=lst-fst;
    return ans;
}
int last,p;
void process(int to,bool state)
{
    long long days;
    if(state)
    {
        days=workt(last,to);
    }
    else
    {
        days=to-last;
    }
    days*=p;
    for(int j=0;j<days&&!pending.empty();j++)
    {
        pending.pop();
    }
    last=to;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m>>p;
    p/=2;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        del[br].x=x;
        del[br].y=y;
        br++;
    }
    sort(del,del+br);
    del[br].x=n;
    del[br].y=n;
    br++;
    bool nss=true;
    last=del[0].x;
    for(int i=0;i<br;i++)
    {
        while(!pending.empty()&&(-pending.top())<del[i].x)
        {
            process(-pending.top()+1,true);
            if(!pending.empty()&&last>(-pending.top()))
            {
                nss=false;
                while(!pending.empty())
                {
                    pending.pop();
                }
                break;
            }
        }
        if(!nss)
        {
            break;
        }
        if(del[i].x==n)
        {
            break;
        }
        process(del[i].x,true);
        pending.push(-del[i].y);
    }
    if(nss)
    {
        cout<<"OK\n";
        return 0;
    }
    bool ss=true;
    last=del[0].x;
    for(int i=0;i<br;i++)
    {
        while(!pending.empty()&&(-pending.top())<del[i].x)
        {
            process(-pending.top()+1,false);
            if(!pending.empty()&&last>(-pending.top()))
            {
                ss=false;
                break;
            }
        }
        if(!ss)
        {
            break;
        }
        if(del[i].x==n)
        {
            break;
        }
        process(del[i].x,false);
        pending.push(-del[i].y);
    }
    if(ss)
    {
        cout<<"MIXED\n";
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
