#include <iostream>
	
using namespace std;

struct Point
{
	int x, y;
};

bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  

	return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false;
}

struct Line
{
	Point p1, p2;
};

int main()
{
	
	int n;
	cin>>n;
	Line *lines = new Line[n];
	for(int i = 0; i<n; i++)
	{
		Line l;
		cin>>l.p1.x>>l.p1.y>>l.p2.x>>l.p2.y;
		lines[i] = l; 
	}
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j  = 0; j<n; j++)
		{
			if(i!=j)
			{
				ans+=doIntersect(lines[i].p1, lines[i].p2, lines[j].p1, lines[j].p2);		
			}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}
