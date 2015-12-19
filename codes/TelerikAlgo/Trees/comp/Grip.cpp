#include <iostream>
#include <vector>

using namespace std;

vector<int> ln [100000];

int main ()
{
	cin.tie(nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0 ; i < n - 1; i ++)
	{
		int x;
		cin >> x;
		ln [i].push_back (x);
		ln [x].push_back (i);
	}
	int q;
	cin >> q;
	for (int i = 0 ; i < q ; i ++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)
			cout << "You are there";
		else
		{
			bool x = false;
			for (auto& x1 : ln [a])
				if (x1 == b)
				{
					cout << "Directly";
					x = true;
					break;
				}
			if (x) continue;
			for (auto& x1 : ln [b])
				if (x1 == a)
				{
					cout << "Directly";
					x = true;
					break;
				}
			if (x) continue;
			
			for (auto& x1 : ln [a])
				for (auto& x2 : ln [x1])
					if (x2 == b)
					{
						cout << "Through " << x1;
						goto Break;
					}
			for (auto& x1 : ln [b])
				for (auto& x2 : ln [x1])
					if (x2 == a)
					{
						cout << "Through " << x1;
						goto Break;
					}
			Break:
			{

			}
		}
		cout << "\n";
	}
}
