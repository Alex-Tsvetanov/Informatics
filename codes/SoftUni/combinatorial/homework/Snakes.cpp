#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

string rotateVert (string b)
{
	for (auto& x : b)
	{
		if (x == 'D')
			x = 'U';
		else if (x == 'U')
			x = 'D';
	}
	return b;
}

string rotate90 (string b)
{
	for (auto& x : b)
	{
		if (x == 'R')
			x = 'D';
		else if (x == 'D')
			x = 'L';
		else if (x == 'L')
			x = 'U';
		else if (x == 'U')
			x = 'R';
	}
	return b;
}

set < pair < int, int > > get_points (string a)
{
	set < pair <int, int> > p;
	set < pair < int , int > > ans;
	p.insert ({0,0});
	int X = 0, Y = 0, minX = 0, minY = 0;
	for (auto& x : a)
	{
		if (x == 'R')
			p.insert ({++X, Y});
		if (x == 'L')
		{
			p.insert ({--X, Y});
			minX = min (minX, X);
		}
		if (x == 'U')
		{
			p.insert ({X, --Y});
			minY = min (minY, Y);
		}
		if (x == 'D')
			p.insert ({X, ++Y});
	}
	for (auto it = p.begin () ; it != p.end () ; it ++)
	{
		ans.insert ({it->first - minX, it->second - minY});
	}
	return (ans);
}
bool correct (string a, string b)
{
	if (a.size () != b.size ())
		return false;
	auto pa = get_points (a);
	auto pb = get_points (b);
	auto ita = pa.begin ();
	auto itb = pb.begin ();
	bool g = true;
	for ( ; ita != pa.end () ; ita ++, itb ++)
		g = g and (*ita == *itb);
	return !g;
}

vector < string > allAnswers (vector < string > a)
{
	for (int i = 0 ; i < (int)a.size () ; i ++)
	{
		if (a [i][1] == 'R')
			;
		else if (a [i][1] == 'L')
			a [i] = rotate90 (rotate90 (a [i]));
		else if (a [i][1] == 'D')
			a [i] = rotate90 (rotate90 (rotate90 (a [i])));
		else if (a [i][1] == 'U')
			a [i] = rotate90 (a [i]);
	}
//	for (int i = 0 ; i < (int)a.size () ; i ++)
//		if (a [i].size () > 2 and a [i][2] == 'D')
//			a [i] = rotateVert (a [i]);
	sort (a.begin (), a.end ());
	vector < string > ans;
	for (int i = 0 ; i < (int)a.size () ; i ++)
	{
		for (int j = i + 1 ; j < (int)a.size () ; j ++)
		{
			//cout << a [i] << " " << a [j] << " -> " << rotateVert (a [i]) << " " << rotateVert (a [j]) << " | " << correct (a [i], a [j]) << endl;
			if (a [i].compare("SRRD") == 0 and a [j].compare ("SDDU"))
			{
				cout << a [i] << " " << a [j] << " -> " << rotateVert (a [i]) << " " << rotateVert (a [j]) << " | " << correct (a [i], a [j]) << endl;
			}
			if (correct (a [i], a [j]) or rotateVert (a [i]).compare (a [j]) == 0)
				goto Skip;
		}
		ans.push_back (a [i]);
		Skip:
		{
	
		}
	}
	return (ans);
}

bool check (string a)
{
	set < pair <int, int> > p;
	p.insert ({0,0});
	int X = 0, Y = 0;
	for (auto& x : a)
	{
		if (x == 'R')
			if (!p.insert ({++X, Y}).second)
				return false;
		if (x == 'L')
			if (!p.insert ({--X, Y}).second)
				return false;
		if (x == 'U')
			if (!p.insert ({X, --Y}).second)
				return false;
		if (x == 'D')
			if (!p.insert ({X, ++Y}).second)
				return false;
	}
	return true;
}

vector < string > allSnakes (int n)
{
	if (n == 1)
	{
		return {"S"};
	}
	auto X = allSnakes (n - 1);
	vector < string > ans;
	for (auto& x : X)
	{
		string y;
		y = x + "R";
		if (check (y))
			ans.push_back (y);
		y = x + "D";
		if (check (y))
			ans.push_back (y);
		y = x + "L";
		if (check (y))
			ans.push_back (y);
		y = x + "U";
		if (check (y))
			ans.push_back (y);
	}
	return (allAnswers ((ans))); 
}


void print (string b)
{
//	cout << b << endl;
//	return;
	char** a = new char* [b.size ()];
	for (int i = 0 ; i < (int)b.size () ; i ++)
	{
		a [i] = new char [b.size ()];
		for (int j = 0 ; j < (int)b.size () ; j ++)
			a [i][j] = ' ';
	}
	for (auto& x : get_points (b))
		a [x.first][x.second] = '#';
	for (int i = 0 ; i < (int)b.size () ; i ++, cout << "\n")
		for (int j = 0 ; j < (int)b.size () ; j ++)
			cout << a [i][j];
	cout << "-------------\n";
}

int main ()
{
	cout << "SRDR" << " " << "SRUR" << " " << rotateVert ("SRUR") << " " << rotateVert ("SRDR") << " " << correct ("SRDR", "SRUR");
	int n;
	cin >> n;
	auto X = allSnakes (n);
	n = 0;
	for (auto& x : X)
	{
		n ++;
		print (x);
	}
	cout << "Snakes count = " << n << endl;
}
