#include <iostream>

using namespace std;

int arr [300000];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, q;
	cin >> n >> q;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
	}
	for (int i = 0 ; i < q ; i ++)
	{
		int a, b;
		char op;
		cin >> op;
		cin >> a >> b;
		if (op == '=')
			arr [a] = b;
		else
		{
			for (int j = a + 1 ; j < b ; j ++)
				if (arr [j] > arr [j - 1])
				{

				}
				else
				{
					cout << "0\n";
					goto Break;
				}
			cout << "1\n";
			Break:
			{

			}
		}
	}
}
