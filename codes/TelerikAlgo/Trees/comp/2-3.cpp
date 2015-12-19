#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    public: int a;
    public: int b; 
    public: int cost;

    public: Edge(int a, int b, int cost)
    {
        this->a = a;
        this->b = b;
        this->cost = cost;
    }

    public: int CompareTo(Edge e)
    {
        return cost - e.cost;
    }
};


bool operator < (Edge a, Edge b)
{
    return a.CompareTo (b) > 0;
}

int GetValue (char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}

int GetCost(vector<string> path, vector<string> build, vector<string> destroy)
{
    int N = path.size(), massiveCost = 0, mstCost = 0;
    vector<Edge> edges = vector<Edge> ();

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
        {
            if (path[i][j] == '0')
                edges.push_back(Edge(i, j, GetValue(build[i][j])));
            else
            {
                int val = GetValue(destroy[i][j]);
                edges.push_back(Edge(i, j, -val));
                massiveCost += val;
            }
        }
    sort(edges.begin (), edges.end ());

    int* color = new int[N];
    for (int i = 0; i < N; ++i)
        color[i] = i;

    for (int i = 0; i < (int)edges.size(); ++i)
    {
        Edge e = edges[i];
        if (color[e.a] != color[e.b])
        {
            mstCost += e.cost;
            int oldColor = color[e.b];
            for (int j = 0; j < N; ++j)
                if (color[j] == oldColor)
                    color[j] = color[e.a];
        }
    }
    return massiveCost + mstCost;
}

int main ()
{
    int N;
    cin >> N;

    vector<string> paths = vector<string>();
    vector<string> builds = vector<string>();
    vector<string> destroy = vector<string>();

    for (int i = 0; i < N; i++)
    {
        string x;
        getline (cin, x);
        paths.push_back(x);
    }

    for (int i = 0; i < N; i++)
    {
        string x;
        getline (cin, x);
        builds.push_back(x);
    }

    for (int i = 0; i < N; i++)
    {
        string x;
        getline (cin, x);
        destroy.push_back(x);
    }

    cout << (GetCost(paths, builds, destroy)) << "\n";
}
