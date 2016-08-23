#define ever (;;)
#include <iostream>

using namespace std;

#include "RMQ.h"

int main ()
{
	int arr [] = {1,25,4,4654,2,2463,23,57,86,9};
	int n = sizeof (arr) / sizeof (int);
	int* ST = RMQ.init (arr, n);
	for ever
	{
		int a, b;
		cin >> a >> b;
		cout << RMQ.query (ST, n, a, b);
	}
}
