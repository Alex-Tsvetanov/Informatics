#include <iostream>
using namespace std;

struct node{
    int x,y;
    int d;
    node(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }
};

int n,m,t;
node v;
int c = 1;
node ap[50];
bool w;
int ans;

int main (){
    cin>>n>>m>>t;
    ans = n*m;
    cin>>v.x>>v.y;
    ap[0].x = v.x;
    ap[0].y = v.y;
    if(t==2){
        cin>>v.x>>v.y;
        ap[1].x = v.x;
        ap[1].y = v.y;
        c=2;
    }
    for(int i = 0; ap[i].d < t ; i++){

        ap[c].x = ap[i].x + 1;
        ap[c].y = ap[i].y;
        ap[c].d = ap[i].d + 1;
        c++;
        ap[c].x = ap[i].x - 1;
        ap[c].y = ap[i].y;
        ap[c].d = ap[i].d + 1;
        c++;
        ap[c].x = ap[i].x;
        ap[c].y = ap[i].y + 1;
        ap[c].d = ap[i].d + 1;
        c++;
        ap[c].x = ap[i].x;
        ap[c].y = ap[i].y - 1;
        ap[c].d = ap[i].d + 1;
        c++;

    }
    for(int i = 0; i < c; i++){

        w = false;
        for(int j = 0; j < i; j++){
            if(ap[i].x == ap[j].x and ap[i].y == ap[j].y){
                w = true;
                break;
            }
        }
        if(w) continue;
        if(ap[i].x > n or ap[i].x<=0) continue;
        if(ap[i].y > m or ap[i].y<=0) continue;

        ans --;
    }

    cout<<ans<<endl;

    return 0;
}


















