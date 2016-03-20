/*#include <iostream>

using namespace std;

int dp [20][30];

int main ()
{
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    int p, n, s;
    cin >> p >> n >> s;

    for (int i = 1 ; i < s ; i ++)
        dp [0][i] = 0;
    for (int i = 0 ; i < n ; i ++)
        dp [i][0] = 1;

}*/
#include <iostream>

using namespace std;

long long dp [2][32];

int main ()
{
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    int p, n, s;
    cin >> p >> n >> s;
    //init knapsack
    for (int i = 0 ; i <= s ; i ++)
        dp [0][i] = 0;
    dp [0][0] = 1;
    //fill knapsack
    for (int i = 1 ; i <= n ; i ++)
    {
        int curr = i % 2, prev = (i - 1) % 2;
        for (int k = 0 ; k <= s ; k ++)
            dp [curr][k] = 0;
        for (int j = 0 ; j < p ; j ++)
        {
            for (int k = 0 ; k < s ; k ++)
                if (k + j < s)
                {
                    dp [curr][k + j] += dp [prev][k];
                    dp [curr][s] += dp [prev][k];
                }
        }
//        cout << "i = " << i << ": ";
//        for (int k = 0 ; k < s ; k ++)
//            cout << dp [curr][k] << "\t";
//        cout << "\n";
    }
    cout << dp [n % 2][s] << endl;
    return 0;
}
