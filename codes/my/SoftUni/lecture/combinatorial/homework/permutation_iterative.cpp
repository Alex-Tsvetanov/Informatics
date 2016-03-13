#include <iostream>
#include <algorithm>

using namespace std;

struct
{

private:

	static void sample_print (int* arr, int n)
	{
		for (int i = 0 ; i < n ; i ++)
			cout << arr [i] << " ";
		cout << endl;
	}

	int* arr;
	int* free;
	int for_print;

	void (*print) (int*, int);

public:
	void GeneratePermutations (int n, void (*printPointer) (int*, int) = sample_print)
	{
		unsigned long long N = 0;
		for_print = n;
		print = printPointer;
		arr = new int [n];
		for (int i = 0 ; i < n ; i ++)
			arr [i] = i + 1;
		do
		{
			print (arr, for_print);
			N ++;
		} while (next_permutation (arr, arr + n));
		delete[] arr;
		print = nullptr;
		cout << "Total permutations: " << N << endl;
	}
} combinatrics;

int main ()
{
	int n;
	cin >> n;
	combinatrics.GeneratePermutations (n);
}
