#include <bits/stdc++.h>
using namespace std;

struct Point
{
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    int x, y;
};

vector<pair<Point, int> > circles;
vector<Point> bases;

vector<double> hittable[16];

int N, Q, M;

double getDistance(int a, int b)
{
    return sqrt(double (bases[a].x-circles[b].first.x)*double (bases[a].x-circles[b].first.x) + double (bases[a].y-circles[b].first.y)*double (bases[a].y-circles[b].first.y)) + double (circles[b].second);
}

void calculateHittable()
{
    for (int i=0;i<M;i++)
    {
        for (int j=0;j<N;j++)
            hittable[i].push_back(getDistance(i, j));
        sort(hittable[i].begin(), hittable[i].end());
    }

}

int customFind(double power, int i)
{
    if (power<hittable[i][0])
        return 0;
    int l = 0, r = hittable[i].size();
    while (l<r-1)
    {
        int m = (l+r)/2;
        if (hittable[i][m]<power)
        {
            l = m;
        }
        else
            r = m;
    }
    return l+1;
}

int main()
{
    //ifstream in("zad2test.in");

    int ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>Q;

    for (int i=0;i<N;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        circles.push_back(make_pair(Point(x, y), z));
    }

    for (int i=0;i<M;i++)
    {
        int x, y;
        cin>>x>>y;
        bases.push_back(Point(x, y));
    }

    calculateHittable();

    /*for (int i=0;i<M;i++)
    {
        cout<<i<<": ";
        for (int j=0;j<hittable[i].size();j++)
            cout<<hittable[i][j]<<' ';
        cout<<endl;
    }*/

    int last[16] = {1};

    //cout<<customFind(3, 0)<<endl;

    for (int i=0;i<Q;i++)
    {
        int power;
        cin>>power;

        for (int i=0;i<M;i++)
        {
            int tmpPower = power + (last[i]%2==0)*power;
            int tmp = customFind(tmpPower, i);
            //cout<<tmp<<endl;
            ans+=tmp;
            last[i] = tmp;
        }
    }

    cout<<ans<<endl;


    return 0;
}
