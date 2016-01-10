#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==b&&c==d||c==a&&b==d||d==a&&c==b||a==b==c==d) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
     if(a==b&&c==d||c==a&&b==d||d==a&&c==b||a==b==c==d) {
        cout<<a*b<<endl;
     }else{
        cout<<a+b+c+d<<endl;

        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        return 0;}
    }
}
