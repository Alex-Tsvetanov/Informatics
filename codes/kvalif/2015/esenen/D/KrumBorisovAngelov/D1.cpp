#include<iostream>
#include<math.h>
using namespace std;
int main() {
    long long n,a=1,MinimalenPerimetyr=1000000;
    cin>>n;
    while(a<=sqrt(n)) {
        if((n/a)*a==n) {
                if((a+(n/a))*2<MinimalenPerimetyr) {
                    MinimalenPerimetyr=(a+(n/a))*2;
                }
        }
        a++;
    }
    cout<<MinimalenPerimetyr;
    return 0;
}
