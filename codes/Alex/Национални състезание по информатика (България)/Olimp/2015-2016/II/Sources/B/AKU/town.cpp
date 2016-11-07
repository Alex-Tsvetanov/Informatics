#include <iostream>
using namespace std;
int main()
{
	int n;
	int a;
	int b;
	cin >> n;
	cin >> a;
	cin >> b;
	int arr[4][4];
	for (int p = 0; p < 5; p++)
	{
		for (int q = 0; q < 5; q++)
			cin >> arr[p][q];
	}
	return 0;
}