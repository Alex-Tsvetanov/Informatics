	struct point
	{
		float x, y;
		point ()
		{
			x = 0.0f; y = 0.0f;
		}
		point (float a, float b)
		{
			x = a; y = b;
		}
	};

	ostream& operator << (ostream& out, point& a)
	{
		out << "(" << a.x / 4 << ", " << a.y / 4 << ")";
		return out;
	}

	istream& operator >> (istream& in, point& a)
	{
		in >> a.x >> a.y;
		return in;
	}

	point operator - (point a, point b)
	{
		return point (a.x - b.x, a.y - b.y);
	}

	bool operator == (point a, point b)
	{
		return (fabs (a.y - b.y) <= 0.01 and fabs (a.x - b.x) <= 0.01);
	}

	bool operator > (point a, point b)
	{
		if (a.y == b.y)
			return a.x > b.x;
		return (a.y > b.y);
	}

	bool operator < (point a, point b)
	{
		if (a.y == b.y)
			return a.x < b.x;
		return (a.y < b.y);
	}

	std::vector < point > polygon;

	const string colinear = "colinear", clockwise = "clock wise", counterclockwise = "counterclock wise";
    
	double CrossProduct(point a, point b)
    {
        return a.x * b.y - a.y * b.x;
    }

	string orientation(point A, point B, point C)
	{
		point AC = C - B,
		      AB = A - B;

		double val = CrossProduct(AB, AC);

	    if (fabs (val) <= 0.01)
			return colinear;
		if (val > 0.01)
			return clockwise;
//		if (val < -0.01)
			return counterclockwise;
	}

	bool inAngle (int A, int K)
	{
		point C = polygon [A],
			  D = polygon [(A - 1 + polygon.size ()) % polygon.size ()],
			  B = polygon [(A + 1 + polygon.size ()) % polygon.size ()],
			  E = polygon [K];
		//cout << "D " << D << endl; 
		//cout << "C " << C << endl; 
		//cout << "B " << B << endl;
		//cout << "Orientation (D, C, B) = " << orientation (D, C, B) << endl;
		if (orientation (D, C, B) == clockwise)
		{
			//cout << "< 180\n";
			//cout << "D " << D << endl; 
			//cout << "C " << C << endl; 
			//cout << "B " << B << endl;
			//cout << "E " << E << endl;
			//cout << "Orientation (C, D, E) = " << orientation (C, D, E) << "\n";
			//cout << "Orientation (C, E, B) = " << orientation (C, E, B) << endl;
			return ((orientation (C, D, E) == counterclockwise) and (orientation (C, E, B) == counterclockwise));
		}
		else
		{
			swap (B, D);
			//cout << "> 180\n";
			//cout << "D " << D << endl; 
			//cout << "C " << C << endl; 
			//cout << "B " << B << endl;
			//cout << "E " << E << endl;
			//cout << "Orientation (C, D, E) = " << orientation (C, D, E) << "\n";
			//cout << "Orientation (C, E, B) = " << orientation (C, E, B) << endl;
			return ((orientation (C, D, E) != counterclockwise) or (orientation (C, E, B) != counterclockwise));
		}
	}

	point* intersection (float x1,float y1,float x2,float y2, float x3, float y3, float x4, float y4)
	{
		float d = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
		if (d == 0) return nullptr;

		float xi = ((x3-x4)*(x1*y2-y1*x2)-(x1-x2)*(x3*y4-y3*x4))/d;
		float yi = ((y3-y4)*(x1*y2-y1*x2)-(y1-y2)*(x3*y4-y3*x4))/d;

		point* p = new point(xi,yi);
		if (xi < min(x1,x2) || xi > max(x1,x2)) return nullptr;
		if (xi < min(x3,x4) || xi > max(x3,x4)) return nullptr;
		return p;
	}

	bool Intersect (point p1, point q1, point p2, point q2)
	{
		if (p1 == q2 and q1 == p2)
			return true;
		if (p1 == p2 and q1 == q2)
			return true;
		point* p = intersection (p1.x,p1.y,q1.x,q1.y,p2.x,p2.y,q2.x,q2.y);
		if (p == nullptr) return false;
		if (*p == p1 or *p == q1 or *p == p2 or *p == q2)
			return false;
		return true;
	}

	vector < pair < int, int > > edges;
	
	bool Intersect (int a, int b, int c, int d)
	{
		return Intersect (polygon [a], polygon [b], polygon [c], polygon [d]);
	}
	
	bool Intersect (int a, int b)
	{
		return Intersect (edges [a].first, edges [a].second, edges [b].first, edges [b].second);
	}

	vector < set < int > > ln;
	
	void gen_LN ()
	{
		for (int i = 0 ; i < (int)polygon.size () ; i ++)
			for (int j = i + 1 ; j < (int)polygon.size () ; j ++)
			{
				//cout << "Check: " << ((char)(i + 'A')) << " " << ((char)(j + 'A')) << endl;
				for (int k = 0 ; k < (int)polygon.size () ; k ++)
					if (Intersect (polygon [i], polygon [j], polygon [k], polygon [(k + 1) % polygon.size ()]))
					{
						//cout << "\tIntersect with " << " " << ((char)(k + 'A')) << " " <<((char)((k + 1) % polygon.size () + 'A')) << endl;
						goto BREAK;
					}
				////cout << "Check: " << i << " " << j << endl;
				if (inAngle (i, j))
				{
					edges.push_back ({i, j});
					//cout << "OK: " << ((char)(i + 'A')) << " " << ((char)(j + 'A')) << endl;
				}
				else
				{
					//cout << "\tNot in angle\n";
				}
				BREAK:{}
			}

		ln.resize (edges.size ());

		for (int i = 0 ; i < (int)edges.size () ; i ++)
			for (int k = i + 1 ; k < (int)edges.size () ; k ++)
			{
				if (!Intersect (polygon [edges [i].first], polygon [edges [i].second], polygon [edges [k].first], polygon [edges [k].second]))
				{
					ln [i].insert (k);
					ln [k].insert (i);
				}
			}
		//cout << "Edges:\n";
		int IND = 0;
		for (auto& x : edges)
		{
			//cout << IND++ << " -> " << ((char)(x.first + 'A')) << " " << ((char)(x.second + 'A')) << " " << "\n";
		}
		//cout << ln.size () << endl;
		//cout << "LN:" << endl;
		for (int i = 0 ; i < (int)edges.size () ; i ++)
		{
			//cout << i << " -> " << endl << "\t";
			//for (auto& x : ln [i])
				//cout << x << " ";
			//cout << endl;
		}
	}
