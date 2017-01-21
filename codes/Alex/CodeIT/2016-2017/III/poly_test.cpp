#include <vector>
//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin ("equations.in");
ofstream cout ("equations.out");
//#include <exception>

using namespace std;

struct polynom
{
	float Const;
	vector <float> k_x_i;

	polynom (float Const = 0, size_t vars = 0)
	{
		this->Const = Const;
		this->k_x_i = vector <float>(vars, 0);
	}

	polynom (short int vars, float* a)
	{
		Const = 0;
		for (short int i = 0 ; i < vars ; i ++)
			k_x_i.push_back (a [i]);
	}

	float calc (const float* x_i, short int size = -1)
	{
		if (size == -1)
			size = k_x_i.size ();
		//cout << k_x_i.size () << " " << x_i.size () << endl;
		float res = Const;
		for (short int i = 0 ; i < size ; i ++)
			res += k_x_i [i] * x_i [i];
		return res;
	}
	
	bool isNumber ()
	{
		for (short int i = 0 ; i < (short int)k_x_i.size () ; i ++)
			if (k_x_i [i] != 0)
				return false;
		k_x_i.clear ();
		return true;
	}

	float& operator[] (size_t ind)
	{
		if (ind >= k_x_i.size ())
			k_x_i.resize (ind + 1, 0);
		return k_x_i.at (ind);
	}
};

polynom operator + (const polynom& a, const polynom& b)
{
	polynom c = a;
	c.Const += b.Const;
	c.k_x_i.resize (max (a.k_x_i.size (), b.k_x_i.size ()), 0);
	for (short int i = 0 ; i < (short int)b.k_x_i.size () ; i ++)
		c.k_x_i [i] += b.k_x_i [i];
	return c;
}

polynom operator - (const polynom& a, const polynom& b)
{
	polynom c = a;
	c.Const -= b.Const;
	c.k_x_i.resize (max (a.k_x_i.size (), b.k_x_i.size ()), 0);
	for (short int i = 0 ; i < (short int)b.k_x_i.size () ; i ++)
		c.k_x_i [i] -= b.k_x_i [i];
	return c;
}

polynom operator * (const polynom& a, const float b)
{
	polynom c = a;
	c.Const *= b;
	for (short int i = 0 ; i < (short int)c.k_x_i.size () ; i ++)
		c.k_x_i [i] *= b;
	return c;
}

polynom operator / (const polynom& a, const float b)
{
	polynom c = a;
	c.Const /= b;
	for (short int i = 0 ; i < (short int)c.k_x_i.size () ; i ++)
		c.k_x_i [i] /= b;
	return c;
}

polynom operator * (polynom a, polynom b)
{
	if (a.isNumber ())
	{
		return b * a.Const;
	}
	else if (b.isNumber ())
	{
		return a * b.Const;
	}
	else
		throw /*runtime_error*/ ("Function* Not Implemented");
}

polynom operator / (polynom a, polynom b)
{
	if (b.isNumber ())
	{
		return a / b.Const;
	}
	else
		throw /*runtime_error*/ ("Function/ Not Implemented");
}

bool operator != (polynom& a, float b)
{
////if (!a.isNumber ())
////{
////	cout << "Eq: (";
////	for (auto& y : a.k_x_i)
////		cout << y << " ";
////	cout << "=" << a.Const << ")\n" << b << "\n";
////	throw runtime_error ("Polynom != Float");
////}
	return a.Const != b;
}

polynom operator += (polynom& a, const polynom& b)
{
	return (a = a + b);
}

polynom operator -= (polynom& a, const polynom& b)
{
	return (a = a - b);
}

polynom operator *= (polynom& a, const polynom& b)
{
	return (a = a * b);
}

polynom operator /= (polynom& a, const polynom& b)
{
	return (a = a / b);
}



polynom c [2048][1024];
polynom ans [1024];
bool found [1048];
bool skipped [2048];

