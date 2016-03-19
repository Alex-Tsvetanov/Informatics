#include <iostream>
#include <algorithm>
using namespace std;

int main () {

    long long n;
    cin >> n;
    long long A[n], B[n], br=n-1;
    for (long long i=0; i<n; i++) {cin >> A[i];}
    for (long long j=0; j<n; j++) {B[j] = A[j];}
    sort(A, A+n+1);
    for (long long k=0; k<n-1; k++) {
        if (B[k]==A[br]) {cout << A[br] << " "; br--;}
    }
    cout << B[n-1] << endl;
    return 0;
}
