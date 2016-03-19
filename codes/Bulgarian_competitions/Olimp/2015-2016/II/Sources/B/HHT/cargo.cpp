#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
long long s[10000000], e[10000000], abs[10000000], del[10000000];
long long n, m, p, ax, a1=1, a3=1;
void quickSort(int l, int r)
{ 
	int i,j,x;
	i=l-1; 
	for(j=l;j<=r;j++)
	if(abs[j]<=abs[r])
		{
			i++;
			swap(e[i],e[j]);
			swap(s[i],s[j]);
			swap(abs[i],abs[j]);
		}
	else if(abs[j]==abs[r] && s[i]<s[r])
		{
			i++;
			swap(e[i],e[j]);
			swap(s[i],s[j]);
			swap(abs[i],abs[j]);
		}
	if(i==r)i--;
	if(l<i)quickSort(l,i);
	if((i+1)<r)quickSort(i+1,r);
}
int main()
{
	cin>>n>>m>>p;
	ax=p/2;
	for(int i=0;i<m;i++)
	{
		cin>>s[i]>>e[i];
		s[i]--;
		e[i]--;
		abs[i]=e[i]-s[i];
	}
	quickSort(0,m-1);	
	for(int i=0;i<m;i++)
	{
		int q=-1, h=-1;
		for(int j=s[i];j<=e[i];j++)
		{
			if(j%6==0 && del[j]<ax && j!=0)q=j;
			else if(j%5==0 && del[j]<ax && j!=0)q=j;
			if(q!=-1)break;
		}
		for(int j=s[i];j<=e[i];j++)
		{
			if(j==0 && del[j]<ax)h=j;
			else if(j%5!=0 && j%6!=0 && del[j]<ax)h=j;/**/
			if(h!=-1)break;
		}
		if(h!=-1)
		{
			del[h]++;
		}
		else if(h==-1 && q!=-1)
			{
				del[q]++;
				a1=0;
			}
		else a3=0;
		if(a3==0)
		{
			cout<<"IMPOSSIBLE"<<endl;
			break;
		}
	}
	if(a1==0 && a3==1)cout<<"MIXED"<<endl;
	else if(a1==1 && a3==1)cout<<"OK"<<endl;
	
}

