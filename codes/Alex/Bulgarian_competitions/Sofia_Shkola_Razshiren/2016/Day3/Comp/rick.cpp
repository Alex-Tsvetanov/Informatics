#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

map <int, int> code;
//dp for 1 number
vector <vector <int> > dp;

int32_t main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, q, k, ind = 1;
	cin >> n >> q >> k;
	dp.push_back (vector <int> (1, 0));
	for (int i = 0 ; i < n ; i ++)
	{
		int bla;
		cin >> bla;
		if (code [bla] == 0)
		{
			//cout << "new val: " << bla << " -> " << ind << "\n";
			//cout.flush ();
			code [bla] = ind ++;
			//cout << "added sucessful\n"; 
			//cout.flush ();
			dp.push_back (vector <int> (i + 1, 0));
			//cout << "added vector sucessful\n"; 
			//cout.flush ();
		}
		//cout << "iterate for DP\n"; 
		//cout.flush ();
		const int curr_code = code [bla];
		//cout << "before **FOR**: " << dp.size () << " " << curr_code << "\n";
		//cout.flush ();
		for (int j = 1 ; j < (int)dp.size () ; j ++)
			dp [j].push_back (dp [j][dp [j].size () - 1]);
		//cout << "back ++: " << dp.size () << " " << curr_code << "\n";
			//cout.flush ();
		dp [curr_code].back ()/*[dp [curr_code].size () - 1]*/ ++;
	}
	vector <int> to_compute;
	for (int j = 1 ; j < (int)dp.size () ; j ++)
		if (dp [j].back () >= k)
			to_compute.push_back (j);
	
	for (int i = 0 ; i < q ; i ++)
	{
		int l, r, ans = 0;
		cin >> l >> r;
		for (int b : to_compute)
		{
			int br = dp [b][r] - dp [b][l - 1];
			if (br >= k)
				ans ++;
		}
		cout << ans << "\n";
	}
}
