#include <fstream>

using namespace std;

const int64_t mod = 1e9 + 7;

int main ()
{
	ifstream fin ("robots.in");
	ofstream fout ("robots.out");
	int n;
	fin >> n;
	int64_t ans = n - 1;
	for (int i = 0 ; i < n ; i ++)
		ans = (ans * 2) % mod;
	
	fout << ans << "\n";
}
