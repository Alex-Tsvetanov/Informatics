#include<iostream>
#include<vector>
#define MAXPQ 400000
#define MAXN 10000
using namespace std;
int k[MAXN][MAXN];
int n, a, b, x, y, br=0, min_br=MAXN;
bool used[MAXN];
void dfs (int v){
    //cout<<"v= "<<v<<" ";
    if(v==b) {return;}used[v]=1;
	for(int i=0; i<=n; i++){
		if(used[i]==0 && k[v][i]!=0) {
			//cout<<"i= "<<i<<"  "<<k[v][i]<<endl;
			if(k[v][i]<0){
				br++;
				//cout<<"pri dfs("<<i<<") br= "<<br<<endl;
				dfs(i);
				//used[i]=0;
			}
			else if(k[v][i]>0) {
                //cout<<"pri dfs("<<i<<") br= "<<br<<endl;
                dfs(i);
                //used[i]=0;
            }
            //cout<<"brr= "<<br<<"  min_br="<<min_br<<endl;
			if(br<min_br && br!=0) min_br=br;
			br=0;
		}
	}
}
int main(){
	cin>>n>>a>>b;
	for(int i=0; cin>>x>>y; i++){
		k[x][y]=1;
		k[y][x]=-1;
	}
	dfs(a);
	if(used[a]==0) cout<<"X"<<endl;
	else cout<<min_br<<endl;
	return 0;
}
