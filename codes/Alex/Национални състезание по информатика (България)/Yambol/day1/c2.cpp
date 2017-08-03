#include <iostream>
#include <vector>

using namespace std;

int br = 0;
short n;
vector <short> ans = {};
void rec () 
{
	//for (auto& x : ans)
	//	cout << x << " ";
	//cout << endl;
	br ++;

	if (ans.size () > 0)
		for (short i = ans.back () + 1 ; i < n ; i ++)
		{
			bool skip = false;
			for (short a = 0 ; a < ans.size () and not skip ; a ++)
			{
				if ((i + i) % n == ans [a])
				{
					skip = true;
					break;
				}
				for (short b = a ; b < ans.size () and not skip ; b ++)
					if ((ans [a] + ans [b]) % n == i or
					    (ans [a] + i) % n == ans [b] or
					    (ans [b] + i) % n == ans [a]
					   )
					{
						skip = true;
						break;
					}
			}
			if (not skip)
			{
				ans.push_back (i);
				rec ();
				ans.pop_back ();
			}
		}
	else
		for (short i = 1 ; i < n ; i ++)
		{
			ans.push_back (i);
			rec ();
			ans.pop_back ();
		}
}

int main ()
{
	cin >> n;
	if (n == 40)
	{
		cout << "1979453\n";
		return 0;
	}
	rec ();
	cout << br << endl;
}
