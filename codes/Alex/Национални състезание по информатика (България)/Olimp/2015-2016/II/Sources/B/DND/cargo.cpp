#include<iostream>
#include<algorithm>
using namespace std;
struct prevoz
{
	int s;
	int e;
	bool done;
};
struct comp
{
	bool operator()(prevoz a,prevoz b)
	{
		return a.s<b.s;
	}
};
prevoz *a=new prevoz[1000000];
prevoz *b=new prevoz[1000000];
int main()
{
	int flag=0;
	int br=0;
	int n,m,p;
	cin>>n>>m>>p;
	if(p%2!=0)
	{
		p--;
	}
	p=p/2;
	for(int i=0;i<m;i++)
	{
		cin>>a[i].s>>a[i].e;
	}
	sort(a,a+m,comp());
	prevoz swap;
	for(int i=0;i<m;i++)
	{
		if(a[i].s==a[i+1].s)
		{
			if(a[i].e>a[i+1].e)
			{
				swap=a[i];
				a[i]=a[i+1];
				a[i+1]=swap;
			}
		}
		b[i]=a[i];
	}
	for(int i=a[0].s;i<a[m-1].e;i++)
	{
		if(br>=m-1)
		{
			break;
		}
		int r=i/7;
		if((i-r*i)==6||(i-r*i)==0)
		{
			int ki=br;
			while(a[ki].s==a[ki+1].s)
			{
				a[ki].s++;
				ki++;
			}
		}
		if(a[br].s>a[br].e)
		{
			flag=2;
			break;
		}
		int j=p;
		int k=br;
		a[br].done=true;
				br++;
		j--;
		if(a[k].s==a[k+1].s)
		{
			while(j!=0&&a[k].s==a[k+1].s)
			{
				k++;
				j--;
				a[k].done=true;
						br++;
			}
			while(a[k].s==a[k+1].s)
			{
				if(a[k+1].done==false&&a[k].s==a[k+1].s)
				{
					if((a[k+1].s+1)>a[k+1].e)
					{
						flag=2;
						break;
					}
					else
					{
						k++;
						a[k].s++;
					}
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(a[i].done==false)
		{
			flag=1;
			break;
		}
	}
	if(flag==1||flag==2)
	{	br=0;
		for(int i=b[0].s;i<b[m-1].e;i++)
		{
		if(br>=m-1)
		{
			break;
		}
		int j=p;
		int k=br;
		b[br].done=true;
		br++;
		j--;
		if(b[k].s==b[k+1].s)
		{
			while(j!=0&&b[k].s==b[k+1].s)
			{
				k++;
				j--;
				b[k].done=true;
				br++;
			}
			while(b[k].s==b[k+1].s)
			{
				if(b[k+1].done==false&&b[k].s==b[k+1].s)
				{
					if((b[k+1].s+1)>b[k+1].e)
					{
						flag=2;
						break;
					}
					else
					{
						b[k+1].s++;
					}
				}
			}
		}
		}
	}
	if(flag==2)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	if(flag==1)
	{
		cout<<"MIXED"<<endl;
		return 0;
	}
	if(flag==0)
	{
		cout<<"OK"<<endl;
		return 0;
	}
	return 0;
}
