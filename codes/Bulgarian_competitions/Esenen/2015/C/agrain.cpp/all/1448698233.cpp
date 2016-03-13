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
	pos.insert (-D - 1);
	pos.insert (N + D + 1);
	for (int i = 0 ; i < N ; i ++)
	{
		pos.insert (X - 1);
		//        cout << "Insert of " << X << endl;
		auto start = pos.begin ();
		if (*start < D)
		{
			//            cout << "Min X (" << *start << ") is smaller then " << D << endl;
			start ++;
			auto end = pos.end ();
			end --;
			for (auto it = start ; it != end ; it ++)
			{
				auto itNext = it, itPrev = it;
				
				auto curr = *it;
				
				itPrev --; auto prev = *it;
				
				itNext ++; auto next = *it;
				
				if ((prev >= curr - D and prev <= curr + D) and
						(next >= curr - D and next <= curr + D))
				{
					//                    cout << prev << " and " << next << " are in interval [" << X - D << ", " << X + D << "]" << endl;
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
		X = (X * A + B) % (L + 1);
	}
	return 0;
}
