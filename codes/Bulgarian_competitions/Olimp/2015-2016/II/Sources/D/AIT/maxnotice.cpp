#include <iostream>
using namespace std;
bool a [100] [100] = {0};
int b [100] [100];
int k [100];
int n, h, l;
int main (){

    ios_base :: sync_with_stdio (false);

    cin >> l >> h;
    cin >> n;
    if (n == 0){
        cout << l * h << endl;
        return 0;
    }
    for (int p = 0; p < n; p ++){
        int x, y, h1, l1;
        cin >> x >> y >> l1 >> h1;
        l1 += x;
        h1 += y;
        for (int i = y; i < h1; i ++)
            for (int j = x; j < l1; j ++)
                a [i] [j] = 1;
    }
    int s = 0;
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < l; j ++){
            int p;
            for (p = i; p < h; p ++){
                if (a [p] [j]){
                    break;
                }
            }
            k [j] = p - i;
        }
        for (int x = 0; x < l; x ++){
            int br = k [x], sum = br;
            for (int y = x + 1; y < l; y ++){
                if (br == 0) break;
                br = min (br, k [y]);
                sum = max (sum, br * (y - x + 1));
            }
            s = max (s, sum);
        }
    }
    cout << s << endl;

    return 0;
}
