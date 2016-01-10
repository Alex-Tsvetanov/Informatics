#include <iostream>
using namespace std;
int main() {

    long long a , b , c , d , e=0 , f=0 ;

    cin>>a>>b>>c>>d;
    if (a==b==c==d) {
        cout<<"YES"<<endl;
        e=a*c;
        cout<<e;
    } else {
        if (a==b and c==d) {

            cout<<"YES"<<endl;
            e=a*c;
            cout<<e;
            f++;
        } else {
            cout<<"NO"<<endl;
            e=a+b+c+d;
            cout<<e;
            f++;
        }



        if (f!=1) {
            if (b==c and d==a) {

                cout<<"YES"<<endl;
                e=a*c;
                cout<<e;
            } else {
                cout<<"NO"<<endl;
                e=a+b+c+d;
                cout<<e;
            }
        }



    }


    return 0;
}


