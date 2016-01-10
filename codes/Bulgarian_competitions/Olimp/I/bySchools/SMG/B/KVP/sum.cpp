#include <iostream>
#include <queue>

using namespace std;

long long n, izh = 1, kolk = 1;
queue <long long> a;

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        if (!(i % 2)) {
            if (!(i % 4)) {
                kolk = a.front();
                a.pop();
            }
            izh += kolk;
            a.push (izh);
        }
    }
    cout << izh << endl;
    return 0;
}
