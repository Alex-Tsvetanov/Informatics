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

public:
	void GenerateCombinationsWithoutRepeatIterative (int n, int k, void (*printPointer) (int*, int) = sample_print)
	{
		print = printPointer;
		arr = new int [k];	
		for (int i = 0; i < k; i++)
			arr [i] = i + 1;
		while (arr [k - 1] < n)
		{
			print (arr, k);

			int t = k - 1;
			while (t != 0 && arr [t] == n - k + t)
				t--;
			arr [t]++;
			for (int i = t + 1; i < k; i++)
				arr [i] = arr [i - 1] + 1;
		}
	}
} combination;

int main ()
{
	int n, k;
	cin >> n >> k;
	combination.GenerateCombinationsWithoutRepeatIterative (n, k);
}
