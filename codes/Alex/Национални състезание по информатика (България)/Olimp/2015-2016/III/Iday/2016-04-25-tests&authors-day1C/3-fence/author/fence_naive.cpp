#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int n,k;
long long A[MAX];

bool check(int p) {
    int i = 0;
    int t = 0;
    bool fl = true;
    while (i<n && t<=k) {
        if (A[i] - t > p) t = A[i];
        else t+=p;
        i++;
    }
    return (t<=k);
}

int main () {
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>A[i];

    sort(A, A+n);

    //for(int i=0; i<n; i++) cout<<A[i]<<" ";
    //cout<<endl;

    //while (min*n > k) min--;
    long long p = k / n;
    long long l = 0;
    long long r = p;
    if (p > A[0]) p = A[0];
    while (!check(p)) p--;
    cout<<p<<endl;
 /*
    if (check(p)) {
        cout<<p<<endl;
    } else {
        while (l+1 == r) {
            p = (l+r) / 2;
            if (check(p)) {
                l = p;
            } else {
                r = p;
            }
        }

        if (check(r)) cout<<r<<endl;
        else cout<<r-1<<endl;
    }
*/

    return 0;
}
