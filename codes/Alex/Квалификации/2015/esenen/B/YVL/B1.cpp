#include<iostream>
#include<cmath>
using namespace std;
struct point{
    int x, y;
};
double cp(point a, point b, point c){
    return ((a.x-b.x)*(a.y+b.y)+(b.x-c.x)*(b.y+c.y)+(c.x-a.x)*(c.y+a.y))/2.0;
}
double bestS;
int bestN, bestV, crntN;
point figure[105];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    crntN=2;
    int n;
    cin>>n;
    bestS=0.0;
    bestN=1;
    bestV=n;
    cin>>figure[0].x>>figure[0].y>>figure[1].x>>figure[1].y;
    for(int i=2;i<n;i++){
        cin>>figure[i].x>>figure[i].y;
        bestS+=fabs(cp(figure[0], figure[i-1], figure[i]));
    }
    cin>>n;
    while(n>0){
        double res=0.0;
        cin>>figure[0].x>>figure[0].y>>figure[1].x>>figure[1].y;
        for(int i=2;i<n;i++){
            cin>>figure[i].x>>figure[i].y;
            res+=fabs(cp(figure[0], figure[i-1], figure[i]));
        }
        if(bestS>res){
            bestS=res;
            bestN=crntN;
            bestV=n;
        }
        if(bestS==res){
            if(bestV>n){
                bestS=res;
                bestN=crntN;
                bestV=n;
            }
        }
        cin>>n;
        crntN++;
    }
    cout<<bestN<<"\n";
    return 0;
}
