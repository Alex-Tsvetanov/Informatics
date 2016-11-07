#include<iostream>
#include<string>
#include<queue>

#define MAXN 200004

using namespace std;

int n, a, b, p, q;
bool path[MAXN][MAXN];
int ans = -1, count;
bool visitedb, nowrong;

queue<int> next;
void BFS(int v)
{
    if(v == b) visitedb = true;

    bool add = false;
    for(int i = 1; i <= n; i ++)
    {
        if(path[v][i])
        {
            //cout << v << " " << i << endl;

            if(v == b)
            {
                if(ans == -1) ans = count;
                else if(ans > count) ans = count;
            }
            path[v][i] = 0; next.push(i);
        }
        else if(path[i][v])
        {
            nowrong = false;
            add = true;
            //cout << i << " " << v << endl;
            if(i == b)
            {
                if(ans == -1) ans = (count+1);
                else if(ans > (count+1)) ans = count+1;
            }
            path[i][v] = 0; next.push(i);
        }
    }
    if(add == true) count ++;

    while(next.size())
    {
        int tmp = next.front();
        next.pop();
        BFS(tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    cin >> n >> a >> b;

    bool skipa = true, skipb = true;
    while(cin.good())
    {
        cin >> p >> q;
        path[p][q] = 1;

        if(skipa == true)
            if(p==a || q==a) skipa = false;
        if(skipb == true)
            if(p==b || q==b) skipb = false;
    }

    if(skipa == false && skipb == false)
    {
        visitedb = false; nowrong = true; BFS(a);
        if(visitedb == false) cout << "X\n";
        else if(nowrong == true) cout << "0\n";
        else if(ans == -1) cout << "0\n";
        else cout << ans << '\n';
    }
    else cout << "X\n";

return 0;
}
/*
4 1 4
4 3
3 2
1 2
4 2
*/
/*
4 1 4
4 3
3 2
4 2
*/
//F6+Enter
