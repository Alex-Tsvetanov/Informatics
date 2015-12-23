#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ln [100000];

int preProcess [100000][19];
vector <int> A;

void Euler_tour (int v, int prev = -1)
{
	A.push_back (v);
	for (auto& x : ln [v])
	{
		if (x != prev)
		{
			Euler_tour (x, v);
			A.push_back (v);
		}
	}
}

void init ()
{
	Euler_tour (0);
	for (auto& x : A)
		cout << x << " ";
	cout << endl << "\n\n\n";
	unsigned N = A.size ();
	unsigned i, j;
	for (i = 0 ; i < N ; i ++)
		preProcess [i][0] = i;
	for (j = 1 ; (uint64_t)((uint64_t)(1) << j) <= N ; j ++)
		for (i = 0 ; i + (1 << j) - 1 < N ; i ++)
			preProcess [i][j] = 
				(
				 A [preProcess [i][j - 1]] 
							<= 
				 A [preProcess [i + (1 << (j - 1))][j - 1]]
				)
				?
					preProcess [i][j - 1]
				:
					preProcess [i + (1 << (j - 1))][j - 1];
}

int query (int s, int e)
{
	if (e < s) swap (s, e);
	int diff = e - s;
	diff = 31 - __builtin_clz (diff + 1);
	cout << "indexes: " << s << " " << diff << " " << A [preProcess [s][diff]]<< "\n";
	cout << "indexes: " << e - (1 << diff) + 1 << " " << diff << " " << A [preProcess [e - (1 << diff) + 1][diff]] << "\n";

	return (
			A [preProcess [s][diff]] <= A [preProcess [e - (1 << diff) + 1][diff]]
		   )
			?
		   preProcess [s][diff]
			:
		   preProcess [e - (1 << diff) + 1][diff];

}

int main ()
{
//	cin.tie(nullptr);
//	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0 ; i < n - 1; i ++)
	{
		int x;
		cin >> x;
		ln [x].push_back (i + 1);
	}
	init ();
	int q;
	cin >> q;
	for (int i = 0 ; i < q ; i ++)
	{
		int a, b;
		cin >> a >> b;
		int LCA = query (a, b);
		if (a == b)
			cout << "You are there";
		else if ( LCA == b or LCA == a)
			cout << "Directly";
		else
			cout << "Through " << LCA;
		cout << endl;
	}
}
