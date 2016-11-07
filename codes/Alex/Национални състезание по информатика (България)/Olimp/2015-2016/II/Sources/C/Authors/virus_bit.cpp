#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

long long N;
int br;
vector <int> v[50];

void Init(){
string s;
long long p;
int i, j, ii;

	br=0;
	p=1;
	while (p<N) {
		p=p*2;
		br++;
	}
	cout<<br<<endl;
	if (N<=500) {
		p=0;
		while (p<N) {
			for (int i=0; i<br;i++)	{
				int q=(1<<i);
				if ( (p & q) == 0) 
					v[br-i].push_back(p+1);
			}
			p++;
			
		}
		for (i=1; i<=br; i++){
			cout<<v[i].size()<<" ";
			for (j=0; j<v[i].size(); j++)
				cout<<v[i][j]<<" ";
			cout<<endl;	
		}
	}
}

int main() {

	cin>>N;
	Init ();
 	
	return 0;
}

