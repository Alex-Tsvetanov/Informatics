#include <iostream>
#include <algorithm>
using namespace std;

long long x,t,a,b,p[1001][3], br;
int main()
{
    cin >> x;
    a=2;
    while (a*a<=x) {
    	b=1;
    	t=a;
    	while (t<=x) {
    		if (t==x) {
    			br++;
    			p[br][1]=a;
    			p[br][2]=b;
    			break;
			}
			b++;
			t=t*a;
		}
		a++;
	}
	cout<<br<<endl;
    for (int i = br; i>=1; i--) 
        cout<<p[i][1]<<" "<<p[i][2]<<endl;

    return 0;
}
/*


*/
