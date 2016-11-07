#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int N,M,Q,flag=0;
int xM=0,yM=0;
unsigned long long sum=0;



struct circle
{
    int x;
    int y;
    int r;
};

circle ARR[10001];

int count(int forceR)
{
    int len=0,br=0;
    for(int i=0; i<Q; i++)
    {
        int dx,dy;
        dx=xM-ARR[i].x;
        dy=yM-ARR[i].y;
        len=ceil(sqrt(dx*dx+dy*dy))+ARR[i].r;
        if(len<=forceR) br++;
    }
    return br;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>Q;

    for(int i=0; i<N; i++) cin>>ARR[i].x>>ARR[i].y>>ARR[i].r;
    for(int i=0; i<M; i++) cin>>xM>>yM;

    for(int z=0; z<Q; z++)
    {
        int f;
        cin>>f;
        if(flag)
        {
            flag=0;
            sum+=count(2*f);
            if(count(2*f)%2==0) flag=1;
            continue;
        }
        sum+=count(f);
        if(count(f)%2==0) flag=1;
    }

    cout<<sum<<endl;
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
