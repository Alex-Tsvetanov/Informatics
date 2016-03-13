#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    int* arr = new int [n];
    for (int i = 0 ; i < n ; i ++)
        cin >> arr [i];
    
    pair <int, int>* dp [2];
    dp [0] = new pair <int, int> [n];
    dp [1] = new pair <int, int> [n];
    for (int i = 0 ; i < n ; i ++) dp [0][i] = dp [1][i] = {1, -1};
    
    for (int variant = 0 ; variant < 2 ; variant ++)
        for (int i = 0 ; i < n ; i ++)
            for (int j = 0 ; j < i ; j ++)
                if (arr [i] != arr [j])
                {
                    if (dp [variant][j].first % 2 != 0)
                    {
                        if ( (arr [j] < arr [i]) == variant ) 
                            dp [variant][i] = {dp [variant][j].first + 1, j};
                    }
                    else if (dp [variant][j].first % 2 == 0)
                        if ( (arr [j] > arr [i]) == variant ) 
                            dp [variant][i] = {dp [variant][j].first + 1, j};
                }
    int v = 0, ind = 0;
    for (int variant = 0 ; variant < 2 ; variant ++)
        for (int i = 0 ; i < n ; i ++)
            if (dp [v][ind].first < dp [variant][i].first)
            {
                v = variant;
                ind = i;
            }
    vector < int > a;
    while (dp [v][ind].second != -1)
    {
        a.push_back (arr [dp [v][ind].second]);
        ind = dp [v][ind].second;
    }
    for (int i = a.size () - 1; i >= 0 ; i --)
        cout << a [i] << " ";
    cout << endl;
}
