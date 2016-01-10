#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef unsigned long long int u64;

bool mergeable(vector<int> &a, vector<int> &b)
{
    map<int, int> index_map;

    if(a.size() > b.size()) {
        vector<int> t = a;
        a = b;
        b = t;
    }

    for(int i = 0; i < b.size(); i++) {
        index_map[b[i]] = i;
    }

    int j = -1;

    for(int i = 0; i < a.size(); i++)
    {
        if(index_map.count(a[i]))
        {
            int t = index_map[a[i]];

            if(t > j) {
                j = t;
            }
            else {
                return false;
            }
        }
        else {
            continue;
        }
    }

    return true;
}

int main()
{
    for(int rows = 0; rows < 5; rows++)
    {
        vector<int> a;
        vector<int> b;
        int s;
        int t;

        cin >> s;
        a.reserve(s);

        for(int i = 0; i < s; i++) {
            cin >> t;
            a.push_back(t);
        }

        cin >> s;

        for(int i = 0; i < s; i++) {
            cin >> t;
            b.push_back(t);
        }

        if(mergeable(a, b)) {
            cout << '1';
        } else {
            cout << '0';
        }
    }

    cout << endl;

    return 0;
}
