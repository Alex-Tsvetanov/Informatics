#include<iostream>
using namespace std;
int main(){
	long int N,i=0,naimalkochslo=1000001,naigolqmochslo=-1,ngchi=0,nmchi=0;
	cin>>N;
	long int a[20000];
	for(i=0;i<N;i++){
		cin>>a[i];
	}
	for(i=0;i<N;i++){
		if(a[i]<naimalkochslo){
			naimalkochslo=a[i];
			nmchi=i;
		}
		if(a[i]>=naigolqmochslo){
			naigolqmochslo=a[i];
			ngchi=i;
		}
	}
cout<<nmchi+1<<" "<<ngchi+1;
return 0;
}

