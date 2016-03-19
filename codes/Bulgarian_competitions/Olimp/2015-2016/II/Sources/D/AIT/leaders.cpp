#include <iostream>
using namespace std;
int a [1000000], b [1000000];
int main (){

    ios_base :: sync_with_stdio (false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a [i];
    }
    int maxi = a [n - 1], br = 1;
    b [0] = a [n - 1];
    for (int i = n - 2; i >= 0; i --){
        maxi = max (maxi, a [i]);
        if (maxi == a [i]){
            b [br] = a [i];
            br ++;
        }
    }
    cout << b [br - 1];
    for (int i = br - 2; i >= 0; i --){
        cout << ' ' << b [i];
    }
    cout << endl;

    return 0;
}
