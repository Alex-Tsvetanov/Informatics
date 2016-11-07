#include <iostream>
using namespace std;
int main ()
{
	int m,n,k,i,c;
	cin>>k;
	if(k%2==0) {
		for(i=0;i<k;i++) {
		c=i*i+3;
		cout<<c<<endl;
		cout<<i<<" "<<i<<endl;}
	}
	else cout<<"0"<<endl;
}
