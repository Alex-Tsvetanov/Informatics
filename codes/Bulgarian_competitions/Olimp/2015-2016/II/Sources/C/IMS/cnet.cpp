#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<long long> susedi[3001];
queue<long long> opa6ka;

long long used[3001];
long long vurhove,rebra;
long long na4alni[3001],broi;
long long minn=-1,otVruh[3001];
bool imaLiRe6enie[3001];

long long bfs(long long start){
    long long br,dulzina,vruh;
    opa6ka.push(start);
    while(!opa6ka.empty()){
        vruh=opa6ka.front();
        opa6ka.pop();
        dulzina=susedi[vruh].size();
        for(br=0;br<dulzina;br++){
            if(!used[susedi[vruh][br]] and susedi[vruh][br]!=start){
                opa6ka.push(susedi[vruh][br]);
                used[susedi[vruh][br]]=used[vruh]+1;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long br,a,b;
    cin>>vurhove>>rebra;
    for(br=0;br<rebra;br++){
        cin>>a>>b;
        susedi[a].push_back(b);
    }
    for(br=0;br<vurhove;br++){
        bfs(br);
        bool re6enieLiE=true;
        long long maxx=-1;
        for(long long i=0;i<vurhove;i++){
            if(used[i]==0 and i!=br){
                re6enieLiE=false;
            }
            if(used[i]>maxx)
                maxx=used[i];
            used[i]=0;
        }
        if(re6enieLiE){
            if(minn==-1 or maxx<minn){
                minn=maxx;
            }
        }
        imaLiRe6enie[br]=re6enieLiE;
        otVruh[br]=maxx;
    }
    long long pro=vurhove/10;
    for(br=0;br<vurhove;br++){
        if(otVruh[br]==minn and imaLiRe6enie[br]){
            na4alni[broi]=br;
            broi++;
            if(broi>pro and vurhove>500)
                br=vurhove;
        }
    }

    cout<<broi<<"\n";
    for(br=0;br<broi;br++){
        cout<<na4alni[br];
        if(br+1<broi)
            cout<<" ";
    }
    cout<<"\n";
    return 0;
}
