#include <iostream>
#include <vector>
using namespace std;

size_t size = 400000000;
vector<int> days(size);
short stat=0; 
int checked = 0;

bool place(int k, int r) {
	while(1<2) {
		for(int i=k;i<=r;i++) {
			if(days[i] > 0) {
				if((i%7!=0&&i%7!=6)&&(checked == 0)) {
					days[i]--;
					return 0;
					break;
				}
				else if((i%7==0||i%7==6)&&(checked == 1)) {
					days[i]--;
					if(stat==0) stat=1;
					return 0;
					break;
				}
			}
		}
		checked++;
		if(checked == 2) {
			stat = 2;
			return 0;
			break;
		}
	}
}

int main() {
	int n,m,p,j=0,k,r;
	cin>>n>>m>>p;
	j=n;
	for(int i=0;i<=n/2;i++) {
		days[i] = p/2;
		days[j] = p/2;
		j--;
	}
	for(int i=0;i<m;i++) {
		cin>>k>>r;
		if(stat!=2) place(k,r);
		checked = 0;
	}
	if(stat==0) cout<<"OK"<<endl;
	else if(stat==1) cout<<"MIXED"<<endl;
	else if(stat==2) cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
