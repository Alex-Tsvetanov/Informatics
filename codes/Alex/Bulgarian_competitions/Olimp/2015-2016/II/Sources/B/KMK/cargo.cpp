#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, m, p;
	
	cin>>n;
	
	cin>>m;
	
	cin>>p;
	
	int count=1, start[100], end[100];
	for(int i=0; i<m; i++)
	{
		
		count++;
			
		do
		{
			cin>>start[i];
		}
		while(start[i]<1 || start[i]>n);
		
		do
		{
			cin>>end[i];
		}
		while(end[i]<1 || end[i]>n);

	}
	
	int week=0, multiplier=1;
	int ok=0, mixed=0, impossible=0;
	for(int i=0; i<m; i++)
	{
		if(i>=7*multiplier)
		{
			week++;
			multiplier++;
		}
		
		if((start[i]-week*5)>=5 && (start[i]-week*7)<=7 && (end[i]-week*7)<=7 && (end[i]-week*5)>=5)
		{
			mixed++;
		}
		
		if((start[i]-week*1)>=1 && (start[i]-week*5)<=5 && (end[i]-week*5)<=5 && (end[i]-week*1)>=1)
		{
			ok++;
		}
		
		for(int j=0; j<m-1; j++)
		{
			if(fabs(fabs(start[i]-start[j+1])-fabs(end[i]-end[j+1])>(p/2-1-p%2)))
			{
				impossible++;
			}
		}
	
	}
	
	if(mixed>0 && impossible==0)
	{
		cout<<"MIXED";
	}
	
	if(impossible>0)
	{
		cout<<"IMPOSSIBLE";
	}
	
	if(ok==m && impossible==0)
	{
		cout<<"OK";
	}
	
	return 0;
}
