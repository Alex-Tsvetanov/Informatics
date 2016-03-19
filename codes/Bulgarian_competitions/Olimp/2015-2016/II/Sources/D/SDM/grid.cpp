#include<iostream>

using namespace std;

int n,m;
bool a[205][205];

void DFS(int i, int j)
{
    a[i][j] = true;

    if(i-1>=0 && a[i-1][j]==false) DFS(i-1,j); //up
    if(i+1<n && a[i+1][j]==false) DFS(i+1,j); //down
    if(j-1>=0 && a[i][j-1]==false) DFS(i,j-1); //left
    if(j+1<m && a[i][j+1]==false) DFS(i,j+1); //right
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int output = 0;

    cin >> n >> m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin >> a[i][j];

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(a[i][j]==false) {DFS(i,j);output++;}

    cout << output << '\n';

    return 0;
}
/*
5 3
0 0 0
0 1 0
0 1 0
0 0 1
0 0 0

4 4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

3 4
1 0 1 0
0 0 1 0
1 0 1 0
*/
