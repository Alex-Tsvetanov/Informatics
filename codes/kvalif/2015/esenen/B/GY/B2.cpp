#include<iostream>
#include<algorithm>

using namespace std;

int a[200100];
int p[200100];
vector<int> jump;

int main()
{
    int N,M;
    cin>>N>>M;

    for(int i=0; i<M; i++)
    {
        int a;
        cin>>a;
        jump.push_back(a);
    }
    sort(jump.begin(),jump.end());

    for(int i=0; i<N+1; i++)
    {
        cin>>a[i];
    }

    p[0]=a[0];

    for(int i=0;i<=N;i++)
    {
        if(p[i])
        {
            for(int j=0;j<jump.size() and i+jump[j]<=N;j++)
            {
                if(p[i+jump[j]]<p[i]+a[i+jump[j]])
                {
                    p[i+jump[j]]=p[i]+a[i+jump[j]];
                }
            }
        }
    }
    int res=-1;
    int n=-1;
    for(int i=0;i<=N;i++)
    {
        if(res<p[i]){res=p[i];n=i;}
    }

    cout<<res<<" "<<n;
        return 0;
}
