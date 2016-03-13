#include <fstream>

using namespace std;

ifstream cin ("dragon.in");
ofstream cout ("dragon.out");

int main ()
{
	int Li, Di, Ld, Dd;
	cin >> Li >> Di >> Ld >> Dd;
	for (int i = 0 ; true ; i ++)
	{
		Li -= Dd;
		Ld -= Di;
		if (Li <= 0 and Ld > 0)
		{
			cout << "Failure\n";
			return 0;
		}
		if (Li <= 0 and Ld <= 0)
		{
			cout << "Failure\n";
			return 0;
		}
		if (Li > 0 and Ld <= 0)
		{
			cout << "Justice\n";
			return 0;
		}
	}
}