void elimination (/*vector < vector < polynom > >& c, */short int n, short int m)
{
//	m = c.size ();
	for (short int i = 0 ; i < n ; ++ i)
		found [i] = false;
	for (short int i = 0 ; i < m ; ++ i)
		skipped [i] = false;
	short int num_of_independent = m;
	for (short int i = 0 ; i < n ; ++ i)
		//for each variable
	{
		short int x = -1;
		for (short int j = i ; j < m ; ++ j) 
			// find equation with coeficient not equals to 0
		{
			if (c [j][i] != 0)
			{
				x = j;
				break;
			}
		}

		if (x == -1)
		{
			continue;
		}

		swap (c [i], c [x]);
		swap (skipped [i], skipped [x]);
		// swap i-th and x-th rows

		for (short int j = i + 1 ; j <= n ; ++ j)
		{
			c [i][j] /= c [i][i];
		}

		c [i][i] = 1;

		for (short int j = i + 1 ; j < m ; ++ j)
		{
			skipped [j] = true;
			for (short int k = i + 1 ; k < n + 1 ; ++ k)
			{
				c [j][k] -= c [j][i] * c [i][k];
				if (c [j][k] != 0)
					skipped [j] = false;
			}
			c [j][i] = 0;
		}
	}
	
//	cout << "Eq " << m << " var " << n << "\n";
	for (short int i = 0 ; i < m ; ++ i)
	{
		num_of_independent -= skipped [i];
	}
//	cout << "I'm alive" << endl;
    if (num_of_independent < n)
    {
    	cout << "Independent: " << num_of_independent << endl;
    	return;
    }
////for (auto& z : c)
////{
////	for (auto& x : z)
////	{
////		cout << "Eq: (";
////		for (auto& y : x.k_x_i)
////			cout << y << " ";
////		cout << "=" << x.Const << "), ";
////	}
////	cout << endl;
////}
////cout << "I'm alive again" << endl;
	bool nep = true;
	while (nep)
	{
		nep = false;
		for (short int i = m - 1 ; i >= 0 ; -- i)
		{
			if (skipped [i])
				continue;
//			cout << "I'm alive again and again on i = " << i << endl;
			ans [i] = c [i][n];
			found [i] = true;
			for (short int j = n - 1 ; j > i ; -- j)
			{
				if (found [j])
					ans [i] = ans [i] - c [i][j] * ans [j];
				else 
				{
					found [i] = false;
					nep = true;
				}
			}
		}
	}
}




//short int approx [2048], exact [2048];
float b [1024];
float v [1024];

int main ()
{
	short int n, m;
	cin >> n >> m;
	v [0] = 1;
	for (short int i = 0 ; i < m ; ++ i)
	{
//		c.push_back (vector < polynom > ());
        for (short int j = 0 ; j < n ; ++ j)
		{
			float a;
            cin >> a;
//			c [i].push_back (polynom (a, n));
			c [i][j] = polynom (a, n);
        }
		c [i][n] = polynom (n, v);
//		c [i].push_back (polynom (n, v));
		short int a;
		cin >> a >> a;
//		cin >> exact [i] >> approx [i];
		swap (v [i], v [i + 1]);
    }
////try
////{
		elimination (/*c, */n, m);
////}
////catch(...)//exception& e)
////{
////	cout << e.what () << endl;
////	throw e;
////}
////cout << "---------------------------------------------\n";
////for (auto& x : ans)
////{
////	cout << "Eq: ";
////	for (auto& y : x.k_x_i)
////		cout << y << " ";
////	cout << "=" << x.Const << endl;
////}
	short int s;
	cin >> s;

	float boza;
    
	for (short int indS = 0 ; indS < s ; ++ indS)
	{
        for (short int row = 0 ; row < n ; ++ row)
		{
			cin >> boza;
			b [row] = (boza);
        }
		
		cout << indS + 1 << "\n";
		for (short int i = 0 ; i < n ; i ++)
			cout << (int)ans [i].calc (b, n) << " ";
		cout << "\n";
		return 0;
	}
}
