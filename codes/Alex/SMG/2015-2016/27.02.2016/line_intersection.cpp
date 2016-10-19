#include <iostream>

using namespace std;
namespace geometry
{
	struct fraction
	{
		float a, b;
		fraction (float a1 = 0, float b1 = 1)
		{
			a = a1;
			b = b1;
		}
	};
	struct point
	{
		float x, y;
		point (float x1 = 0.0f, float y1 = 0.0f)
		{
			x = x1; y = y1;
		}
	};
	struct line
	{
		point A, B;
		line (point A1 = point (), point B1 = point ())
		{
			A = A1;
			B = B1;
		}
		fraction steep ()
		{
			return fraction ((A.y - B.y), (A.x - B.x));
		}
	};
	point intersect (line a, line b)
	{
		fraction m_a = a.steep ();
		fraction m_b = b.steep ();
		//m_a.b*x+m_a.a*y+(m_a.a*(a.A.x-a.B.x)-m_a.b*(a.A.y-a.B.y))=0
		//x = (0-(m_a.a*(a.A.x-a.B.x)-m_a.b*(a.A.y-a.B.y))-m_a.a*y)/m_a.b
		//m_b.b*x+m_b.a*y+(m_b.a*(b.A.x-b.B.x)-m_b.b*(b.A.y-b.B.y))=0
		//m_b.b*((0-(m_a.a*(a.A.x-a.B.x)-m_a.b*(a.A.y-a.B.y))-m_a.a*y)/m_a.b)+m_b.a*y+(m_b.a*(b.A.x-b.B.x)-m_b.b*(b.A.y-b.B.y))=0
		point ans;
		ans.y = (2*m_a.a*m_a.b*m_a.b*m_b*b)/(m_a.a*m_b.b+m_a.b*m_b.a);
		ans.x = -(m_a.a*(2*m_a.b+ans.y))/m_a.b;
		return ans;
	}
};
using namespace geomery;

int main ()
{
	point A, B, C, E;
}
