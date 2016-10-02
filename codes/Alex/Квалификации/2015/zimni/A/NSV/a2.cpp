#include<iostream>
using namespace std;

int a[100000], b[100000];
bool used[100000];

int main ()
{
    int m, n, num = 0;
    cin >> m >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        ++num;
        for(int j = 0; j < i; ++j)
            if(!used[j] && ((a[i] >= a[j] && a[i] <= b[j]) || (b[i] >= a[j] && b[i] <= b[j])))
            {
                used[j] = true;
                --num;
            }
    }
    cout << num << endl;
    return 0;
}
