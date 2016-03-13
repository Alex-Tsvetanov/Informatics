//agrain_slow.cpp
#include <iostream>
//#include <iomanip>

using namespace std;

bool* flowers;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int64_t N, L, D, A, B;
	int64_t X;
	cin >> N >> L >> D >> X >> A >> B;
	flowers = new bool [L + 1];
	for (int64_t i = 0 ; i < L + 1 ; i ++)
		flowers [i] = 0;
	/*
	   cout << "   ";
	   for (int64_t i = 0 ; i < L + 1 ; i ++)
	   cout << setw (2) << i << " ";
	   cout << "\n";
	 */
	for (int64_t k = 0 ; k < N ; k ++)
	{
		flowers [X] = 1;
		/*
		   cout << setw (2) << k + 1 << " ";
		   for (int64_t i = 0 ; i < L + 1 ; i ++)
		   cout << ' ' << flowers [i] << " ";
		   cout << "\n";
		 */
		for (int64_t i = 0 ; i <= L - D ; i ++)
		{
			int64_t old = i;
			for (int64_t j = 0 ; j < D ; j ++)
				if (flowers [i + j] == 1)
					i += j + 1;
			if (old == i)
				goto Break;
		}
		cout << k + 1 << "\n";
		delete[] flowers;
		return 0;
Break:
		{
			
		}
		X = (X * A + B) % (L + 1);
	}
	cout << "-1\n";
	delete[] flowers;
	return 0;
}
