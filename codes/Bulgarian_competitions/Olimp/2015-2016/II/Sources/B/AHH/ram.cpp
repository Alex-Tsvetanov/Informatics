#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    vector<int> v;
    int M, N, K, R, fance, broken,br = 0,a,b,c,d;
    cin >> K;
    if(K > 300000000)
        R = 100000000;
    else R = K/3;
    for(int i = 1; i <= R; i++)
    {
        if(i < 35000){
            a = 2*i + 1;
            b = K+i;
            if(b%a == 0 && b/a > i)
            {
                br++;
                v.push_back(i);
                v.push_back(b/a);
            }
        }
        d = K-i - 1;
        c = 2*i - 1;
        if(d%c == 0 && d/c <= i && d!=0)
        {
            br++;
            v.push_back(i);
            v.push_back(d/c);
        }
    }
    cout << br << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); )
    {
        cout << *it << " ";
        it++;
        cout << *it << endl;
        it++;
    }
}
