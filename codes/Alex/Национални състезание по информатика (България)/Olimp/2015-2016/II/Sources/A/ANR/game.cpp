#include <bits/stdc++.h>
using namespace std;

const int N=10002;

class Circle
{
    public:
    int x;
    int y;
    int r;
};
Circle num[N];

pair <int, int> pointsCoo[12];

vector <int> forces;
int arr[N][N];

int arr1[N];

inline double findDistance(int x1, int y1, int x2, int y2, int circleRadius)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+circleRadius;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    int score=0, finalScore=0;
    cin>>n>>m>>q;
    forces.resize(q+3);
    for(int i=1;i<=n;i++)
    {
        cin>>num[i].x>>num[i].y>>num[i].r;
    }

    for(int i=1;i<=m;i++)
    {
        cin>>pointsCoo[i].first>>pointsCoo[i].second;
    }

    for(int i=1;i<=q;i++)
    {
        cin>>forces[i];
    }

    //double distances[m+1][n+1];

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[(int)(findDistance(num[j].x, num[j].y, pointsCoo[i].first, pointsCoo[i].second, num[j].r))+1][i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=q;j++)
        {
            score=0;
            for(int k=forces[j];k>=1;k--)
            {
                score+=arr[k][i];
            }
            if(score%2==0)
            {
                forces[j+1]*=2;
            }
            finalScore+=score;
        }
    }
    cout<<finalScore<<endl;
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



