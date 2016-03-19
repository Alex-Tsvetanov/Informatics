#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int n,q,m;

struct point{
    int x,y;
    point(int a, int b){
        x=a;y=b;
    }
};

double dist(point a,point b){
    int c1 = a.x-b.x;
    int c2 = a.y-b.y;
    return sqrt(c1*c1+c2*c2);
}

struct cir{
    int x,y,r;
    cir(){
        x=0;y=0;r=0;
    }
    cir(int a, int b, int c){
        x=a;y=b;r=c;
    }

    bool isIn(cir a){
        if(dist(point(x,y),point(a.x,a.y))+a.r < r)return true;
        return false;
    }
};

vector<cir> cirs;
vector<point> attacks;

int main(){

    cin >> n >> m >> q;

    int res = 0;

    int x,y,r;
    for(int i=0;i<n;i++){
        cin >> x >> y >> r;
        cirs.push_back(cir(x,y,r));
    }

    for(int i=0;i<m;i++){
        cin >> x >> y;
        attacks.push_back(point(x,y));
    }

    int s, prev=-1, cur;
    for(int i=0;i<q;i++){
        cin >> s;
        cur=0;
        if(!(prev&1)){
            s=(s<<1);
        }
        for(int j=0;j<m;j++){
            cir ata(attacks[j].x,attacks[j].y,s);
            for(int k=0;k<n;k++){
                if(ata.isIn(cirs[k]))cur++;
            }
        }
        prev=cur;
        res+=cur;
    }

    cout << res << endl;

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

4 2 3
7 -7 5
0 0 200
-2 0 2
-6 -4 1
4 4
-7 -4
30 2 3
*/
