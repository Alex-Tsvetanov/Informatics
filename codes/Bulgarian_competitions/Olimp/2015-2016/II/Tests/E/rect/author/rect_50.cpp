//Task: rect
//Author: Pavel Petrov

#include<iostream>
using namespace std;
long long N;
int main (){
long long brP,i,j;
	cin>>N;
	brP=0;
	for (i=1; i<=N-1; i++){
		for (j=i;j<=N;j++){
			if (i*(j+1)+j*(i+1) == N) {
			brP++; 							// дори се сложи break, след като IF е изпълнен,
											 // тестването показа, че решението пак лови 50%
			}								 // и останалите 50% се губят от време	
		}
	}
	cout<<brP<<endl;
return 0;
}
