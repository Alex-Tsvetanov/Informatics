#include <stdlib.h>
#include <random>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

int Get_Random ()
{

	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100000);	 
    return dis (gen);
}

int Get_N ()
{

	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);	 
    return dis (gen);
}

int main ()
{
	system ("g++ stable_sort.cpp -o stable_sort.exe -std=c++11 -Wall");
	for (int testNumber = 1; testNumber <= 100 ; testNumber ++)
	{
		stringstream num;
		num << setfill ('0') << setw (3) << testNumber;
		string file = "tests/quick_sort." + num.str () + ".in";
		ofstream fout;
		fout.open (file.c_str ());
		int n = Get_N ();
		fout << n << "\n";
		for (int i = 0 ; i < n ; i ++)
			fout << Get_Random () << " ";
		fout << "\n";
		fout.close ();
		string command = "./stable_sort.exe < " + file + " > " + file.substr (0, file.size () - 2) + "out";
		system (command.c_str ());
	}
}
