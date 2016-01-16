#include<iostream>
#include<map>
using namespace std;
int main ()
{
    map<string, int> key;
    string nums[100005];
    int n, m, prev, h;
    bool cont;
    char kk[6];
    for(int a = 0; a < 5; ++a)
    {
        key.clear();
        cin >> n;
        for(int i = 0; i < n; ++ i)
        {
            cin >> nums[i];
            key[nums[i]] = i + 1;
        }
        prev = -1;
        cin >> m;
        cont = false;
        for(int i = 0; i < m; ++ i)
        {
            cin >> nums[i];
            if(!cont && key[nums[i]] != 0)
            {
                h = key[nums[i]] - 1;
                if(h < prev)
                {
                    kk[a] = '0';
                    cont = true;
                }
                prev = h;
            }
        }
        if(!cont)
            kk[a] = '1';
    }
    kk[5] = '\0';
    cout << kk << endl;
    return 0;
}
/*
3 1 2 3
4 1 3 5 6
3 5 1 4
4 150 1 20 5
4 1 5 6 2
3 2 1 6
5 100 20 45 10 3
4 3 100 80 10
5 90 1 4 8 80
5 90 1 8 100 5
*/
