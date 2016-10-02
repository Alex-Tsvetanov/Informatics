#include <cstdio>
#include <cstdlib>
#include <vector>

const int N = 100000, TREE_HEIGHT = 17;

struct point
{
    long long x, y;
    int multi(const point &a, const point &b)
    {
        long long x1 = a.x - x, x2 = b.x - x, y1 = a.y - y, y2 = b.y - y;
        long long result = x1 * y2 - x2 * y1;
        if (result > 0)
            return 1;
        else if (result < 0)
            return -1;
        return 0;
    }
};

struct node
{
    int child;
    node *next;
    node(int _child, node *_next) : child(_child), next(_next) {}
};

int deep_data[N + 1] = {0};

int n, *deep = deep_data + 1, ancestor[N][TREE_HEIGHT + 1] = {0};
point pt[N];
node *children[N] = {0};

void add_child(int parent, int child)
{
    children[parent] = new node(child, children[parent]);
}

int lca(int u, int v)
{
    if (deep[u] < deep[v])
    {
        int t = u;
        u = v;
        v = t;
    }

    for (int i = TREE_HEIGHT; i >= 0; i--)
    {
        if (deep[ancestor[u][i]] >= deep[v])
        {
            u = ancestor[u][i];
            if (deep[u] == deep[v])
                break;
        }
    }

    if (u == v)
        return u;

    for (int i = TREE_HEIGHT; i >= 0; i--)
    {
        if (ancestor[u][i] != ancestor[v][i])
        {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }

    return ancestor[u][0];
}

void init_ancestors()
{
    for (int i = 1; i <= TREE_HEIGHT; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ancestor[j][i - 1] != -1)
                ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
            else
                ancestor[j][i] = -1;
        }
    }
}

void dfs(int t = n - 1, int layer = 0)
{
    deep[t] = layer;
    for (node *p = children[t]; p; p = p->next)
        dfs(p->child, layer + 1);
}

void read_data()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &pt[i].x, &pt[i].y);
        ancestor[i][0] = -1;
    }
}

void build_tree()
{
    std::vector<int> q;
    q.push_back(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (q.size() > 1 && pt[i].multi(pt[q.back()], pt[q[q.size() - 2]]) > 0)
            q.pop_back();
        ancestor[i][0] = q.back();
        add_child(q.back(), i);
        q.push_back(i);
    }
}

void answer()
{
    int q, u, v;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &u, &v);
        int ans = lca(u - 1, v - 1) + 1;
        printf("%d ", ans == 0 ? n : ans);
    }
}

int main()
{
    read_data();
    build_tree();
    init_ancestors();
    deep[-1] = -1;
    dfs();

    answer();
    return 0;
}

/*
6
1 4
2 1
3 2
4 3
6 4
7 4
3
3 1
5 6
2 3
*/
