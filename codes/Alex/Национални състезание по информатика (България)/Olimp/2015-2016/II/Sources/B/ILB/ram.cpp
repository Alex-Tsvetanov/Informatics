#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ll long long
#include <cmath>
#include <vector>

struct dup {
    ll x, y;
};

bool operator < (const dup& a, const dup& b) {
    return a.y < b.y;
}

int main(){

    ll k;
    std::cin >> k;

    ll s = std::sqrt(k + 100) + 100;

    std::vector<dup> ans;

    dup d;
    /* total in n x m grid : 2 * m * n + n + m */
    ll br = 0;
    /* case 1 : m <= n
       k = total - 2*m + 1
     */
    for (ll m = 1; m <= s; m++) {
        ll ch = k + m - 1;
        ll zn = 2 * m + 1;

        if (ch % zn == 0) {
            ll n = ch / zn;
            if (m <= n) {
                d.x = m;
                d.y = n;
                ans.push_back(d);
            }
        }
    }

    /* case 2 : m > n
       k = total - 2 * n
    */

    for (ll n = 1; n <= s; n++) {
        ll ch = k + n;
        ll zn = 2 * n + 1;

        if (ch % zn == 0) {
            ll m = ch / zn;
            if (n < m) {
                d.x = m;
                d.y = n;
                ans.push_back(d);
            }
        }
    }
    std::cout << ans.size() << std::endl;
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i].y << " " << ans[i].x << std::endl;
    }
    return 0;
}
