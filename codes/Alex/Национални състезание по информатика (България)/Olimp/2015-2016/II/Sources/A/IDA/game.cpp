#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

struct kryg{
long long x,y,r;
};

struct point{
long long x,y;
};

double dist(long long X1, long long Y1, long long X2, long long Y2){
double d=0;
    d=sqrt((double(X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1)));
return d;
}



long long n,m,q,ans=0;
long long str[10005],strength=0,pos=0;
kryg a[10005];
point p[50];
vector < double > v[50];


int main(){
cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].r);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }


    for(int i=1;i<=q;i++){
        scanf("%lld", &str[i]);
    }

    /// m - точки    p[].x p[].y
    /// n - кръгове  a[].x a[].y a[].r

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
          v[i].push_back((double(dist(p[i].x,p[i].y,a[j].x,a[j].y)+a[j].r)));
        }
    }
/// SORT !!!!
    for(int i=1;i<=m;i++){
        sort(v[i].begin(),v[i].end());
    }
/// SORT !!!!

    str[0]=1;
    for(int i=1;i<=q;i++){
        strength=str[i];
        if(str[i-1]%2==0)strength=strength*2;

        for(int j=1;j<=m;j++){
            pos=lower_bound(v[j].begin(),v[j].end(),strength)-v[j].begin();

            if(v[j][pos]==strength){
                ans=ans+pos+1;
            }
            else
                ans=ans+pos;

        }
    }
cout<<ans<<endl;

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
