#include <iostream>
#include <algorithm>
using namespace std;


int n,m,br,sum;
bool fl;

int main()
{
int i,j,b;
char c;
    cin >> n >> m;
    sum=br=b=0;
    for (int i = 1; i <= n; i++) {
    	b=0;
	    for (int j = 1; j <= m; j++) {
        	cin>>c;
        	if (c=='*') b++;
		}
		if (b==m) 
		br++;
		else
		br=0;
		sum=sum+br;
	}
	
	cout << sum <<endl;	
    return 0;
}
/*


*/
