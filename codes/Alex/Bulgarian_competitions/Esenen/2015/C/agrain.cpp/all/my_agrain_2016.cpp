#include <iostream>

using namespace std;

struct bucket
{
	bucket (int s = 0)
	{
		size = s;
		water = 0;
	}
	int size;
	int water;
	bool add ()
	{
		water ++;
		return water == 1;
	}
};

struct set_bucket
{
	int n;
	int size1, size2;
	bucket* buckets;
	int empty_buckets;
	set_bucket (int l, int d)
	{
		d ++;
		size1 = d / 2;
		size2 = d - d / 2;
		n = 0;
		while (l > 0)
		{
			if (n % 2 == 0)
				l -= size1;
			else if (n % 2 == 1)
				l -= size2;
			n ++;
		}
		empty_buckets = n;
		buckets = new bucket [n];
		for (int i = 0 ; i < n ; i ++)
		{
			if (i % 2 == 0)
				buckets [i] = bucket (size1);
			else if (i % 2 == 1)
				buckets [i] = bucket (size2);
		}
	}
	bool update (int x)
	{
		int a = x / (size1 + size2);
		int b = x % (size1 + size2);
		a *= 2;
		if (b >= size1)
			a ++;
		
		empty_buckets -= buckets [a].add ();
		return (empty_buckets == 0);
	}
};

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, l, d;
	cin >> n >> l >> d;
	int x, a, b;
	cin >> x >> a >> b;
	set_bucket buckets (l, d);
	cout << buckets.n << " " << buckets.size1 << " " << buckets.size2 << "\n";
	for (int i = 0 ; i < n ; i ++)
	{
		if (buckets.update (x))
		{
			cout << i + 1 << "\n";
			return 0;
		}
		cout << x << " -> " << buckets.empty_buckets << "\n";
		x = (x * a + b) % (l + 1);
	}
	cout << "-1\n";
	return 0;
}
