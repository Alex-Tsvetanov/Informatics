#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int obh[n];
    vector<int> rebra[n];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        rebra[a].push_back(b);
    }
    vector<int> ans[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            obh[j]=-1;
        }
        int max_obh=-1;
        queue<int>q;
        q.push(i);
        obh[i]=0;
        int curr;
        int hobh=1;
        while(!q.empty()){
            curr=q.front();
            for(int j=0;j<rebra[curr].size();j++){
                if(obh[rebra[curr][j]]==-1){
                    obh[rebra[curr][j]]=obh[curr]+1;
                    q.push(rebra[curr][j]);
                    max_obh=max(max_obh,obh[curr]+1);
                    hobh++;
                }
            }
            q.pop();
        }
        if(hobh==n){
                ans[max_obh].push_back(i);
                //cout<<i<<" "<<max_obh;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i].size()>0){
            cout<<ans[i].size()<<endl;
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            return 0;
        }
    }
}
/*
8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4
*/
