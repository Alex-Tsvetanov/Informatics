#include<iostream>
using namespace std;
int main()
{
	bool MIXED, IMPOSIBLE, OK;
	long int n, m, p, S[100000], E[100000];
	do
	{
		cin >> n >> m >> p;
	} while (n<7 || n >= 1000000000 && m<1 || m >= 10000000 && p<1 || p >= 20000000);
	for (int i = 0; i < m; i++)
	{
		cin >> S[i] >> E[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (S[i] % 6 == 0 || S[i] % 7 == 0 || E[i] % 6 == 0 || E[i] % 7 == 0)
		{
			MIXED = true;
		}
		else
			if (S[i] % 2 == 0 || S[i] % 3 == 0 || S[i] % 4 == 0 || S[i] % 5 == 0 || E[i] % 2 == 0 || E[i] % 3 == 0 || E[i] % 4 == 0 || E[i] % 5 == 0)
			{
			OK = true;
			MIXED = false;
			}
			else
			{
				IMPOSIBLE = true;
				OK = false;
				MIXED = false;
			}
	}
	if (MIXED)
	{
		cout << "MIXED\n";
	}
	else
		if (OK)
		{
		cout << "OK\n";
		}
		else
		{
			cout << "IMPOSIBLE\n";
		}
	return 0;
}