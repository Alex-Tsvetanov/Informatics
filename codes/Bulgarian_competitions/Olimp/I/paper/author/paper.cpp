#include <iostream>
using namespace std;

long long m,n,i, br;

int main() {
	
	cin>>m>>n;
	br=0;
	i=1;
	while (i<n) {
		br++;
		i=2*i;
	}
	i=1;
	while (i<m) {
		br++;
		i=2*i;
	}
	
	cout<<br<<endl;
	return 0;
}
