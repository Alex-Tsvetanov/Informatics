#include<iostream>
using namespace std;
struct dimo
{
	int a;
	int b;	
};
dimo a[10000];
int main()
{
	long long min=1;
	long long max=1000000001;
	long long k;
	cin>>k;
	long long sr;
	long long  m=1;
	long long n;
	long long br;
	long c=0;
	bool flag=false;
	long long maxm=1000000001;
	for(long long i=1;i<1000000001;i++)
	{
		if(i>10&&flag==false)
		{
			break;
		}
		if(i>=maxm)
		{
			break;
		}
		m=i;
		min=1;
		max=1000000001;
	while(min<=max)
	{
		sr=(min+max)/2;
		n=sr;
		if(m>=n)
		{
			br=n*(4*m-(m-1))-m*(n-1);
		}
		else
		{
			br=m*(4*n-(n-1))-n*(m-1);
		}
		if(m>=n)
		{
			br=br-(2*n-1);
		}
		else
		{
			br=br-2*m;
		}
		if(br>k)
		{
			max=sr-1;
		}
		else
		{
			min=sr+1;
		}
		if(br==k)
		{
			if(flag==false)
			{
			maxm=n;
			flag=true;
			}
			a[c].a=i;
			a[c].b=n;
			c++;
		}
	}
	}
	cout<<c<<endl;
	for(int i=0;i<c;i++)
	{
		cout<<a[i].a<<" "<<a[i].b<<endl;
	}
	return 0;
}
