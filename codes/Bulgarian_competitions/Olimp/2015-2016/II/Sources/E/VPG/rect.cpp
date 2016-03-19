#include <iostream>
using namespace std;
int main ()
{
    long long N, pravougulnici=0, j=5, d, sh;
    cin >> N;
    if ((N-1)%3==0) {pravougulnici++;d=(N-1)/3;sh=1;}
    for (int i=2;i<N;i++,j=j+2) {
        if (i==d and (N-i)/j==sh) break;
        if ((N-i)%j==0) {pravougulnici++;d=(N-i)/j;sh=i;}
    }
    cout << pravougulnici << endl;
    return 0;
}
