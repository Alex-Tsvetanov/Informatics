#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string ConsoleReadLine ()
{
	string x;
	getline (cin, x);
	return move (x);
}

struct Edge
{
    int a = 0;
    int b = 0;
    int cost = 0;

    Edge(int a, int b, int cost)
    {
	    this->a = a;
	    this->b = b;
	    this->cost = cost;
    }
};

bool cmp (Edge* a, Edge* b)
{
      if (a->cost < b->cost) return true;
      if (a->cost > b->cost) return false;
      if (a->a < b->a) return true;
      if (a->a > b->a) return false;
      return (a->b < b->b);
}

int charToNum(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
	    return c - 'A';
    }
    return c - 'a' + 26;
}

int Ans (vector<string> path, vector<string> build, vector<string> destroy)
{
    int N = path.size(), massiveCost = 0, mstCost = 0;
    vector<Edge*> edges;

    for (int i = 0; i < N; ++i)
      for (int j = i + 1; j < N; ++j)
	if (path[i][j] == '0')
	  edges.push_back (new Edge(i, j, charToNum(build[i][j])));
	else
	{
	  int val = charToNum (destroy[i][j]);
	  edges.push_back (new Edge(i, j, -val));
	  massiveCost += val;
	}
    sort (edges.begin(), edges.end(), cmp);

    vector <int> color (N);
    for (int i = 0; i < N; ++i)
      color[i] = i;

    for (int i = 0; i < (int)edges.size(); ++i)
    {
      auto* e = edges[i];
      if (color[e->a] != color[e->b])
      {
	mstCost += e->cost;
	int oldColor = color[e->b];
	for (int j = 0; j < N; ++j)
	  if (color[j] == oldColor)
	    color[j] = color[e->a];
      }
    }
    return massiveCost + mstCost;
}

int main ()
{
    int N = stoi (ConsoleReadLine());

    vector<string> paths;
    vector<string> builds;
    vector<string> destroy;

    for (int i = 0; i < N; i++)
      paths.push_back (ConsoleReadLine());

    for (int i = 0; i < N; i++)
      builds.push_back (ConsoleReadLine());

    for (int i = 0; i < N; i++)
      destroy.push_back (ConsoleReadLine());

    cout << Ans (move(paths), move(builds), move (destroy)) << endl;
}
