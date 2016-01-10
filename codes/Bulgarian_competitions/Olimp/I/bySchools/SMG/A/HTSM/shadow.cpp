#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main(){

    double a,b;
    cin >> a >> b;
    double s = sqrt(a*a + b*b);

    cout << fixed << setprecision(3) << (a*b + (s-a)*a/2.0 + (s-b)*b/2.0) << endl;

    return 0;
}
