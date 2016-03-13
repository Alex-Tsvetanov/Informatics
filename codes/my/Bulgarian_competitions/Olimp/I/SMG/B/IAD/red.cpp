#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int maxn = -1, minn = 1000001;
    int num[20001];
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> num[i];
        minn = min(minn, num[i]);
        maxn = max(maxn, num[i]);
    }
    int mlmax = 20001, mlmin = 20001, mrmax = -1, mrmin = -1;
    for(int i = 0; i < n; i ++)
    {
        if(num[i] == minn)
        {
            mlmin = min(i, mlmin);
            mrmin = max(i, mrmin);
        }
        if(num[i] == maxn)
        {
            mlmax = min(i, mlmax);
            mrmax = max(i, mrmax);
        }
    }
    if(mrmax-mlmin < mrmin-mlmax) cout << mlmax+1 << " " << mrmin+1 << endl;
    if(mrmax-mlmin > mrmin-mlmax) cout << mlmin+1 << " " << mrmax+1 << endl;
    if(mrmax-mlmin == mrmin-mlmax)
    {
        if(mlmin < mlmax) cout << mlmin+1 << " " << mrmax+1 << endl;
        else cout << mlmax+1 << " " << mrmin+1 << endl;
    }
}
