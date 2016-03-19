#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	unsigned long k, count=0, arr1[3], arr2[3];
	
	for(int i=0; i<3; i++)
	{
		arr1[i]=0;
		arr2[i]=0;
	}
	
	cin>>k;

	unsigned long m, n;
	if((k+1)%3==0 || k%3==0)
	{
		if((k+1)%3==0)
		{
			m=1;
			arr1[0]=m;
			n=(k+1)/3;
			arr2[0]=n;
		}
			
		if(k%3==0)
		{
			m=k/3;
			arr1[0]=m;
			n=1;
			arr2[0]=n;
		}
			
		count++;
	}
	
	if(k>=9 && (k%3==0 || (k-1)%3==0))
	{
		
		m=floor(sqrt((k+1)/2)); 		
		n=m;
		if(k<(2*(m+1)*m))
		{
			arr1[1]=m;
			arr2[1]=n;
			count++;
		}
	}
		 
	if((k-2)%3==0)
	{
		m=floor(sqrt((k+1)/2))+1;
		arr1[2]=m;
		n=m-1;
		arr2[2]=n;
			
		count++;
	}


	cout<<count<<endl;
			
	for(int i=0; i<3; i++)
	{
		if(arr1[i]!=0 || arr2[i]!=0)
		{
			cout<<arr1[i]<<" "<<arr2[i]<<endl;
		}
	}
	
	
	return 0;
}
