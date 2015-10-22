#include <iostream>

using namespace std;

const size_t maxn = 1000;

pair <int, int> dp [maxn][maxn];
int table [maxn][maxn];

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < n ; j ++)
			cin >> table [i][j];
	dp [0][0] = {0, 0};
	for (int i = 1 ; i < n ; i ++)
		if (table [
	for (int i = 1 ; i < n - 1 ; i ++)
		for (int j = 1 ; j < n - 1 ; j ++)
			dp [i][j] = 
}
