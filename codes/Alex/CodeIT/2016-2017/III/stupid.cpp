#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream cin ("equations.in");
ofstream cout ("equations.out");

int main ()
{
	cin.tie (nullptr); 
	ios::sync_with_stdio (false);
	int n, m;
	cin >> m >> n;
    {
    	cout << "1\n";
    	for (int i = 0 ; i < n - 1 ; i ++)
    		cout << ((i % 2) + 1)<< " ";
    	cout << (((n - 1) % 2) + 1) << "\n";
    }
	
////	cout << "1\n";
////	for (int i = 0 ; i < n - 1 ; i ++)
////		cout << (2)<< " ";
////	cout << (2) << "\n";
	return 0;
}
