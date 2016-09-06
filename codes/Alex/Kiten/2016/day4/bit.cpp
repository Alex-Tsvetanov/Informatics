#include <iostream>
int LSOne (int S)
{
	return (S & (-S));
}

class BIT {
	int* ft, size;
public:
	BIT(int n)
	{
		size = n;
		ft = new int [n + 1];
		for (int i = 0 ; i < n + 1 ; i ++)
			ft [i] = 0;
	}

	~BIT ()
	{
		delete [] ft;
	}

	int sum(int b)
	{
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	int sum(int a, int b)
	{
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}

	void update (int k, int v)
	{
		for (; k <= size; k += LSOne(k)) ft[k] += v;
	}
};

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	int n;
	std::cin >> n;
	int* arr = new int [n + 5];
    BIT b (n);
	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		std::cin >> a;
		arr [i + 1] = a;
		b.update (i + 1, a);
	}
	int m;
	std::cin >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		char c;
		int a, b_;
		std::cin >> c >> a >> b_;
		if (c == 'u')
		{
			b.update (a, arr [a] - b_);
			arr [a] = b_;
		}
		else if (c == 's')
		{
			std::cout << b.sum (a, b_) << std::endl;
		}
	}
    return 0;
}
