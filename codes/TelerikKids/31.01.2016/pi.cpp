#include <iostream>
#include<iomanp>
#include <random>

using namespace std;

int main ()
{
	double avarage_pi = 0;
	int maxN = 100;
	for (int n = 0 ; n < maxN ; n ++)
	{
		double pi = 0;
		int br = 0;
		std::random_device rd;
		std::mt19937 gen (rd());
		std::uniform_real_distribution<double> X (0, n + 1);
		std::uniform_real_distribution<double> Y (0, n + 1);
		for (int i = 0 ; i < 1000000 * (n + 1) ; i ++)
		{
			double x = X (gen);
			double y = Y (gen);
			double dist = x * x + y * y;
			double radius = n + 1;
			br += (dist <= radius);
		}
		pi = br / 1000000.0f;
		pi *= 4;
		avarage_pi += pi;
		cout <<setprecision (1000)<< pi << " " << avarage_pi / (n + 1) << "\n";
	}
}
