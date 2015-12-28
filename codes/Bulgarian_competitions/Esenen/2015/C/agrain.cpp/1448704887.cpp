//agrain.cpp
#include <iostream>
#include <set>

using namespace std;

set < int > pos;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int N, L, D, A, B;
	int64_t X;
	cin >> N >> L >> D >> X >> A >> B;
	for (int i = 0 ; i < N ; i ++)
	{
		pos.insert (X);
		if (pos.size () == 1)
		{
			if (X <= D and L - X <= D)
			{
				cout << "1\n";
				return 0;
			}
		}
		else if (pos.size () == 2)
		{
			int a, b;
			auto it = pos.begin();
			a = *it;
			it ++;
			b = *it;
			//cout << a << " " << b << "\n";
			if (a <= D and b - a <= D and L - b <= D)
			{
				cout << "2\n";
				return 0;
			}
		}
		else
		{
			//cout << "Insert of " << X << endl;
			auto start = pos.begin ();
			if (*start <= D)
			{
				//cout << "Min X (" << *start << ") is smaller or equal then " << D << endl;
				start ++;
				auto end = pos.end ();
				end --;
				for (auto it = start ; it != end ; it ++)
				{
					auto itNext = it, itPrev = it;
					
					auto curr = *it;
					
					itPrev --; auto prev = *itPrev;
					
					itNext ++; auto next = *itNext;
					//cout << "Checking for " << prev << " and " << next << " is in interval [" << X - D << ", " << X + D << "]" << endl;
					
					if ((prev >= curr - D and prev <= curr + D) and
							(next >= curr - D and next <= curr + D))
					{
						//cout << prev << " and " << next << " are in interval [" << X - D << ", " << X + D << "]" << endl;
					}
					else
						goto Break;
				}
				cout << i + 1 << endl;
				return 0;
				Break:
				{
					
				}
			}
		}
		X = (X * A + B) % (L + 1);
	}
	cout << "-1\n";
	return 0;
}
