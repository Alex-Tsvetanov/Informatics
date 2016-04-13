#include<iostream>
using namespace std;
bool pole[1010][1010];
int pos[14];
int main(){
    int n, m, t, sz, x, y;
    cin>>n>>m>>t;
    for(sz=0;cin>>pos[sz];sz++){
    }
    for(y=pos[0]+t;y>=pos[0];y--){
        if(y<1||y>n) continue;
        for(x=pos[1]-(pos[0]+t-y);x<=pos[1]+(pos[0]+t-y);x++){
            if(x<1||x>m) continue;
            pole[y-1][x-1]=true;
        }
    }
    for(;y>=pos[0]-t;y--){
        if(y<1||y>n) continue;
        for(x=pos[1]-t+(pos[0]-y);x<=pos[1]+t-(pos[0]-y);x++){
            if(x<1||x>m) continue;
            pole[y-1][x-1]=true;
        }
    }
    if(sz!=2){
        for(y=pos[2]+t;y>=pos[2];y--){
        if(y<1||y>n) continue;
        for(x=pos[3]-(pos[2]+t-y);x<=pos[3]+(pos[2]+t-y);x++){
            if(x<1||x>m) continue;
            pole[y-1][x-1]=true;
        }
        }
        for(;y>=pos[2]-t;y--){
            if(y<1||y>n) continue;
            for(x=pos[3]-t+(pos[2]-y);x<=pos[3]+t-(pos[2]-y);x++){
                if(x<1||x>m) continue;
                pole[y-1][x-1]=true;
            }
        }
    }
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pole[i][j]) res++;
        }
    }
    cout<<(n*m)-res<<"\n";
    return 0;
}
