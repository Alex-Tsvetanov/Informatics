#include<iostream>
using namespace std;
int main()
{
	long long int a,b,c,bra=0,brb=0,brc=0;
	cin>>a>>b>>c;
	    a-=1;
	    bra++;
	    b-=1;
	    brb++;
	    b-=1;
	    brc++;

	    int min=a;
	    if(min>b)min=b;
	    if(min>c)min=c;
	    for(int i=0;i<a;i++)
	    {
	        b-=2;
	        brb+=2;
	        a-=1;
	        bra++;
	        c-=1;
	        brc++;
	    }
	    cout<<bra+brb+brc<<endl;

return 0;
}
