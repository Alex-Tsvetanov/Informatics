#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	vector < int > line = {1, 1};
	cout << "1\n1 1\n";
	for (int i = 2 ; i <= n ; i ++)
	{
		vector < int > copyline = move (line);
		line.push_back (1);
		for (int i = 1 ; i < (int)copyline.size () ; i ++)
			line.push_back (copyline [i] + copyline [i - 1]);
		line.push_back (1);
		for (auto& x : line)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
}
