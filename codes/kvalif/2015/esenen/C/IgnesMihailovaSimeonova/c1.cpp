#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<long long> susedi[1000];
queue<long long> opa6ka;
bool used[1000];

void bfs(long long vruh){
    used[vruh]=true;
    opa6ka.push(vruh);
    while(!opa6ka.empty()){
        vruh=opa6ka.front();
        opa6ka.pop();
        for(long long br=0;br<susedi[vruh].size();br++){
            if(!used[susedi[vruh][br]]){
                used[susedi[vruh][br]]=true;
                opa6ka.push(susedi[vruh][br]);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    long long vurhove,rebra,a,b,br,svurzani=0;
    cin>>vurhove>>rebra;
    for(br=0;br<rebra;br++){
        cin>>a>>b;
        susedi[a-1].push_back(b-1);
        susedi[b-1].push_back(a-1);
    }
    bool imaLiOste=true;
    while(imaLiOste){
        imaLiOste=false;
        for(br=0;br<vurhove;br++){
            if(!used[br]){
                imaLiOste=true;
                svurzani++;
                bfs(br);
                used[br]=true;
            }
        }
    }
    cout<<svurzani<<"\n";
    return 0;
}
