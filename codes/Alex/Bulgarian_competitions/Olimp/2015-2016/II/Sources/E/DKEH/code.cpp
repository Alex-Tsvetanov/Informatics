#include<iostream>
using namespace std;
int main()
{
	char a[1000000];
    long long i,br=0,c,s,f=0,n=0;
	for(i=0;i<1000000;i++)
	{
		br++;
		cin>>a[i];
		if(a[i]=='.')
		break;
	}
	for(i=0-1;i<br-1;i++)
	{
		s=i-1;
		c=i+1;
		if(i=0)
		{
			if(a[i]!=a[c])
			{
			do
        	{
        		f+=1;
        	}while(a[i]!=a[s] && a[i]!=a[c]);
        	}
        	else if(a[i]==a[c])
        	{
			do
		    {
			    f+=2;
		    }while(a[i]=a[c]);
		    }
		    }
		    else if(br==2)
		    {
			f+=1;
		    break;
		    }
		    else
		    {
		    if(a[i]!=a[s] && a[i]!=a[c])
		    {
        	do
        	{
        		f+=1;
        	}while(a[i]!=a[s] && a[i]!=a[c]);
            }
			else if(a[i]==a[s] && a[i]==a[c])
		    {
		    do
		    {
			f+=2;
		    }while(a[i]=a[c]);
		    }
		    }
	        }
            if(br-1>f)cout<<br-1-f<<endl;
			else if(br-1<f) cout<<f-(br-1)<<endl;
			else cout<<"0"<<endl;
    return 0;
}
