#include <iostream>

using namespace std;

int64_t a, b, c, d;

int main ()
{
	uint64_t R, C;
	cin >> a >> b >> c >> d >> R >> C;
	for (uint64_t i = 0 ; i < R * C ; i ++)
	{
		if (i == 0)
			cout << a;
		else if (i == 1)
			cout << b;
		else if (i == 2)
			cout << c;
		else if (i == 3)
			cout << d;
		else
		{
			int64_t s = a + b + c + d;
			a = b;
			b = c;
			c = d;
			d = s;
			cout << d;
		}
		if (i > 0 and (i + 1) % C == 0)
			cout << endl;
		else
			cout << " ";
	}
}
