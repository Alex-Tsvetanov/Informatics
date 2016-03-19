#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int score=0,lastscore=1;

int a,b,c;
int N,M,Q;
double dis;
struct okrujnost{
    int x,y,R;
    okrujnost(int a,int b,int c){x=a;y=b;R=c;return;}
};
vector<okrujnost> cerc;
vector< pair<int,int> > points;
vector<int> hit;
vector<double> dist;
int findscore(int q)
{
    int big,small,mid;
    big=dist.size();
    small=-1;
    while(small+1<big)
    {
        mid=(small+big)/2;
        if(dist[mid]<=q){small=mid;}else{big=mid;}
    }
    return small+1;
}
int main()
{
    cin>>N>>M>>Q;
    for(int i=0;i<N;i++)
    {
        cin>>a>>b>>c;
        cerc.push_back(okrujnost(a,b,c));
    }
    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        points.push_back(pair<int,int>(a,b));
    }
    for(int i=0;i<Q;i++)
    {
        cin>>a;
        hit.push_back(a);
    }
    for(int i=0;i<M;i++)
    {
        if(i==0)
        {
            for(int j=0;j<N;j++)
            {
                dist.push_back(cerc[j].R+
sqrt((cerc[j].x-points[i].first)*(cerc[j].x-points[i].first)+(cerc[j].y-points[i].second)*(cerc[j].y-points[i].second)));
            }
        }else
        {
            for(int j=0;j<N;j++)
            {
                dis=cerc[j].R+
sqrt((cerc[j].x-points[i].first)*(cerc[j].x-points[i].first)+(cerc[j].y-points[i].second)*(cerc[j].y-points[i].second));
                if(dis<dist[j]){dist[j]=dis;}
            }
        }
    }
    sort(dist.begin(),dist.end());
    /*for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<"\n";
    }*/
    for(int i=0;i<Q;i++)
    {
        if(lastscore%2==1)
        {
            lastscore=findscore(hit[i]);
        }else
        {
            lastscore=findscore(hit[i]*2);
        }
        score+=lastscore;
    }
    cout<<score<<"\n";
    return 0;
}
/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
*/
