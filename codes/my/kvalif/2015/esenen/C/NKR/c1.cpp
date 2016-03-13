#include <iostream>
#include <vector>
using namespace std;
struct student{
    vector<int> fr;
    bool anyfriends;
    bool seen;
};
int main()
{
    int N, M, found = 0;
    cin >> N >> M;
    student a[N];
    for (int i = 0;i < N;i ++)
    {
        a[i].anyfriends = false;
        a[i].seen = false;
    }
    for (int i = 0;i < M;i ++)
    {
        int k, m;
        cin >> k >> m;
        a[k - 1].fr.push_back(m - 1);
        a[k - 1].anyfriends = true;
    }
    for (int i = 0;i < N;i ++)
    {
        if(a[i].anyfriends)
        {
            for (int v = 0;v < a[i].fr.size();v ++)
            {
                if(!a[a[i].fr[v] - 1].seen)
                {
                    a[a[i].fr[v] - 1].seen = true;
                }
            }
        }
        if(!a[i].seen)
        {
            found ++;
        }
    }
    cout << found << endl;
    return 0;
}
