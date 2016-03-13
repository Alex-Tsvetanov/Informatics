#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double a, b, t, alpha, lice, maxlice = 0;
    cin >> a >> b;
    if(a<b){
        t = a;
        a = b;
        b = t;
    }
    for(alpha = 0; tan(alpha/2) < b/a; alpha += 0.00001){
        lice = a*b + (a*a + b*b - 2*a*b*sin(alpha))*tan(alpha)/(2+2*cos(alpha));
        if(lice > maxlice){
            maxlice = lice;
        }
    }
    lice = 2*a*b - b*b;
    if(lice > maxlice){
        maxlice = lice;
    }
    cout.precision(3);
    cout << fixed << maxlice << '\n';
    return 0;
}
