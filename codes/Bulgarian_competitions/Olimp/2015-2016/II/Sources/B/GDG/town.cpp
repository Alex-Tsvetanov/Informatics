#include<iostream>
#include<queue>
#include<vector>

#define INF 100000000
using namespace std;
int n,a,b;

struct comp
{
   bool operator()(pair<int,int> & l, pair<int,int> & r)
   {
       return l.first >= r.first;
   }
};
vector< vector< pair<int,int> > > v;
int path [200005];
bool done[200005];
void dijkstra(int x){
   //priority_queue < pair<int,int>,
    priority_queue<pair<int,int>, vector< pair<int,int> >  , comp> q;

    q.push(make_pair(x,0));

    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();


        int el = p.first;
        int cur = p.second;

        if(cur == INF)return;
        //cout<<" el is "<<el<<endl;

        done[el] = true;

        if(el == b){
            //cout<<"answer found"<<endl;
            return;
        }

        for(int i = 0; i < v[el].size(); i++){

            int newEl = v[el][i].first;
            int w = v[el][i].second;
            //cout<<" newEl is "<<newEl<<endl;

            if(!done[newEl] && cur + w < path[newEl]){
               // cout<<"updating newEl"<<endl;
                path[newEl] = cur + w;
                q.push(make_pair(newEl,path[newEl]));
            }
        }
    }
}

int main(){

    /// Djikstra (na obraten put slagame duljina 1)

    cin>>n>>a>>b;
    int p,q;

    //INIT
    vector< pair<int,int> >  temp;
    for(int i  = 0 ; i < n + 5; i++){
        v.push_back(temp);
        done[i] = false;
        path[i] = INF;
    }

    while(cin>>p>>q){
       // cout<<"starting "<<p<<" "<<q<<endl;
        v[p].push_back(make_pair(q,0));
        v[q].push_back(make_pair(p,1));
        //cout<<"done "<<p<<" "<<q<<endl;
    }
    dijkstra(a);
    if(path[b]==INF){
        cout<<"X"<<endl;
        return 0;
    }
    cout<<path[b];
    return 0;

}
