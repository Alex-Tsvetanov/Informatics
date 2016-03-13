#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	vector < int > line = {1, 1};
	for (int i = 3 ; i <= n ; i ++)
	{
		vector < int > copyline = move (line);
		line.push_back (1);
		for (int i = 1 ; i < (int)copyline.size () ; i ++)
			line.push_back (copyline [i] + copyline [i + 1]);
		line.push_back (1);
	}
	cout << line [m - 1] << "\n";
}
