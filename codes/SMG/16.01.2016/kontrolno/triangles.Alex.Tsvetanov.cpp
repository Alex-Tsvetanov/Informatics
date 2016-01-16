#include <iostream>

struct fPoint
{
	int x; int y;

	fPoint () : x (0), y (0)
	{}
	
	fPoint (int _x, int _y) : x (_x), y (_y)
	{}
};

int sign (fPoint p1, fPoint p2, fPoint p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
{
	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0;
	b2 = sign(pt, v2, v3) < 0;
	b3 = sign(pt, v3, v1) < 0;

	return ((b1 == b2) and (b2 == b3));
}

int main ()
{
	for (int i = 0 ; i < 1 ; i ++)
	{
		fPoint A_1, A_2;
		fPoint B_1, B_2;
		fPoint C_1, C_2;
		std::cin >> A_1.x >> A_1.y >> B_1.x >> B_1.y >> C_1.x >> C_1.y;
		std::cin >> A_2.x >> A_2.y >> B_2.x >> B_2.y >> C_2.x >> C_2.y;
		bool first_in_second =
		PointInTriangle (A_1, A_2, B_2, C_2) and
		PointInTriangle (B_1, A_2, B_2, C_2) and
		PointInTriangle (C_1, A_2, B_2, C_2);
		bool second_in_first =
		PointInTriangle (A_2, A_1, B_1, C_1) and
		PointInTriangle (B_2, A_1, B_1, C_1) and
		PointInTriangle (C_2, A_1, B_1, C_1);
		std::cout << (second_in_first or first_in_second) << std::endl;
	}
}
