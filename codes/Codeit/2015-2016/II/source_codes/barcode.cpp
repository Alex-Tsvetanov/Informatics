#include <fstream>

using namespace std;

bool matrix [1024][1024];

int main ()
{
	ifstream fin ("barcode.in");
	ofstream fout ("barcode.out");
	int N, M;
	fin >> N >> M;
	for (int i = 0 ; i < N ; i ++)
		for (int j = 0 ; j < M ; j ++)
		{
			char a;
			fin >> a;
			if (i != N - 1)
			{
				if ('.' != a and a != '#')
				{
					fout << "NO!\n";
					return 0;
				}
				
				matrix [i][j] = (a == '#');
			}
			else
			{
				if ('1' <= a and a <= '9')
					matrix [i][j] = true;
				else
				{
					fout << "NO!\n";
					return 0;
				}
			}
		}
	for (int col = 0 ; col < M ; col ++)
	{
		bool is_black_column = (matrix [0][col]);
//		fout << "Column " << col << " is_black_column = " << is_black_column << "\n";
//		fout << "Column: ";
//		for (int row = 1 ; row < N ; row ++)
//			fout << matrix [row][col] << " ";
//		fout << "\n";
		for (int row = 1 ; row < N - 1 ; row ++)
		{
			if (matrix [row][col] != is_black_column)
			{
				fout << "NO\n";
				return 0;
			}
		}
	}
	fout << "BUY\n";
}
