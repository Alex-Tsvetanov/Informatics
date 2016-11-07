#include <fstream>
#include <vector>

using namespace std;

ifstream cin ("brackets.in");
ofstream cout ("brackets.out");

const uint64_t mod = 1000000007;

/*constexpr*/ uint64_t fact (int64_t k)
{
	return ((k <= 1)?(1):(fact (k - 1) * k)%mod);
}
/*constexpr*/ uint64_t catalan (uint64_t k)
{
	return ((k <= 1)?(1):(((4*k-2) * catalan (k - 1) / (k+1))%mod));
}
uint64_t a [10];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int k;
		cin >> k;
		uint64_t sum = 0;
		for (int j = 0 ; j < k ; j ++)
		{
			cin >> a [j];
			sum += a [j];
		}
		uint64_t res = fact (sum);
		uint64_t znam = 1;
		for (int i = 0 ; i < k ; i ++)
		{
			znam *= fact (a [i]);
			znam %= mod;
		}
	//	cout << res << " / " << znam << endl;
		res /= ((znam == 0)?mod:znam);
	//	cout << res << endl;
	//	cout << "C(" << sum << ") = "<< catalan (sum);
		res *= catalan (sum);
		cout << res % mod << endl;
	}
}
