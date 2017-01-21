#include <iostream>
using namespace std;
int n;
double c[128][128], ans[128];
int main(){
	cin>>n;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n+1; ++j){
			cin>>c[i][j];
		}
	}
	for (int i=0; i<n; ++i){
		int x;
		for (int j=i; j<n; ++j){
			if (c[j][i]!=0){
				x=j;
				break;
			}
		}
		swap(c[i], c[x]);

		for (int j=i+1; j<n+1; ++j){
			c[i][j] /= c[i][i];
		}c[i][i]=1;

		for (int j=i+1; j<n; ++j){
			for (int k=i+1; k<n+1; ++k){
				c[j][k] -= c[i][k]*c[j][i];
			}
			c[j][i] = 0;
		}
	}

	/*for (int i=0; i<n; ++i){
	  for (int j=0; j<n+1; ++j){
	  cout<<c[i][j]<<" ";
	  }cout<<"\n";
	  }*/

	for (int i=n-1; i>=0; --i){
		ans[i]=c[i][n];
		for (int j=n-1; j>i; --j){
			ans[i]-=c[i][j]*ans[j];
		}
	}

	for (int i=0; i<n; ++i){
		cout<<ans[i]<<" ";
	}cout<"\n";
	return 0;
}

