#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class segment : public pair < int , pair < int, int > >
{
	public:
		int x () const
		{
			return this->first;
		}
		int y1 () const
		{
			return this->second.first;
		}
		int y2 () const
		{
			return this->second.second;
		}
		segment (int a, int b, int c) : pair < int, pair < int, int > > ({a, {max (b, c), min (b, c)}})
		{}
};

vector < segment > segments;

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int x, y1, y2;
		cin >> x >> y1 >> y2;
		segments.push_back (segment (x, y2, y1));
	}
	sort (segments.begin (), segments.end ());

	long long area = 0;

	long long yMax = segments [0].y1 ();
	long long yMin = segments [0].y2 ();
	int ind = 0;
	for (int i = 1 ; i < segments.size () ; )
	{
		long long x = segments [i].x () - segments [i - 1].x ();
		//cout << area << " + " << y * x << " = ";
		area += (yMax - yMin) * x;
		//cout << area << "\n";
		int j = i;
		for ( ; i < segments.size () and segments [i].x () == segments [j].x () ; i ++)
		{
			if (yMax == segments [i].y1 () and yMin == segments [i].y2 ())
			{
				continue;
			}
			else
			if (yMax == segments [i].y1 ())
			{
				yMax -= (segments [i].y1 () - segments [i].y2 ());
			}
			else 
			if (yMin == segments [i].y1 ())
			{
				yMin -= (segments [i].y1 () - segments [i].y2 ());
			}
			else 
			if (yMin == segments [i].y2 ())
			{
				yMin += (segments [i].y1 () - segments [i].y2 ());
			}
			else 
			if (yMax == segments [i].y2 ())
			{
				yMax += (segments [i].y1 () - segments [i].y2 ());
			}
			if (yMax < yMin)
				swap (yMax, yMin);
		}
	}
	cout << area << endl;
}
