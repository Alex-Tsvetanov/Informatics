#include<iostream>
#include<vector>
using namespace std;
int n,a,b;
struct D{
    int dir;
    bool legal;
};
struct leg{
    bool s[200005];
};
vector< D > roads[200005];
int minV=100000000;
void bfs(int point,int v,leg stepped){
    if(point==b){
        if(v<minV){
            minV=v;
            //cout<<v<<endl;
        }
        return;
    }
    for(int i=0;i<roads[point].size();i++){
        if(!stepped.s[roads[point][i].dir]){
            stepped.s[roads[point][i].dir]=1;
            if(roads[point][i].legal){
                bfs(roads[point][i].dir,v,stepped);
            }
            if(!roads[point][i].legal){
                //cout<<point<<" "<<roads[point][i].dir<<endl;
                bfs(roads[point][i].dir,v+1,stepped);
            }
        }
    }

}
leg steppedOn;
int main(){
    cin>>n>>a>>b;

    int fromC=-1,toC=-1,fromB=-2,toB=-2;
    while(true){
        cin>>fromC>>toC;
        if(fromC==fromB && toC==toB){
            break;
        }
        D road1;
        road1.dir=toC;
        road1.legal=1;
        D road2;
        road2.dir=fromC;
        road2.legal=0;
        roads[fromC].push_back(road1);
        roads[toC].push_back(road2);
        fromB=fromC;
        toB=toC;
    }
    steppedOn.s[a]=1;
    bfs(a,0,steppedOn);
    /*cout<<minV<<endl;
    for(int br1=0;br1<5;br1++){
        while(!roads[br1].empty()){
            cout<<roads[br1].back().dir<<" "<<br1<<endl;
            roads[br1].pop_back();
        }
        cout<<endl;
    }*/
    if(minV==100000000){
        cout<<"X"<<endl;
    }else{
        cout<<minV<<endl;
    }

}
