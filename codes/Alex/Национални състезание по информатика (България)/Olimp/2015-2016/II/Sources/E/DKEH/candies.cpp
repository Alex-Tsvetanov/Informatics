#include<iostream>
using namespace std;
int main()
{
	long long a,b,c,i,br=0;
	cin>>a>>b>>c;
	for(i=0;i<300000000;i++)
	{
		if(a==0)break;
			a=a-1;
		br++;
		if(b==0)break;
		b=b-1;
		br++;
		if(c==0)break;
		c=c-1;
	    br++;
		if(b==0)break;
		b=b-1;
		br++;
	}
	cout<<br<<endl;
	return 0;
}
