#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector < int >* posOfChar = new vector < int > [26];
vector < int >* tmp       = new vector < int > [26];

int main ()
{
	ifstream fin ("bullcode.in");
	ofstream fout ("bullcode.out");
	int N, K;
	fin >> N >> K;
	string P;
	fin >> P;
	string C;
	fin >> C;
	for (int j = 0 ; j < (int)P.size () ; j ++)
		posOfChar [P [j] - 'a'].push_back (j);
	for (int i = 0 ; i < K ; i ++)
	{
		vector <int>* tmp2;
		for (int j = 0 ; j < 26 ; j ++)
		{
			tmp [C [j] - 'a'] = move (posOfChar [j]);
		}
		tmp2 = tmp;
		tmp = posOfChar;
		posOfChar = tmp2;
	}
	for (int i = 0 ; i < 26 ; i ++)
		for (auto& x : posOfChar [i])
			P [x] = i + 'a';
	fout << P << "\n";
}
