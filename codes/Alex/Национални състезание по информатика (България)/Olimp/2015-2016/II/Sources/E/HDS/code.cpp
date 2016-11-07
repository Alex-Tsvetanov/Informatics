#include <iostream>
using namespace std;
int main()
{
char a,p;
long long int br=1,maxr=-1;
cin>>a;
p=a;
while (a!='.') {
    if (a!=p) {
        if (br>1) {
            long long int g=br-3;
            if (maxr<g) maxr=g;
        }
        br=1;
        p=a;
    }
    br++;
    cin>>a;
}
if (a!=p) if (br>1) {
    long long int g=br-3;
    if (maxr<g) maxr=g;
}
if (maxr<=0) {
    cout<<0<<endl;
    return 0;
}
cout<<maxr<<endl;
    return 0;
}
//nadqwam se da e wqrno!? YEEEEES!//
