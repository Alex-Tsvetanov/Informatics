#include <iostream>
using namespace std;
int main(){
	long int A,B,C,i=0,broitrvaz=0;
	cin>>A>>B;
	long int m,n,p[A+1],q[A+1];
	for(i=0;i<A;i++){
		p[i+1]=0;
	}
	for(i=0;i<B;i++){
		cin>>m>>n;
		p[m]++;
		p[n]++;
	}
	cin>>C;
	for(i=0;i<A;i++){
		if(p[i+1]>=C){
			broitrvaz++;
			q[i]=i+1;
			q[i+1]='\0';
		}
	}
	if(broitrvaz>0){
		cout<<broitrvaz<<"\n";
		for(i=0;i<A;i++){
			if(q[i]>0 and q[i]<A+1){
				cout<<q[i]<<" ";
			}
		}
	}
	return 0;
}
