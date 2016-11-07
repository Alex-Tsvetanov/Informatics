#include<iostream>
using namespace std;

int main()
{
	int n,m,p,s[m]e[m];
	cin>>n>>a>>b;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i]>>e[i];
		if(s[i]>7||e[i]>7)
		while(s[i]>7||e[i]>7)
		cin>>s[i]>>e[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		if (s[i]>e[i])
		{
			int change;
			changes=s[i];
			s[i]=e[i];
			e[i]=change;
		}
		if (s[i]>5)
		cout<<MIXED;
		else cout<<OK;
	}
}
