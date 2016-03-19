#include <iostream>
using namespace std;
int main () {
	int a[100000];
	int n,m,p,x,z,obshto=0,chep=0;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++){
		a[i]= 0;
	}
	for(int i=0;i<m;i++){
		cin>>x>>z;
		if(x%6==0&&z%7==0){
			chep=1;
			cout<<"MIXED"<<endl;
		}
		a[x]++;
		a[z]++;
	}
	for(int i=0;i<n;i++){
		if(a[i]>1) obshto+=a[i];
	}
	
		
	
	if(chep==0){
	
	if(obshto<=p) cout<<"OK"<<endl;
	if(obshto>p&&obshto<2*p) cout<<"MIXED"<<endl;
	if(obshto>=2*p) cout<<"IMPOSSIBLE";
}
}

	
	




	

	
	








	


