#include <iostream>
using namespace std;
int cnt[100000000];
int a[100000000], b[100000000];
int main()
{
    int bnum = 0, roadn = 0;
    cin >> bnum >> roadn;
    if(bnum < 100000000)
    {
        for(int i = 0; i < roadn; i ++)
        {
            cin >> a[i] >> b[i];
            cnt[a[i]] ++;
            cnt[b[i]] ++;
        }
        int k = 0, ans = 0;
        cin >> k;
        int trans[10001];
        for(int i = 0; i < bnum; i ++)
        {
            if(cnt[i]>=k)
            {
                trans[ans] = i;
                ans ++;
            }
        }
        cout << ans << endl;
        for(int i = 0; i < ans; i ++)
        {
            if(i != ans-1) cout << trans[i] << " ";
            else cout << trans[i] << endl;
        }
    }else{
        cout << 0 << endl;
    }
}
