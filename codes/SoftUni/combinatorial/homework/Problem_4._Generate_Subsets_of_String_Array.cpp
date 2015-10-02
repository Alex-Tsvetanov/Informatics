#include <iostream>
#include <algorithm>

using namespace std;

string* out;

struct
{
public:
	static void sample_print (int* arr, int n)
	{
		cout << "(";
		for (int i = 0 ; i < n - 1 ; i ++)
			cout << out [arr [i]] << " ";
		cout << out [arr [n - 1]] << ")" << endl;
	}
private:
	int* arr;
	int* free;
	int for_print;

	void (*print) (int*, int);

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

public:
	void GenerateCombinationsWithoutRepeat (int n, int k, void (*printPointer) (int*, int) = sample_print)
	{
		for_print = k;
		print = printPointer;
		arr = new int [k + 1];
		arr [k] = -1;
		gen_comb_without (n, k - 1);
		delete[] arr;
		print = nullptr;
	}
} combination;

int main ()
{
	int n, k;
	cin >> n;
	cin >> k;
	out = new string [n];
	for (int i = 0 ; i < n ; i ++)
		cin >> out [i];
	combination.GenerateCombinationsWithoutRepeat (n, k);
}
