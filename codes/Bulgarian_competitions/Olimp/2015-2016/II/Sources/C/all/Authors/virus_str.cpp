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
		s=""; 
		for (i=1; i<=br;i++) {
		s=s+"."; 
		}
		p=1;
		while (p<=N) {
			for  (i=0;i<br;i++) {
				if (s[i]=='.') v[i+1].push_back(p);
			}
			if (s[br-1]=='1') {
				for (i=br-2; i>=0; i--)
					if (s[i]=='.') {
						ii=i;
						break;
					}
				s[ii]='1';
				for (i=ii+1;i<br;i++) s[i]='.';	
			}
			else
			s[br-1]='1';
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

