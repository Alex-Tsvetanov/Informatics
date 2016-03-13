#include <iostream>
#include <algorithm>

using namespace std;

struct
{
public:
	static void sample_print (int* arr, int n)
	{
		for (int i = 0 ; i < n ; i ++)
			cout << arr [i] << " ";
		cout << endl;
	}
private:
	int* arr;
	int* free;
	int for_print;

	void (*print) (int*, int);

	void gen_var_without (int n, int k)
	{
		if (-1 == k)
		{
			print (arr, for_print);
			return;
		}
		for (int i = 0 ; i < k ; i ++)
		{
			arr [k] = free [i];
			swap (free [k], free [i]);
			gen_var_with (n, k - 1);
			swap (free [k], free [i]);
			arr [k] = 0;
		}
	}

	void gen_var_with (int n, int k)
	{
		if (-1 == k)
		{
			print (arr, for_print);
			return;
		}
		for (arr [k] = 0 ; arr [k] < n ; arr [k] ++)
		{
			gen_var_with (n, k - 1);
		}
	}

	void gen_comb_without (int n, int k)
	{
		if (-1 == k)
		{
			print (arr, for_print);
			return;
		}
		for (arr [k] = arr [k + 1] + 1 ; arr [k] < n ; arr [k] ++)
		{
			gen_comb_without (n, k - 1);
		}
	}

	void gen_comb_with (int n, int k)
	{
		if (-1 == k)
		{
			print (arr, for_print);
			return;
		}
		for (arr [k] = arr [k + 1] ; arr [k] < n ; arr [k] ++)
		{
			gen_comb_with (n, k - 1);
		}
	}

public:
	void GenerateVariationsWithoutRepeat (int n, int k, void (*printPointer) (int*, int) = sample_print)
	{
		for_print = k;
		print = printPointer;
		arr = new int [k + 1];
		free = new int [n];
		for (int i = 0 ; i < n ; i ++)
			free [i] = i;
		gen_var_without (n, k);
		delete[] arr;
	}
	void GenerateVariationsWithRepeat (int n, int k, void (*printPointer) (int*, int) = sample_print)
	{
		for_print = k;
		print = printPointer;
		arr = new int [k + 1];
		gen_var_with (n, k);
		delete[] arr;
		print = nullptr;
	}
	void GenerateCombinationsWithoutRepeat (int n, int k, void (*printPointer) (int*, int) = sample_print)
	{
		for_print = k;
		print = printPointer;
		arr = new int [k + 1];
		gen_comb_without (n, k);
		delete[] arr;
		print = nullptr;
	}
	void GenerateCombinationsWithRepeat (int n, int k, void (*printPointer) (int*, int) = sample_print)
	{
		for_print = k;
		print = printPointer;
		arr = new int [k + 1];
		free = new int [n];
		for (int i = 0 ; i < n ; i ++)
			free [i] = i;
		gen_comb_with (n, k);
		delete[] arr;
		delete[] free;
		print = nullptr;
	}
	void GeneratePermutations (int n, void (*printPointer) (int*, int) = sample_print)
	{
		for_print = n;
		print = printPointer;
		arr = new int [n + 1];
		do
		{
			print (arr, for_print);
		} while (next_permutation (arr, arr + n));
		delete[] arr;
		print = nullptr;
	}
} combination;

int main ()
{
	int n, k;
	cin >> n >> k;
	combination.GenerateCombinationsWithRepeat (n, k);
}
