#include <iostream>
using namespace std;

int main () {
    long long a, a1, a2, a3, b, b1, b2, b3, sumG, s1, s2, s3, sumR;
    char znak;
    cin >> a >> znak >> b;

    sumR=a+b;

    a1=a/100;
    a2=a%100/10;
    a3=a%10;
    b1=b/100;
    b2=b%100/10;
    b3=b%10;

    s1=a1+b1;
    s2=(a2+b2)%10;
    s3=(a3+b3)%10;
    sumG=s1*100 + s2*10 + s3*1;

    cout << sumG << endl << sumR << endl;
    return 0;
}

