#include <iostream>
using namespace std;
int main()
{
	int n,br=0,a;
	cin>>n;
	for(a=1;a*a<=n;a++)
	{
	    if((n-a)%(2*a+1)==0 && (n-a)/(2*a)>=a) {br++;cout<<a<<" ";}
	}
	cout<<br<<endl;
	return 0;
}

