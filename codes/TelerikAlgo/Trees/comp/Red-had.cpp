#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

using my_struct = pair <int, pair <int, int> >;

int* weight;
vector <int>* ln;
stack <my_struct> Stack;


int main()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);

	int n;
	cin >> n;
	
	weight = new int [n];
	ln = new vector <int> [n];

	for(int i = 0 ; i < n ; i ++)
		cin >> weight [i];

	for(int i = 0; i < n - 1 ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		ln [a].push_back (b);
		ln [b].push_back (a);
	}
	int ans = -(1<<30);
	for(int i = 0 ; i < n ; i ++)
	{
		Stack.push ({i, {-1, 0}});
		while(!Stack.empty ())
		{
			auto f = Stack.top ();
			Stack.pop ();
			f.second.second += weight [f.first];
			bool b = false;
			for (auto &x : ln [f.first])
			{
				if(x != f.second.first)
				{
					Stack.push ({x, {f.first, f.second.second}});
					b = true;
				}
			}
			if (!b)
				ans = max (best, f.second.second);
		}
	}
	cout << ans << "\n";
}

