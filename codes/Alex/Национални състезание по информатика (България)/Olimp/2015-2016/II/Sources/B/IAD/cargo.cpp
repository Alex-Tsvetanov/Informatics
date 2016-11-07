#include <iostream>
#include <algorithm>
using namespace std;
int days, reqs, pilots;
struct range
{
    int from, to;
}rngs[1000000];
bool operator<(range a, range b)
{
    if(a.from == b.from) return a.to < b.to;
    return a.from < b.from;
}
bool operator==(range a, range b)
{
    return (a.from == b.from)&&(a.to == b.to);
}
int main()
{
    cin >> days >> reqs >> pilots;
    bool mx = 0, k = 1;
    for(int i = 0; i < reqs; i ++)
    {
        cin >> rngs[i].from >> rngs[i].to;
        if((rngs[i].to-rngs[i].from < 2 && rngs[i].from%8==6)||(rngs[i].to-rngs[i].from == 0 && rngs[i].from%8==7)) mx = 1;
    }
    sort(rngs, rngs+reqs);
    int seq = 1;
    for(int i = 1; i < reqs; i ++)
    {
        if(rngs[i] == rngs[i-1]) seq ++;
        else seq = 0;
        if(2*seq/pilots > rngs[i].to-rngs[i].from+1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    if(mx)
    {
        cout << "MIXED" << endl;
        return 0;
    }
    int last = 0, used = 0;
    for(int i = 0; i < reqs;i ++)
    {
        int j = rngs[i].from;
        while(j%8 == 6 || j%8 == 7 || !((j == last&&used<pilots/2)||(j != last)))
        {
            j ++;
            if(j > rngs[i].to)
            {
                cout << "MIXED" << endl;
                return 0;
            }
        }
        if(last == j) used ++;
        else used = 1;
        last = j;
    }
    cout << "OK" << endl;
}
