#include <fstream>

using namespace std;

bool is_not_prime [1<<14]; 
int* primes;
int num_of_primes; 

void eratosten (int n)
{
	for (int i = 2 ; i <= n ; i ++)
		if (!is_not_prime [i])
		{
			num_of_primes ++;
			for (int j = i * 2 ; j <= n ; j += i)
				is_not_prime [j] = true;
		}
	primes = new int [num_of_primes];
	int ind = 0;
	for (int i = 2 ; i <= n ; i ++)
		if (!is_not_prime [i])
			primes [ind ++] = i;
}

const int64_t mod = 1000000007;

int64_t* knapsack;

int main ()
{
	ifstream fin ("scourge.in");
	ofstream fout ("scourge.out");
	int n, k;
	fin >> n >> k;
	eratosten (k - 1);
	
	knapsack = new int64_t [n + 1];
	knapsack [0] = 1;
	for (int i = 0 ; i < num_of_primes ; i ++)
		for (int j = 0 ; j < n + 1 ; j ++)
			if (knapsack [j] > 0)
				if (j + primes [i] < n + 1)
					knapsack [j + primes [i]] = (knapsack [j + primes [i]] + knapsack [j]) % mod;

	fout << knapsack [n] << "\n";
	delete[] primes;
	delete[] knapsack;
}
