#include <bits/stdc++.h>
#define endl '\n'

using namespace std; //DO NOT FORGET TO USE LONG LONG!!!

long long k,n,m;
vector < pair < long long, long long > > ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	
	cin>>k;
	for(n=1;true;n++) {
		if(2ll*n*(n+1)+1>k) break;
		if((k+n)%(2ll*n+1)==0) {
			m=(k+n)/(2ll*n+1);
			if(n<m) ans.push_back(make_pair(n,m));
		}
	}
	for(m=1;true;m++) {
		if(2ll*m*m>k-1) break;
		if((k-1+m)%(2ll*m+1)==0) {
			n=(k-1+m)/(2ll*m+1);
			if(n>=m) ans.push_back(make_pair(n,m));
		}
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(i=0;i<(int)(ans.size());i++) {
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	
	return 0;
}
