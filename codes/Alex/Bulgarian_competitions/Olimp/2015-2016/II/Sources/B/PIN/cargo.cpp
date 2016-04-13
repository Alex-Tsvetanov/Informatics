#include <bits/stdc++.h>

using namespace std;

struct cmp_int {
	bool operator ()(const int &a, const int &b) const {
		return a>b;
	}
};

int n,m,p,e;
int l[1<<20],r[1<<20];
map < int, vector < int > > v;
map < int, vector < int > >::iterator it;
priority_queue < int, vector < int >, cmp_int > q;

bool is_it_possible() {
	int i,j,cnt;
	while(!q.empty()) q.pop();
	for(i=1;i<=n;i++) {
		if(v.find(i)!=v.end()) for(j=0;j<(int)(v[i].size());j++) q.push(v[i][j]);
		if(!q.empty() && q.top()<i) return false;
		if(q.empty()) {
			it=v.upper_bound(i);
			if(it==v.end()) break;
			i=((*it).first)-1;
			continue;
		}
		cnt=0;
		while(!q.empty() && cnt<e) {
			++cnt;
			q.pop();
		}
	}
	if(q.empty()) return true;
	else return false;
}

bool is_it_ok() {
	int i,j,cnt;
	while(!q.empty()) q.pop();
	for(i=1;i<=n;i++) {
		if(v.find(i)!=v.end()) for(j=0;j<(int)(v[i].size());j++) q.push(v[i][j]);
		if(!q.empty() && q.top()<i) return false;
		if(q.empty()) {
			it=v.upper_bound(i);
			if(it==v.end()) break;
			i=((*it).first)-1;
			continue;
		}
		if(i%7==0 || i%7==6) continue;
		cnt=0;
		while(!q.empty() && cnt<e) {
			++cnt;
			q.pop();
		}
	}
	if(q.empty()) return true;
	else return false;
}

int main() {
	int i;
	
	scanf("%d %d %d", &n, &m, &p);
	e=(p>>1);
	for(i=1;i<=m;i++) {
		scanf("%d %d", &l[i], &r[i]);
		v[l[i]].push_back(r[i]);
	}
	if(is_it_possible()) {
		if(is_it_ok()) {
			printf("OK\n");
		}
		else {
			printf("MIXED\n");
		}
	}
	else {
		printf("IMPOSSIBLE\n");
	}
	
	return 0;
}
/*
100 3 2
4 5
5 6
5 7
*/
