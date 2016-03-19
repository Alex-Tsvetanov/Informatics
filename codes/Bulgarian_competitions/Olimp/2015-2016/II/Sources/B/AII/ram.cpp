#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <climits>
#include <limits>
using namespace std;
typedef long long llong;

llong k;

void read()
{
    cin>>k;
}

//fences = n*(m+1) + m*(n+1) = 2*n*m+n+m
inline llong fences(llong n, llong m)
{
    return (m+1ll)*n + (n+1ll)*m;
}

inline llong m(llong n, llong fenceCount)
{
    llong a=fenceCount-n;
    llong b=2ll*n+1ll;
    if(a%b!=0)return -1ll;
    else return a/b;
}

llong simulate(llong heigth, llong width)
{
    llong total=fences(heigth, width);
    for(int x=1, y=1, i=0;;i++)
    {
        if(i%2==0)x++;
        else y++;
        total--;
        if(x>width||y>heigth)break;
    }
    return total;
}

void solve()
{
    vector<pair<llong, llong> > answer;

    llong x=1, y=1, broken=1, total;
    for(;;)
    {
        total=k+broken;
        if(fences(x, y)>=k*64ll)break;

        if(broken%2==1)
        {
            x++;
            llong width=x-1;
            llong heigth=m(width, total);
            if(heigth>=y)answer.push_back(make_pair(heigth, width));
        }
        else
        {
            y++;
            llong heigth=y-1;
            llong width=m(heigth, total);
            if(width>=x)answer.push_back(make_pair(heigth, width));
        }

        broken++;
    }

    sort(answer.begin(), answer.end());
    printf("%d\n", (int)answer.size());
    for(size_t i=0;i<answer.size();i++)
    {
        printf("%lld %lld\n", answer[i].first, answer[i].second);
    }
}

void dumb_solve()
{
    vector<pair<llong, llong> > answer;
    for(llong h=1;h<=1111;h++)
    {
        for(llong w=1;w<=1111;w++)
        {
            if(simulate(h, w)==k)answer.push_back(make_pair(h, w));
        }
    }

    printf("%d\n", (int)answer.size());
    for(size_t i=0;i<answer.size();i++)printf("%lld %lld\n", answer[i].first, answer[i].second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read();
    solve();
    return 0;
}

/*
31278923781

1000000003
*/
