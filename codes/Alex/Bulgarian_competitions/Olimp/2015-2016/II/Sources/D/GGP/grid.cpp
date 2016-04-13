#include<iostream>
using namespace std;
int n, m, grid[200][200];
void read()
{
    cin >> n >> m;
    int temp;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        cin >> temp;
        if (temp == 0) grid[i][j] = 0;
        else grid[i][j] = -1;
    }
}
void zones(int i, int j)
{
    grid[i][j] = 1;
    if (grid[i+1][j] == 0 && i+1 < n) zones(i+1, j);
    if (grid[i-1][j] == 0 && i-1 >= 0) zones(i-1, j);
    if (grid[i][j+1] == 0 && j+1 < m) zones(i, j+1);
    if (grid[i][j-1] == 0 && j-1 >= 0) zones(i, j-1);
}
void solve()
{
    int br = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (grid[i][j] == 0)
    {
        br++;
        zones(i, j);
    }
    cout << br << endl;
}
int main()
{
    read();
    solve();
}
