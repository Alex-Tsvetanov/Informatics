//Task: rect
//Author: Pavel Petrov

#include<iostream>
using namespace std;

long long N;
int main (){
int brP,a,b,i,k,Ost;
	cin>>N;
	i=0; brP=0;
	while (true) {
		i++;
		a=3*i+1;
      	if (N<=a) 
       		break;		
		Ost=N-a;
		k=a-i;
		if (Ost%k==0) {
			b=Ost/k+1;
			if (i>b) 
				break;
			brP++;	
		}
	}
	cout<<brP<<endl;
return 0;
}
