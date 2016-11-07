#include <iostream>
using namespace std;
int main ()
{
	int n,m,p,i,j,s[1000],e[1000],b=0,q=0,d,c;
	cin>>n>>m>>p;
	for(i=0;i<m;i++) cin>>s[i]>>e[i];
		b=p/2;
		q=n/7;
	for(i=0;i<m;i++)
	for(j=1;j<q;j++)
	{
		d=6*j;c=7*j;
		if(((s[i]==d) || (s[i]==c)) || ((e[i]==d) || (e[i]==c))) cout<<"MIXED"<<endl;
		else cout<<"IMPOSSIBLE";
	}
}
