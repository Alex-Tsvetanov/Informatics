#include <iostream>
using namespace std;
int isk[1000000] = {-1000000001};// masiv s chislata, koito gledame
//bool ans[1000000];
int n, t;
void solve()
{
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        cin >> t;
        //cout << t << " ";
        for(int j = 0;j < i - 1;j ++)
        {
            //cout << isk[j] << " ";
            if(t > isk[j])
                isk[j] = -1000000001;
        }
        isk[i] = t;
        //cout << endl;
    }
    //cin >> t;
    if(isk[n - 2] < isk[n - 1])
        isk[n - 2] = -1000000001;
    for(int i = 0;i < n - 1;i ++)
    {
        if(isk[i] != -1000000001)
            cout << isk[i] << " ";
    }
    cout << isk[n - 1] << endl;
}
int main()
{
    solve();
    return 0;
}
