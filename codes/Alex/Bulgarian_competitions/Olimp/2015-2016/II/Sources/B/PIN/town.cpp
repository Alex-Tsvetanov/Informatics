#include <bits/stdc++.h>

using namespace std;

const int N = 1<<18;

int n,m,a,b;
vector < int > v[N],z[N];
bool used[N];
int dist[N];
queue < int > q,p;

void add_it(int x) {
	int i,curr;
	while(!p.empty()) p.pop();
	p.push(x);
	q.push(x);
	while(!p.empty()) {
		curr=p.front();
		p.pop();
		for(i=0;i<(int)(z[curr].size());i++) {
			if(!used[z[curr][i]]) {
				dist[z[curr][i]]=dist[x];
				used[z[curr][i]]=true;
				q.push(z[curr][i]);
				p.push(z[curr][i]);
			}
		}
	}
}

void bfs() {
	int i,curr;
	dist[a]=0;
	used[a]=true;
	add_it(a);
	while(!q.empty()) {
		curr=q.front();
		q.pop();
		for(i=0;i<(int)(v[curr].size());i++) {
			if(!used[v[curr][i]]) {
				used[v[curr][i]]=true;
				dist[v[curr][i]]=dist[curr]+1;
				add_it(v[curr][i]);
			}
		}
	}
}

int main() {
	int x,y;
	
	scanf("%d %d %d", &n, &a, &b);
	while(scanf("%d %d", &x, &y)==2) {
		++m;
		z[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	if(used[b]) printf("%d\n", dist[b]);
	else printf("X\n");
	
	return 0;
}
