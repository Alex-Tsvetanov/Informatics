#include <stdio.h>
#include <vector>
#include <algorithm>

int guides [128];
int countries [16];

struct edge
{
	int* guide;
	int* country;
	int  children;
	edge () {}
	edge (int guideID, int countryId, int children)
	{
		guide = &guides [guideID];
		country = &countries [countryId];
		this->children = children;
	}
};

bool cmp (edge, edge);

std::vector < edge > edges;

void addChildrenToCountry (int country, int children)
{
	countries [country] += children;
}

int input [128][16];

int is_guide_busy [128];
int is_country_busy [16];

int main ()
{
	int n, m;
	scanf ("%d%d", &n, &m);

	int children;

	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < m ; j ++)
		{
			scanf ("%d", &children);
			input [i][j] = children;
			edges.push_back (edge (i, j, children));
			addChildrenToCountry (j, children);
		}
	std::sort (edges.begin (), edges.end (), cmp);
	
	//for (auto& x : edges)
	//	printf ("country: %ld guide: %ld ratio: %d/%d\n", (x.country - countries + 1), (x.guide - guides + 1), x.children, (*x.country));

	for (auto& x : edges)
	{
		int guideID = x.guide - guides;
		int countryID = x.country - countries;
		if (!is_guide_busy [guideID] and !is_country_busy [countryID])
		{
			is_guide_busy [guideID] = x.children + 1;
			is_country_busy [countryID] = guideID + 1;
		}
	}

	int ans = 0;

	for (int i = 0 ; i < m ; i ++)
	{
		//printf ("Country %d = +(%d - %d)\n", i + 1, countries [i], is_guide_busy [is_country_busy [i] - 1] - 1); 
		ans += countries [i] - (is_guide_busy [is_country_busy [i] - 1] - 1);
	}
	printf ("%d\n", ans);
}

bool cmp (edge a, edge b)
{
	double ratioA = a.children / ((double)(*a.country));
	double ratioB = b.children / ((double)(*b.country));
	return ratioA > ratioB;
}
