#include <iostream>
#include <random>

using namespace std;

int main ()
{
	size_t SIZE;
	cin >> SIZE;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 1<<25);
	cout << SIZE << "\n";
	for (size_t i = 0 ; i < SIZE ; i ++)
		cout << dis (gen) << " ";
	cout << "\n";

}
