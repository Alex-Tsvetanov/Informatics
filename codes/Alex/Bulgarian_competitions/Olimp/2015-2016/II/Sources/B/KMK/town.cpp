#include <iostream>
#include <math.h>
using namespace std; 

int main()
{
	unsigned long n, a, b;
				
	cin>>n;
	
	cin>>a;

	cin>>b;
	
	unsigned long m=n;
	
	unsigned long p, q;
	unsigned long start[50], end[50];
	for(int i=0; i<m; i++)
	{
		cin>>p;
		start[i]=p;
		
		cin>>q;
		end[i]=q;
	}
	
	unsigned long error=0, moves=0, ending=0;
	unsigned long count=0, changes=0, min=100, shortest=0; 
	while(ending!=1)
	{
		for(int i=0; i<n; i++)
		{
			if(fabs(b-end[i])<=min)
			{
				shortest=i;
			}
			
			if(start[i]==a)
			{
				a=end[i];
				moves++;
				start[i]=0;
				changes++;
			}
			count++;
			if(count==n)
			{
				if(changes>0)
				{
					a=start[shortest];
					error++;
				}
			}
			
			if(a==b)
			{
				ending=1;
			}
		}
		changes=0;
		if(moves==0)
		{
			ending=1;
		}
	}
	
	
	if(a==b)
	{
		cout<<error;
	}
	
	if(moves==0)
	{
		cout<<"X";
	}
	return 0;
}
