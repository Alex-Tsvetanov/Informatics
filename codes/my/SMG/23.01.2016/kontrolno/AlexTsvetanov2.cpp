#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp (pair < uint32_t , int32_t > a, uint32_t b)
{
	return a.first < b;
}

bool answer (vector <uint32_t> a, vector <uint32_t> b1)
{
	if (a.size () < b1.size ())
		swap (a, b1);
	vector < pair < uint32_t, int32_t > > b;
	for (int i = 0 ; i < b1.size () ; i ++)
		b.push_back ({b1 [i], i});
	sort (b.begin (), b.end ());
	int last_index = -1;
	for (int i = 0 ; i < a.size () ; i ++)
	{
		//cout << last_index << " " << "FIND: " << a [i] << " --> ";
		int index_of_find_number = lower_bound (b.begin (), b.end (), a [i], comp) - b.begin ();
		if (index_of_find_number != b.size () and b [index_of_find_number].first == a [i])
		{
			//cout << "on " << index_of_find_number << " => " <<  b [index_of_find_number].second << "\n";
			if ( last_index > b [index_of_find_number].second )
			{
				//cout << last_index << " > " << b [index_of_find_number].second << "\n";
				return 0;
			}

			last_index = b [index_of_find_number].second;
		}
		//cout << "\n";
	}
	//cout << "----------------\n";
	return 1;
}

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		uint32_t N;
		cin >> N;
		vector < uint32_t > a, b;
		for (int j = 0 ; j < N ; j ++)
		{
			int B;
			cin >> B;
			a.push_back (B);
		}
		cin >> N;
		for (int j = 0 ; j < N ; j ++)
		{
			int A;
			cin >> A;
			b.push_back (A);
		}
		cout << answer (move (a), move (b)) << " "; 
	}

}
