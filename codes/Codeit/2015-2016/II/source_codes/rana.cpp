#include <fstream>
#include <string>
#include <map>

using namespace std;

map < char, int > letters;

int main ()
{
	ifstream fin ("rana.in");
	ofstream fout ("rana.out");
	int n;
	fin >> n;
	string a;
	for (int i = 0 ; i < n ; i ++)
	{
		fin >> a;
		for (int i = 0 ; i < (int)a.size () ; i ++)
			letters [a [i]] ++;
	}
	char max = ' ';
	letters [' '] = 0;
	for (auto& x : letters)
		if (x.second > letters [max])
		{
			max = x.first;
		}
	fout << max << "\n";
}
