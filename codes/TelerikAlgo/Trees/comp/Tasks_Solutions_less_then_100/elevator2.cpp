#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ln [100000];

int preProcess [100000][19];
vector < int > Euler_tour_in_tree;
int depth [100000];

void Euler_tour (int v, int prev = -1, int curr_depth = 0)
{
    Euler_tour_in_tree.push_back (v);
    depth [v] = curr_depth;
    for (auto& x : ln [v])
    {
        if (x != prev)
        {
            Euler_tour (x, v, curr_depth + 1);
            Euler_tour_in_tree.push_back (v);
        }
    }
}
template <typename T>
struct BIT
{
    T** tree;
    int levels;
    BIT () {}

    void fill ()
    {
        for (int row = levels - 1 ; row >= 0 ; row --)
            for (int col = 0 ; col < (1 << row) ; col ++)
            {
                tree [row][col] =
                    (
                        (depth [tree [row + 1][2 * col]] <= depth [tree [row + 1][2 * col + 1]])
                        ?
                        tree [row + 1][2 * col]
                        :
                        tree [row + 1][2 * col + 1]
                    );
            }
    }

    void init (std::vector <T> arr)
    {
        levels = 31 - __builtin_clz (arr.size ());
        if ( (1ull << levels) < arr.size () )
            levels ++;

        tree = new T* [levels + 1];
        for (int j = levels - 1 ; j >= 0 ; j --)
            tree [j] = new T [1ull << (j + 1)];

        tree [levels] = new T [ 1ull << levels ];
        for (int i = 0 ; i < (int)arr.size () ; i ++)
            tree [levels][i] = arr [i];
        for (int i = (int)arr.size () ; i < (1 << levels) ; i ++)
            tree [levels][i] = tree [levels][i - 1];

        fill ();
    }
    bool cmp (T a, T b)
    {
        return depth [a] <= depth [b];
    }

    T query (int a, int b)
    {
        if (b < a)
            swap (b, a);
        return *min_element (tree [levels] + a, tree [levels] + b, cmp);
        //cout << "Query for " << a << " and " << b << endl;
        int diff = b - a + 1;
        int row = levels, col = a;
        T ans = tree [row][col];
        if (a % 2 == 1)
        {
            ans = min (ans, tree [levels][a], cmp);
            a ++;
        }
        if (b % 2 == 0)
        {
            ans = min (ans, tree [levels][b], cmp);
            b --;
        }
        diff = b - a + 1;
        while (diff > 0)
        {
            if (diff % 2 == 1)
            {
                //cout << "\tGet " << tree [row][col] << endl;
                ans = min (ans, tree [row][col], cmp);
            }

            diff /= 2;
            row --;
            col = (col + 1) / 2;
        }
        //cout << "Answer of query is " << ans << endl;
        return ans;
    }

    ~BIT ()
    {
        for (int i = 0 ; i <= levels ; i ++)
            delete[] tree [i];
        delete[] tree;
    }
};

int main ()
{
    cin.tie(nullptr);
    ios::sync_with_stdio (false);
    int n;
    cin >> n;
    for (int i = 0 ; i < n - 1; i ++)
    {
        int x;
        cin >> x;
        ln [x].push_back (i + 1);
    }
    Euler_tour (0);

    for (int i = 0 ; i < n ; i ++)
        ln [i].clear ();
    vector < int > firsts;
    for (int i = 0 ; i < (int)Euler_tour_in_tree.size () ; i ++)
        cout << Euler_tour_in_tree [i] << " ";
    cout << endl;
    for (int i = 0 ; i < (int)Euler_tour_in_tree.size () ; i ++)
        cout << depth [Euler_tour_in_tree [i]] << " ";
    cout << endl;
    for (int i = 0 ; i < (int)Euler_tour_in_tree.size () ; i ++)
    {
        ln [Euler_tour_in_tree [i]].push_back (i);
    }

    BIT<int> index_tree;
    index_tree.init (move (Euler_tour_in_tree));

    int q;
    cin >> q;
    for (int i = 0 ; i < q ; i ++)
    {
        int a, b;
        cin >> a >> b;
        int LCA = index_tree.query (ln [a][0], ln [b][0]);
        if (a == b)
            cout << "You are there";
        else if ( LCA == b or LCA == a)
            cout << "Directly";
        else
            cout << "Through " << LCA;
        cout << endl;
    }
}
