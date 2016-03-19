#include<iostream>
#include<queue>
#include<vector>

using namespace std;
struct comp
{
   bool operator()(pair<int,int> & l, pair<int,int> & r)
   {
       return l.first <= r.first;
   }
};
priority_queue<pair<int,int>, vector< pair<int,int> >  , comp> q;
int taken[1000000];
int n,m,p;
int main(){
    cin>>n>>m>>p;
    p/=2;
    bool weekend=false;
    int a,b;
    for(int i =1; i<=m;i++){
        cin>>a>>b;
        q.push(make_pair(a,b));
    }
    for(int i = 1; i <=n; i++){

        taken[i]=0;
    }
    while(!q.empty()){
        pair<int,int> pr = q.top();
        q.pop();
        bool done = false;
        int onw = 0;
        for(int i = pr.first;i<=pr.second;i++){
            if(taken[i] < p){
                if(i%6!=0 && i%7!=0){
                    taken[i]++;
                    done = true;
                    break;
                }else if(onw==0){
                    onw=i;
                }
            }
        }
        if(!done && onw!=0){
            taken[onw]++;
            weekend=true;
        }else if(!done){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }

    if(weekend){
        cout<<"MIXED"<<endl;
    }else{
        cout<<"OK"<<endl;
    }
    return 0;

}
/*
100 3 2
4 5
5 6
5 7

*/
