#include <iostream>
using namespace std;
int main()
{
long long int a,b,c,br=0;
cin>>a>>b>>c;
if (a==0) {
    cout<<0<<endl;
    return 0;
}
while (a!=0 && b!=0 && c!=0) {
    if (a!=0) {
        a--;
        br++;
    }
    if (b!=0) {
        b--;
        br++;
    }
    if (c!=0) {
        c--;
        br++;
    }
    if (b!=0) {
        b--;
        br++;
    }
}
cout<<br<<endl;
    return 0;
}
//nadqwam se da e wqrno!? YEEEEES!//
