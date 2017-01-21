//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin ("equations.in");
ofstream cout ("equations.out");

#include <vector>
#include <cmath>

int n, m;
int k [2048][2048];
double approx [2048], exact [2048];

vector <int> x;

bool is_true (int ind)
{
	long long ans = k [ind][n];
	for (int i = 0 ; i < n ; i ++)
	{
		ans -= (long long)k [ind][i] * x [i];
		if (ans < 0)
			return false;
	}
	return ans == 0;
}

double not_exactly (int ind)
{
	double ans = 0;
	for (int i = 0 ; i < n ; i ++)
		ans += k [ind][i] * x [i] - k [ind][n];
	ans = abs (ans) + 1;
	ans = approx [ind] / ans;
	return ans;
}

double get_score ()
{
	double score = 0;
	for (int i = 0 ; i < m ; i ++)
	{
		if (is_true (i))
			score += exact [i];
		else
			score += not_exactly (i);
	}
	return score;
}

int curr_m_ind;
int m_ind;
vector <int> optimum;
double max_score = -1e10;
bool seted = false;

void rec (int ind)
{
	//cout << "Ind = " << ind << endl;
	if (ind == m)
	{
		double score = get_score ();
		//cout << "new score: " << score << endl;
		if (!seted)
		{
			max_score = score;
			for (auto& a : x)
				optimum.push_back (a);
			m_ind = curr_m_ind;
			seted = true;
		}
		else
			if (max_score < score)
			{
				max_score = score;
				for (int i = 0 ; i < (int)x.size () ; i ++)
					optimum [i] = x [i];
				m_ind = curr_m_ind;
			}
		return ;
	}
	x.push_back (1);
	for ( ; x [x.size () - 1] <= 5 ; x [x.size () - 1] ++)
		rec (ind + 1);
	x.pop_back ();
}

int main ()
{
    cin >> m >> n;
    for (int i = 0 ; i < m ; ++ i)
	{
        for (int j = 0 ; j < n ; ++ j)
		{
            cin >> k [i][j];
        }
		cin >> exact [i] >> approx [i];
    }
	int s;
	cin >> s;
    for (int indS = 0 ; indS < s ; ++ indS)
	{
        for (int ind_j = 0 ; ind_j < m ; ++ ind_j)
            cin >> k [ind_j][n];
		rec (0);
	}

	cout << m_ind + 1 << endl;
	for (int i = 0 ; i < (int)optimum.size () - 1 ; i ++)
		cout << optimum [i] << " ";
	cout << optimum [optimum.size () - 1] << "\n";
}
