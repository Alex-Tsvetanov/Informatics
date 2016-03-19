#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main ()
{
    vector <long long> conn[3005];
    queue <long long> q;
    queue <long long> qnew;
    queue <long long> answer;
    bool used[3005],flag=true;
    long long a,b,n,m,posleden,brniva=0,brgot=0,minniva=5000,brizp=0;
    cin>>n>>m;
    for(long long i=0;i<m;i++)
    {
        cin>>a>>b;
        conn[a].push_back(b);
    }
    for(long long i=0;i<=3000;i++)used[i]=0;
    for(long long i=0;i<=n-1;i++)
    {
        flag=true;
        q.push(i);
        used[i]=1;
        brniva=0;
        brgot=0;
        while(flag)
        {
            while(!q.empty())
            {
                posleden=q.front();
                for(long long j=0;j<conn[posleden].size();j++)
                {
                    if(used[conn[posleden][j]]==0)
                    {
                        used[conn[posleden][j]]=1;
                        brgot++;
                        qnew.push(conn[posleden][j]);
                    }
                }
                q.pop();
            }
            brniva++;
            while(!qnew.empty()){posleden=qnew.front(); qnew.pop(); q.push(posleden);}
            if(q.empty()&&qnew.empty())flag=false;
        }
        brniva--;
        if(brgot+1==n)
        {
            if(brniva<minniva)
            {
                while(!answer.empty())answer.pop();
                minniva=brniva;
                answer.push(i);
                brizp=1;
            }
            else
            if(brniva==minniva)
            {
                answer.push(i);
                brizp++;
            }
        }
        while(!q.empty())q.pop();
        for(long long j=0;j<=3000;j++)used[j]=0;
    }
    cout<<brizp<<endl;
    long long stupki=0;
    while(!answer.empty())
    {
        stupki++;
        if(stupki==brizp)cout<<answer.front()<<endl;
        else cout<<answer.front()<<" ";
        answer.pop();
    }
    return 0;
}
