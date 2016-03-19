#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 3001;

int N, M;
int minTime[MAXN], maxRes[MAXN], minForAll = 1 << 20;
vector<int> A[MAXN];

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        //A[b].push_back(a);
    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            minTime[j] = 1 << 20;
        }

        set<int> s;
        s.insert(i);
        minTime[i] = 0;
        while (!s.empty())
        {
            int curr = *s.begin();
            s.erase(curr);
            for (int j = 0; j < A[curr].size(); ++j)
            {
                if (minTime[curr] + 1 < minTime[A[curr][j]])
                {
                    s.erase(A[curr][j]);
                    minTime[A[curr][j]] = minTime[curr] + 1;
                    s.insert(A[curr][j]);
                }
            }
        }
        //cout << i << ":\n";
        maxRes[i] = minTime[0];
        for (int j = 0; j < N; ++j)
        {
            //cout << minTime[j] << ' ';
            if (minTime[j] > maxRes[i])
            {
                maxRes[i] = minTime[j];
            }
        }
        //cout << "\n";
        //cout << maxRes[i] << ' ' << minForAll << endl;
        if (maxRes[i] < minForAll)
        {
            minForAll = maxRes[i];
        }
    }

    vector<int> res;
    for (int i = 0; i < N; ++i)
    {
        if (maxRes[i] == minForAll)
        {
            res.push_back(i);
        }
    }

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if (i < res.size() - 1)
        {
            cout << ' ';
        }
    }
    cout << '\n';
    return 0;
}
