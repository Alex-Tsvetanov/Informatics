#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Edge
{
    public:
        int a, b, cost;
        Edge(int a1, int b1, int cost1) : a (a1), b (b1), cost (cost1)
        {}
};

bool operator < (Edge a, Edge b)
{
    return a.cost < b.cost;
}

int GetValue(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}
int GetCost(vector<string> path, vector<string> build, vector<string> destroy)
{
    int N = path.size (), massiveCost = 0, mstCost = 0;
    vector < Edge > edges;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
        {
            if (path[i][j] == '0')
                edges.push_back (Edge(i, j, GetValue(build[i][j])));
            else
            {
                int val = GetValue(destroy[i][j]);
                edges.push_back (Edge(i, j, -val));
                massiveCost += val;
            }
        }
    sort (edges.begin (), edges.end ());
    int* color = new int [N];
    for (int i = 0; i < N; ++i)
        color[i] = i;
    for (int i = 0; i < (int)edges.size (); ++i)
    {
        Edge e = edges[i];
        if (color[e.a] != color[e.b])
        {
            mstCost += e.cost;
            // recolor the component
            int oldColor = color[e.b];
            for (int j = 0; j < N; ++j)
                if (color[j] == oldColor)
                    color[j] = color[e.a];
        }
    }
    return massiveCost + mstCost;
}

string ConsoleReadLine ()
{
    try
    {
	string out;
	getline (cin, out);
	return out;
    }
    catch (std::exception& e)
    {
	throw e;
    }
}
int main()
{
    int N;
    cin >> N;

    vector<string> paths;
    vector<string> builds;
    vector<string> destroy;

    for (int i = 0; i < N; i++)
    {
        paths.push_back (ConsoleReadLine());
    }

    for (int i = 0; i < N; i++)
    {
        builds.push_back (ConsoleReadLine());
    }

    for (int i = 0; i < N; i++)
    {
        destroy.push_back (ConsoleReadLine());
    }

    cout << (GetCost(paths, builds, destroy)) << endl;
}
