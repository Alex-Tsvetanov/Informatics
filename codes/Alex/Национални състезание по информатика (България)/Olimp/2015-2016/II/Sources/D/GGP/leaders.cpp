#include<iostream>
#include<vector>
using namespace std;
int n;
vector <long long> c;
void read()
{
    cin >> n;
    long long temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        c.push_back(temp);
    }
}
void solve()
{
    vector <long long> v;
    int br = 0;
    long long maxch = c[n-1];
    for (int i = n-1; i >= 0; i--)
        if (c[i] >= maxch)
        {
            maxch = c[i];
            br++;
            v.push_back(c[i]);
        }
        for (int i = br-1; i > 0; i--)
        cout << v[i] << " ";
        cout << v[0] << endl;
}
int main()
{
    read();
    solve();
}
