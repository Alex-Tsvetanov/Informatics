#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n,a[1001];
vector <pair <int,int> > p;
pair <int,int> pp; 

void Resh () {
int i,j,k,m;

	for ( m = 1;m<=n; m++) {
	    if (a[m] == m)  continue;
	
	    j = 0;
	    for ( i = m + 1; i<=n; i++) {
	        if (a[i] == m)  j = i;
		}
	
	    while (j > m ){
	        if (a[j - 1] != j) {
//	        	cout<<j-1<<" "<<j<<endl;
				pp=make_pair(j-1,j);
				p.push_back(pp);
	            swap(a[j - 1], a[j]);
	            j--;
	        }
	        else {
	            k = j - 1;
	            while ((k >= m) && (a[k] == k + 1)) k--;
	
	            if (k < m) {
	                for ( i = j - 1; i>=m; i--) {
//	                	cout<<i<<" "<<i+1<<endl;
						pp=make_pair(i,i+1);
						p.push_back(pp);
	            		swap(a[i], a[i+1]); 
					}
	                j = m;
	            }
	            else {
	                for ( i = k;i<=j-1;i++) {
//	                	cout<<i<<" "<<i+1<<endl;
						pp=make_pair(i,i+1);
						p.push_back(pp);
	            		swap(a[i], a[i+1]); 
					}
	                j--;
	            }
	        }
	    }
	}	
}

int main() {
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	Resh();
	cout<<p.size()<<endl;
	for (int i=0;i<p.size();i++)
		cout<<p[i].first<<" "<<p[i].second<<endl;
	
	return 0;
}

