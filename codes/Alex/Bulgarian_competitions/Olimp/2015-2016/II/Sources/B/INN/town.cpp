#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int to,value;
    node(int t = 0, int v = 0){
        to = t;
        value = v;
    }
};

int n,a,b,k;
int x,y;
vector<node> v[200000];
bool visited[200000];
int graph[200000];
queue<int> q;


int main (){
    cin>>n>>a>>b;
    while(cin>>x>>y){
        v[x].push_back(node(y,0));
        v[y].push_back(node(x,1));
    }
    q.push(a);
    visited[a] = true;
    while(!q.empty()){
        //cout<<k<<endl;
        k = q.front();
        q.pop();
        if(k == b){
            break;
        }
        for(int i=0;i<v[k].size();i++){
            if(!visited[v[k][i].to]){
                visited[v[k][i].to] = true;
                graph[v[k][i].to] += graph[k] + v[k][i].value;
                q.push(v[k][i].to);
            }
        }
    }
    if(visited[b]){
        cout<<graph[b]<<endl;
    }else{
        cout<<"X"<<endl;
    }
    return 0;
}
