#include <fstream>
#include <random>

int main ()
{
	std::ofstream cout ("in");

	std::random_device rd;
    std::mt19937 gen (rd ());
    std::uniform_int_distribution<> dis (1, 500000);
	
	int n = dis (gen);
	cout << n << "\n";
	for (int i = 0 ; i < n ; i ++)
	{
		cout << dis (gen) << " " << dis (gen) << "\n";
	}
	cout.flush ();
}
