#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#define int uint64_t

using namespace std;

string binary (int a)
{
	string ans;
	while (a > 0)
	{
		ans += (char)(a & 1) + '0';
		a >>= 1;
	}
	while (ans.size () == 0)
		ans += "0";
	reverse (begin (ans), end (ans));
	return ans;
}

int reverseBits(int v)
{
	int s = sizeof(v) * 8; // bit size; must be power of 2 
	int mask = ~0;         
	while ((s >>= 1) > 0) 
	{
	  mask ^= (mask << s);
	  v = ((v >> s) & mask) | ((v << s) & ~mask);
	}
	return v;
}
/*
int reverseBits(int num)
{
    int  NO_OF_BITS = sizeof(num) * 8;
    int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
    }
    return reverse_num;
}*/

int32_t main ()
{
	cout << sizeof (int) << std::endl;
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int x, y;
	cin >> x >> y;

	string x_2, y_2;
	x_2 = binary (x);
	y_2 = binary (y);

	if (x_2.size () == y_2.size ())
	{
		int maxx = (1 <<( x_2.size () - (x_2.size () >> 1) )) - 1;
		int x1 = x, y1 = y;
		x1 >>= x_2.size () / 2;
		y1 >>= y_2.size () / 2;
		//loop from x to y
		for (int i = x1 ; i <= y1 ; i ++)
		{
			//cout << "\t" << setw (64) << binary (i << (x_2.size () / 2)) << std::endl;
			//cout << "\t" << setw (64) << binary (reverseBits (i >> (x_2.size () & 1))) << std::endl;
			//cout << "\t" << setw (64) << binary (maxx) << " " << maxx << std::endl;
			//cout << "\t" << setw (64) << binary (maxx - x1) << " " << maxx - x1 << std::endl;
			//cout << "\t" << setw (64) << binary ((maxx - x1) << 1) << " " << ((maxx - x1) << 1) << std::endl;
			//cout << "\t" << setw (64) << binary ((((maxx - x1) << 1) xor x)) << std::endl;
			//cout << "\t" << setw (64) << binary ((((maxx - x1) << 1) xor x1) xor maxx) << std::endl;
			int tmp = ((((maxx - i) << 1) xor i) xor maxx) - i;
			//(i << (x_2.size () / 2)) xor (reverseBits (i >> (x_2.size () & 1)));
			cout << binary (i) << " " << binary (tmp) << std::endl;
		}
	}

}
