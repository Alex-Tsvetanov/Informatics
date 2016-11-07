#include<iostream>
using namespace std;
int main()
{
	int a,a1,b1,c1,br=0,br2=0;
	while (a!='.')
	{
	    cin>>a>>a1>>b1;
	    if(a1==b1)br++;
	    else br2++;
	    cout<<(br+br2)-a<<endl;return 0;
	}


return 0;
}
