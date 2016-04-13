#include<iostream>
using namespace std;

int n,m,p,s,e;
int day[100000];

string status = "OK";

int f(int s, int e){
    int mi=2005;
    int mi_index;
    for(int i=s;i<e;i++){
        if((i+s)%7==0 or (i+s)%7==1){
            continue;
        }
        if(mi > day[i]){
            mi = day[i];
            mi_index = i;
        }
    }
    if(mi<p){
        day[mi_index]++;
        return 1;
    }
    for(int i=s;i<e;i++){
        if(mi > day[i]){
            mi = day[i];
            mi_index = i;
        }
    }
    if(status == "OK") status = "MIXED";
    if(mi<p){
        day[mi_index]++;
        return 2;
    }
    status = "IMPOSSIBLE";
}

int main(){
    cin>>n>>m>>p;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        f(s,e);
    }
    cout<<status<<endl;
    return 0;
}
