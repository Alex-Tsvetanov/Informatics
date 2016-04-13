#include<iostream>
using namespace std;
long long N;
int main (){
long long brP,i,j;
	cin>>N;
	brP=0;
	for (i=1; i*i<=N-1; i++){
		for (j=i;j<=N;j++){
			
			if (i*(j+1)+j*(i+1) == N) {
				brP++;
				break;
			}
		}
	}
	cout<<brP<<endl;
return 0;
}