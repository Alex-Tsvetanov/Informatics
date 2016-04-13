#include <iostream>
using namespace std;
int main ()
{
    long long A, B, C, candies;
    cin >> A >> B >> C;
    if (A<=B/2 and A<=C) {
        candies=A*4;
    }
    if (B/2<A and B/2<C) {
        candies=B/2*4;
        if (B%2==1) candies=candies+3;
    }
    if (C<=B/2 and C<A) {
        candies=C*4;
    }
    cout << candies << endl;
    return 0;
}

