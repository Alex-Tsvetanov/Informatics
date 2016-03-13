#include <iostream>
#include <vector>

struct min_max
{
	int min, max;
	min_max (int i, int a)
	{
		min = i;
		max = a;
	}
	void update (int x)
	{
		min = std::min (min, x);
		max = std::max (max, x);
	}
};

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	int n, l, d;
	std::cin >> n >> l >> d;
	int x, a, b;
	std::cin >> x >> a >> b;
	if ((uint64_t)(n + 1) * d < (uint64_t)l)
	{
		std::cout << "-1\n";
		return 0;
	}
	std::vector < min_max > buckets (l / d + 1, min_max (l, 0));
	int remember_to_end = l / d;
	int i = 0;
	for ( ; remember_to_end > 0 and ++i <= n  ; )
	{
		int index_of_bucket = x / d;
		remember_to_end -= (
(index_of_bucket - 1 >= 0 and buckets [index_of_bucket].min - buckets [index_of_bucket - 1].max > d and x - buckets [index_of_bucket - 1].max <= d) +
(index_of_bucket + 1 <= l / d and buckets [index_of_bucket + 1].min - buckets [index_of_bucket].max > d and buckets [index_of_bucket + 1].min - x <= d)
		                   );
		buckets [index_of_bucket].update (x);
		x = (int)((x * (uint64_t)a + b) % (l + 1));
	}
	if (i <= n)
		std::cout << i << "\n";
	else
		std::cout << -1 << "\n";
}
