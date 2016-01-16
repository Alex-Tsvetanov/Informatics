#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    double a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a==b)cout<<fixed<<setprecision(3)<<double(a*a+a*a*(sqrt(2)-1)*(sqrt(2)-1))<<endl;
    else cout<<fixed<<setprecision(3)<<double(a*a+2*a*abs(b-a))<<endl;

    return 0;
}
