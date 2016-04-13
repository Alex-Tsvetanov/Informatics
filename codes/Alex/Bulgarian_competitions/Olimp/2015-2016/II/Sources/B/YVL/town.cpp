#define INF 2000000
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct k{
    bool price;///=0 ili 1
    int to;
};
vector<k> susedi[200010];
int priceToHere[200010];
bool visited[200010];
queue<int> que;
void Dijkstra(int crnt){
    //cout<<crnt<<": ";
    visited[crnt]=true;
    for(int i=0;i<susedi[crnt].size();i++){
        //cout<<susedi[crnt][i].to<<" ";
        if(priceToHere[crnt]+susedi[crnt][i].price<priceToHere[susedi[crnt][i].to]){
            que.push(susedi[crnt][i].to);
            priceToHere[susedi[crnt][i].to]=priceToHere[crnt]+susedi[crnt][i].price;
        }
    }
    //cout<<"\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin>>n>>a>>b;
    for(int i=0;i<=n;i++){
        priceToHere[i]=INF;
    }
    //cout<<priceToHere[b]<<"!";
    int p, q;
    while(cin>>p>>q){
        k crnt;
        crnt.price=0;
        crnt.to=q;
        susedi[p].push_back(crnt);
        crnt.price=1;
        crnt.to=p;
        susedi[q].push_back(crnt);
    }
    priceToHere[a]=0;
    que.push(a);
    while(!que.empty()){
//        cout<<" size:"<<que.front()<<"\n";
        while(visited[que.front()]){
            que.pop();
            if(que.empty()) break;
        }
//    cout<<"!";
    if(que.empty()) break;
        Dijkstra(que.front());
    }
    if(priceToHere[b]==INF) cout<<"X\n";
    else cout<<priceToHere[b]<<"\n";
    return 0;
}
