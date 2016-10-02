#include <iostream>
#include <string>

using namespace std;

int rec (int index, int n, int k, int* digits, string seq, string& output)
{
	if (k <= 0)
	{
		return k;
	}

	if (index == n)
	{
		k --;
		if (k == 0)
		{
			for (int i = 0; i < n; i++)
			{
				output [i] = (char)(digits [i] + '0');
			}
		}
		return k;
	}

	if (index == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			digits [0] = i;
			k = rec (1, n, k, digits, seq, output);
		}

		return k;
	}

	if (seq [index - 1] == '<')
	{
		int digit = ((digits [index - 1] == 0) ? 10 : digits [index - 1]);
		for (int i = 1 ; i < digit ; i ++)
		{
			digits [index] = i;
			k = rec (index + 1, n, k, digits, seq, output);
		}

		return k;
	}

	if (seq [index - 1] == '>')
	{
		int digit = digits [index - 1];
		if (digit == 0)
		{
			return k;
		}

		digits [index] = 0;
		k = rec (index + 1, n, k, digits, seq, output);

		for (int i = digit + 1 ; i < 10 ; i ++)
		{
			digits [index] = i;
			k = rec (index + 1, n, k, digits, seq, output);
		}

		return k;
	}

	if (seq [index - 1] == '=')
	{
		digits [index] = digits [index - 1];
		return rec (index + 1, n, k, digits, seq, output);
	}
}

int digits [25];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	string sequance;
	cin >> sequance;
	int k;
	cin >> k;

	string output (n, ' ');
	rec (0, n, k, digits, sequance, output);

	cout << output << "\n";
}
